#include <iostream>
#include <memory>

// 1/25
// Scope (local, global)
// Memory Storage (stack, heap, static, etc.)
// Memory Address (array, pointers, reference)
// Parameter passing (value, address, reference)

// Any global variables will be stored in a static memory
// These variables will remain in a memory until the program stops running.
int c = 'a'; // this a global variable. It is in a global scope

void pass_by_value_func(int x)
{ // this is a scope of the func function
  std::cout << x << std::endl;
  std::cout << &x << std::endl;
  x = 3;
  std::cout << x << std::endl;
  std::cout << &x << std::endl;
}

void pass_by_pointer( int* x )
{
  std::cout << x << std::endl;
  std::cout << &x << std::endl;
  std::cout << *x << std::endl;
  *x = 3;
  std::cout << x << std::endl;
  std::cout << &x << std::endl;
  std::cout << *x << std::endl;
}

void pass_by_reference( int& x )
{
  std::cout << "In a function" << std::endl;
  std::cout << x << std::endl;
  std::cout << &x << std::endl;
  x = 3;
  std::cout << x << std::endl;
  std::cout << &x << std::endl;
  std::cout << "Going out of a function" << std::endl;
}

int main() 
{ 
  int a = 2;
  std::cout << a << std::endl;
  std::cout << &a << std::endl;
  //pass_by_value_func( a );
  //pass_by_pointer( &a ); // send a memory address
  pass_by_reference( a );
  std::cout << a << std::endl;
  std::cout << &a << std::endl;
  
  
  /*
  
  // this is a scope of the main function

  // Any local variables in a scope will be stored in a stack memory
  // All these local variables will be destroyed at the end of the scope, which means the stack memory will be cleared

  // regular varrialbe
  int x = 1; // the variable name (x) doesn't mean anything to the computer.
  std::cout << "The value of x is " << x << std::endl; // this is the number inside the memory address where x is stored
  std::cout << "The memory address of x is " << &x << std::endl; // where x is stored in RAM.

  // pointer
  int* p; // a pointer is a variable that stores a memory address
  // The pointer itself is also stored somewhere inside a memory
  p = &x; // a point p pointing to an address of an exisiting variable x
  std::cout << "The value of p is " << p << std::endl; // the value of a pointer (memory address of x)
  std::cout << "The memory address of p is " << &p << std::endl; // the memory address of p
  std::cout << "The dereference value of p is " << *p << std::endl; // the value stored at the memory address where p is pointing at

  std::cout << "The memory address of c (a global variable) is " << &c << std::endl;

  int arr[3] = { 1,2,3 }; // also inside a stack memory
  std::cout << "The memory address of arr is " << &arr << std::endl;
  std::cout << "The memory address of arr[0] is " << &arr[0] << std::endl;
  std::cout << "The memory address of arr[1] is " << &arr[1] << std::endl;
  std::cout << "The memory address of arr[2] is " << &arr[2] << std::endl;

  // Heap memory
  // This is where you can ask for as many memory blocks you want from a computer
  // You can use a pointer to point to a block of memory where it hasn' been allocated to any exisitng variable.
  // When working with a heap memory; there's a chance "memory leak".
  // memory leak means that we lose an access to the dynamically allocated memory
  {
    int* ptr = new int; // an int (4 bytes) is dynamically allocated to ptr
    std::cout << "The value of ptr is " << ptr << std::endl;
    std::cout << "The memory address of ptr is " << &ptr << std::endl;
    std::cout << "The dereference value of ptr is " << *ptr << std::endl;
    delete ptr; // 1 way to prevent a memory leak (standard way in C language)
  }
  // whatever block of memory ptr is pointing at, we cannot access it if ptr goes out of the scope.
  // We lose 4 bytes of memory

  // Another way to prevent a memory leak is to use a smart pointer
  std::unique_ptr<int> sp = std::make_unique<int>();
  auto sp2 = std::make_unique<int>();

  // Reference
  // Reference is an alias of a variable (rename a variable)
  double abc = 4.5;
  double& def = abc; // def is a reference of abc

  def = 6.7;
  std::cout << abc << std::endl;
  std::cout << def << std::endl;

  abc = 8.9;
  std::cout << abc << std::endl;
  std::cout << def << std::endl;

  std::cout << &abc << std::endl;
  std::cout << &def << std::endl;
  */

  return 0;
} // this is the end of the scope of the main function