#include<thread>
#include<iostream>
#include<vector>
#include <mutex>

static int shared_val = 0;
static std::mutex val_lock;

namespace {

	void func(int num) {
		using namespace std;
		cout << "Current thread id is: " << this_thread::get_id() << endl;
		cout << "Passed argument is " << num << endl;
	}

	void increment_data() {
		using namespace std;
		std::cout << "fetching the lock" << this_thread::get_id() << endl;
		val_lock.lock();
		std::cout << "holding the lock" << this_thread::get_id() << endl;
		// critical section protected by lock and unlock of the mutex
		shared_val = shared_val + 1;
		// thread which holds the lock never unlocks
		val_lock.unlock();
	}
}

int main() {
	using namespace std;
	cout << "Hardware concurrency " << thread::hardware_concurrency() << endl;
	// passing lamdba to thread
	auto dummy_func = []() {
		using namespace std;
		cout << "Current thread ID in dummy func: " << this_thread::get_id() << endl;
		};

	thread myThread(dummy_func);
	myThread.join();

	// passing function pointer to the thread 
	thread anotherThread(&func, 100);
	anotherThread.join();

	// creating thread pool 
	vector<thread> threads;
	for (int index = 0; index < 10; index++)
		threads.emplace_back(thread{ &func, index });

	// wait for the threads to finish
	for (int index = 0; index < 10; index++)
		threads[index].join();
	// no synchronization leads to interleaved cout statement based on the thread execution order.
	// std::thread need to be joined explicitly in the calling thread context

	// C++20 auto joinable threads called jthread 
	std::vector<jthread> jThreads;
	for (int index = 10; index < 20; index++)
		jThreads.emplace_back(jthread{ &func, index });
	// still synchronization required

	// data race example: shared_value is not protected so between the reading the value and incrementing the value by the same thread, 
	// the value can be read by another thread and incremented. 
	// The final value of the shared_value depends on order of execution and data access. 
	std::vector<thread> dataThreads;
	for (int index = 0; index < 10; index++)
		dataThreads.emplace_back(thread{ &increment_data });

	for (int index = 0; index < 10; index++)
		dataThreads[index].join();

	cout << "Data value:" << shared_val << endl;
	// if you create jthreads then even after sychronization, the shared_val might be not be as expected 
	// because when the cout statement is executed, not all threads are guarenteed to be finished 
	// so to ensure that either scope the jthreads or join on the jthreads before the shared_val is accessed. 
	{
		std::vector<jthread> dataThreads;
		for (int index = 0; index < 10; index++)
			dataThreads.emplace_back(jthread{ &increment_data });
	}
	cout << "Current main thread id: " << this_thread::get_id() << endl;
	cout << "Data value:" << shared_val << endl;

	return 0;
}