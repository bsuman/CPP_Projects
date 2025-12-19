// Sychronization primitives 
// thread - spinlock 
// waiting on a condition why holding a thread 
// instead using condition variable for to communicate change of state 
// used mostly in producer/consumer problems 
// t1 consuming what t2 produces 

#include<condition_variable>
#include<mutex>
#include<iostream>
#include<thread>
#include<chrono>
#include<future>

static int shared_val = 0;
bool work_done = false;
std::condition_variable cv; 
std::mutex m;

void consumer() {
	std::unique_lock<std::mutex> lock{ m }; 
	auto start = std::chrono::high_resolution_clock::now();
	cv.wait(lock, []() {
		return work_done == true and shared_val > 0;
		});
	shared_val = shared_val-1; 
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "consumer: Time:" << std::chrono::duration(end - start) << std::endl;
}

void producer() {
	auto start = std::chrono::high_resolution_clock::now();
	std::lock_guard<std::mutex> lock{ m }; 
	std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });
	shared_val = shared_val + 1;
	work_done = true;
	cv.notify_one();
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "producer: Time:" << std::chrono::duration(end - start) << std::endl;
}

// async library
// a asynchronous operation that returns a std::future using which caller can fetch the result of the operation 
//  

int square() {
	return shared_val* shared_val;
}

int main() {
	std::thread producer_thread{&producer }, consumer_thread{&consumer};
	consumer_thread.join();
	producer_thread.join();
	std::cout << "shared value " << shared_val << std::endl;
	shared_val = 10;
	// implement a deadlock using std::future
	// wrong!! --> std::future<int> f1 = std::async(std::launch::deferred, &square);
	// because when the policy is deferred, the async task gets executed when either wait is called on it or get is called. 
	// in the loop before, the get is only called when the task is ready with the result 
	// so both the main thread and async thread end up waiting for each other 
	// right --> use async launch policy 
	std::future<int> f1 = std::async(std::launch::async, &square);
	std::future_status sts;
	while (true)
	{
		sts = f1.wait_for(std::chrono::milliseconds(1));
		if (sts == std::future_status::ready)
		{
			std::cout << "computed result:" << f1.get() << std::endl;
			break;
		}
	}
	return 0;
}