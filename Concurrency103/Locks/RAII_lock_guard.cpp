
#include<thread>
#include<iostream>
#include<mutex>
#include<condition_variable>
#include<shared_mutex>
#include<syncstream>

static int shared_val = 0, shared_val2 = 100;
static std::mutex val_lock, val2_lock;

namespace {
	// it is safer to use primitives instead of directly locking the mutex wrapping the mutex using the primitive, 
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

	void decrement_data_1() {
		{
			std::scoped_lock scope_lock{ val_lock /*val2_lock*/ };
			shared_val = shared_val + 1;
		}
	}

	//vs
	void decrement_data_2() {
		{
			std::lock_guard<std::mutex> val_guard(val_lock);
			shared_val = shared_val + 1;
		}
	}

	// when to use lock_guard vs scoped_lock vs unqiue_lock vs shared_lock 
	// lock_guard and scoped_lock behave the same way between decrement_data_1 and decrement_data_2 function 
	// They acquire the lock on the mutex and release it when the scope ends and their destructors are called 
	// When to use lock_guard vs when to use scoped_lock? 
	// use lock_guard for single mutex locking and unlocking the mutex after the scope ends is what you need 
	// use scoped_lock for multiple mutex locking in a deadlock-safe way and when unlocking at the end of the scope is what you need. 
	//  
	// when to use unqiue_lock?
	// with lock_guard and scoped_lock the locks on the given mutex/ mutices is/are acquired immediately and there is no early unlock 
	// with unique_lock it is possible to lock after creation ( or deferred locking based on condition) and release the lock before scope ends. 
	// it also allows locking conditionaly 
	// condition_variable need to wait on shared_state change( example shared_val2 changed) 

	static std::condition_variable cv;
	void decrement_data() {
		std::unique_lock<std::mutex> lock(val2_lock); // mutex is locked here
		cv.wait(lock, []() {
			return shared_val2 > 0;
			}); // unlocks the mutex until the condition becomes true and relocks the mutex
		shared_val2 = shared_val2 - 1;
		lock.unlock();
	}

	void increment_data_notify() {
		{
			std::lock_guard<std::mutex> lock(val2_lock); // wait for the mutex to be available 
			shared_val2 = shared_val2 + 1; // increments the value
		}
		cv.notify_one(); // notifies a single thread waiting on the conditional variable 
		// notify_all() notifies all threads waiting on the conditional variable 
		// only one of the woken thread can proceed and acquire the mutex 
		// so depending on the context using notify_one could be more scalable 
	}

	// when to use shared_lock 
	// works only with shared_mutex  or shared_timed_mutex
	// mutliple threads can acquire read lock simulatenously
	// shared resource is write lock is acquired by only one thread at a time 
	// write lock .. locks all readers and writers out 
	// read lock .. locks all writers out 

	static int shared_value = 10;
	static std::shared_mutex sm;
	void read() {
		std::osyncstream sync_out{ std::cout }; // outputs to thread lock buffer
		std::shared_lock<std::shared_mutex> sl{ sm };
		// writes to osyncstream which is thread-safe
		sync_out << "read access to thread " << std::this_thread::get_id() << " read value of shared_value " << shared_value << std::endl;
	}

	void write() {
		std::unique_lock<std::shared_mutex> ul(sm);
		shared_value = shared_value + 10;
		std::osyncstream sync_out{ std::cout };
		sync_out << "write access to thread " << std::this_thread::get_id() << std::endl;
	}
}

int main() {
	std::jthread t1(read), t2(read), t3(write), t4(read);
	return 0;
}