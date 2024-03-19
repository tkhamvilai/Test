// From Example 21
#include <iostream>
#include <thread>
//#include <mutex> // we will implement this ourselves
#include <string>
#include <Windows.h> // for Sleep(0);

/*
struct hemiphore {
  int value = 0;

  // Block until the hemiphore has `this->value >= bound`, then ATOMICALLY
  // increment its value by `delta`.
  void H( int bound, int delta ) {
    // This is pseudocode; a real hemiphore implementation would block, not spin, and would
    // ensure that the test and the increment happen in one atomic step. To do this, we will need an atomic library
    // You may assume that `this->value` never overflows.
    while ( this->value < bound ) { 
      // what should happen is that the first thread should not get into this while loop
      // bound should be less than 0 or equal to 0 (initial value of the value variable) initially 

      //sched_yield(); // this function is only available in Linux
      // For Windows, we have to use Sleep() function
      Sleep( 0 ); // for Windows
    }
    this->value += delta; // the first thread will go to this line after skipping the while loop
    // the first thread (once it gets to line 25), it should make the condition ( this->value < bound ) to be true
    // in order to make all the other threads wait. For that to happen the value of the valeu variable, should be less than bound
    // We can pick any pair of numbers for bound and delta (input arguments to this H function so that
    // the conditions are satisfied.

    // Initially this->value = 0
    // bound = 0, which makes ( this->value < bound ) == false
    // delta = -1, which makes this->value = 0 + -1 = -1
    // meaning that for all other threads
    // ( this->value < bound ) == true
  }
};
*/

class hemiphore {
private:
  std::atomic<int> value;

public:
  hemiphore( int initialValue ) : value( initialValue ) {}

  void H( int bound, int delta ) {
    while ( true ) {
      // Spin until the value is at least `bound`
      int current = value.load( std::memory_order_relaxed );
      while ( current < bound ) {
        //sched_yield(); // Yield to other threads
        Sleep( 0 );
        current = value.load( std::memory_order_relaxed );
      }

      // Attempt to atomically adjust the value
      if ( value.compare_exchange_weak( current, current + delta,
                                        std::memory_order_release,
                                        std::memory_order_relaxed ) ) {
        break; // Success, exit loop
      }
      // If compare_exchange_weak fails, it means another thread has modified 'value'
      // The loop will continue, and 'current' will be updated with the new value of 'value'
    }
  }
};

struct mutex {
  hemiphore h;
  // YOUR CODE HERE (if necessary)

  // Initialize the mutex.
  mutex() : h( 0 ) {
    // YOUR CODE HERE (if necessary)
    // this is not necessary
  }

  // Lock the mutex.
  void lock() {
    // YOUR CODE HERE
    this->h.H( 0, -1 );
  }

  // Unlock the mutex, which must be locked.
  void unlock() {
    // YOUR CODE HERE
    this->h.H( -1, 1 );
  }
};

void print( std::string s, mutex* m ) {
  while ( 1 ) {
    m->lock();
    std::cout << s << std::endl;
    m->unlock();
  }
}

int main() {
  mutex m;
  std::thread t1( print, "Hello", &m );
  std::thread t2( print, "World", &m );
  t1.join();
  t2.join();
  return 0;
}
