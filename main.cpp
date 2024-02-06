#include <iostream>
#include <array>

// 2/6
// week 3 hw solution
// struct
// sizeof struct / struct padding
// members
// class, 
// encapsulation / get&set
// overloading
// include guard, 
// 
// For next class
// constructor/deconstructor
// static keyword

struct Person { // Person is a struct.
  // For a struct, by default, every member is public.
  // each of the following variables is called 'variable member'
//private:
  char initial; // 1 byte
  char lastname_initial; // 1 bytes
  int home_address; // 4 bytes
  int height; // 4 bytes
  int weight; // 4 bytes
  double age; // 8 bytes

  // In Cpp, we can also have a function member (not possible in C language)
  void greeting()
  {
    std::cout << "hi" << std::endl;
  }
}; // there is no global variable initialized with this struct

class Person2 { // Person2 is a class.
  // For a class, by default, every member is private.
  // each of the following variables is called 'variable member'
  char initial; // 1 byte
  char lastname_initial; // 1 bytes
  int home_address; // 4 bytes
  int height; // 4 bytes
  int weight; // 4 bytes

public:
  double age; // 8 bytes

  // In Cpp, we can also have a function member (not possible in C language)
  void greeting()
  {
    std::cout << "hi" << std::endl;
    this->initial = 'a'; // this is inside a class
    home_address = 123;
  }

  // this greeting function is not the same as the above greeting function
  // because of the input arguments
  void greeting( std::string word ) 
  {
    std::cout << word << std::endl;
  }

  // having multiple function with the same name but different input arguments is a function overloading
  // This is can be used outside a struct/class
  void greeting( int x )
  {

  }
};

void func() {

}

void func( int x ) {

}

int main()
{
  Person me; // me is an object instantiated from a struct. (datatype & variable)
  me.initial = 'T';
  std::cout << sizeof( me ) << "," << sizeof( Person ) << std::endl;
  me.greeting();

  Person2 you;
  //you.initial = 'T'; // error: this is outside a class
  you.age = -1;
  you.greeting();
  return 0;
}
