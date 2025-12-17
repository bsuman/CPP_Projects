#include<thread>
#include<iostream>
#include<mutex>

static int shared_val = 0, shared_val2 = 10;
static std::mutex val_lock, val2_lock;

namespace {

	void increment_data() {
		using namespace std;
		std::cout << "fetching the lock" << this_thread::get_id() << endl;
		val_lock.lock();
		std::cout << "holding the lock" << this_thread::get_id() << endl;
		// critical section protected by lock and unlock of the mutex
		shared_val = shared_val + 1;
		// thread which holds the lock never unlocks
		// val_lock.unlock();
	}

	void decrement_data() {
		using namespace std;
		std::cout << "fetching the lock" << this_thread::get_id() << endl;
		val2_lock.lock();
		std::cout << "holding the lock" << this_thread::get_id() << endl;
		// critical section protected by lock and unlock of the mutex
		shared_val2 = shared_val2 - 1;
		// thread getting the lock never unlocks
		//val2_lock.unlock();
	}

	// example of deadlock 
	void func1() {
		using namespace std;
		increment_data();
		std::cout << "incremented data first" << this_thread::get_id() << endl;
		decrement_data();
		std::cout << "decremented data second" << this_thread::get_id() << endl;
	}

	// example of deadlock 
	void func2() {
		using namespace std;
		decrement_data();
		std::cout << "decremented data first" << this_thread::get_id() << endl;
		increment_data();
		std::cout << "incremented data second" << this_thread::get_id() << endl;
	}
}


int main() {
	using namespace std;
	// example of deadlock
	std::thread t1_func1(&func1), t2_func2(&func2);
	t1_func1.join();
	t2_func2.join();
	return 0;
}