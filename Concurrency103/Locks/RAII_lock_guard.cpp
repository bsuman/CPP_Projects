
#include<thread>
#include<iostream>
#include<mutex>

static int shared_val = 0;
static std::mutex val_lock;

namespace {
	// it is safeer to use primitives instead of directly locking the mutex wrapping the mutex using the primitive, 
	// and unlocking automatically using RAII when the destructor of the primitive is called( with exception safety)
	// example lock_gaurd 
	void increment_data() {
		using namespace std;
		// acquires / locks the mutex when created 
		lock_guard<mutex> val_guard(val_lock);
		std::cout << "Thread acquired the lock and  incrementing shared_value " << std::this_thread::get_id() << std::endl;
		shared_val = shared_val + 1;
		// on leaving scope, val_guard destructor unlocks the mutex automatically. 
		// !!! to ensure that the lock_guard is scoped properly to avoid unnecessary locking of mutex
		std::cout << "Thread leaving scope " << std::this_thread::get_id() << std::endl;
	}
}

int main() {
	std::jthread t1(&increment_data), t2(&increment_data);
	t1.join();
	t2.join();
	std::cout << "all threads finished, and shared_value is: " << shared_val << std::endl;
	return 0;
}