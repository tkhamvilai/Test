#include <iostream>
#include <array> // fixed size
#include <vector> // dynamic sized array
#include <algorithm>
#include <map> // another type of container

// 2/1
// review function pointer: use when you want to have a function that takes another function as an input
// lambda function: use when you want to create a function inside another function
// containers

double func_x( double x ) {
  return x;
}

double x_square( double x ) {
  return x * x;
}

double x_cube( double x ) {
  return x * x * x;
}

// We can use a function pointer when we want to have a function to be an input to another function
double derivative_f( double ( *f )( double ), double x )
{
  // f is a function pointer points to a function that is an input argument to this derivative_f function
  double dx = 0.001;
  return ( f( x + dx ) - f( x - dx ) ) / ( 2 * dx ); // numerical derivative
}

int main()
{
#if 0
  // lambda function
  // is a function inside another function
  []() {}; // An empty lambda function
  // () for input arguments
  // {} for a function implementation
  // [] for capturing variables in a larger scope of a function that the lambda function lives in

  int x = 2, y = 3;
  //[] () {x + y;}; // this lambda function doesn't know/see x, y variables
  [x, y] () { x + y; }; // performs a summation but returns nothing
  [x, y] () -> int{ return x + y; }; // returns a summation
  auto val = [=] (int a)->int {
    return (x + y)*a;
  };

  int z = 3;

  std::cout << val(10) << std::endl;

  std::array<int, 3> arr;
  int x0 = 0;
  std::generate( arr.begin(), arr.end(), [x0] () mutable -> int {return x0++; } );
  for ( auto ar : arr )
    std::cout << ar << std::endl;
#endif

  // both array and vector are containers
  std::array<int, 5> arrr = { 1,2,3,4,5 };
  std::vector<int> v = { 1,2,3 };
  v.push_back( 10 );
  v.push_back( 20 );
  for ( auto i : v )
    std::cout << i << std::endl;

   // For array or vector, index (key) is a number and the value is based the datatype
  std::cout << arrr[0] << std::endl;
  std::cout << v[1] << std::endl;

  // For map, you can use any datatype as a key
  std::map<char, double> m1; // char is a key, double is a value
  m1['a'] = 1.2;
  m1.insert( { 'b', 4.5 } );
  std::cout << m1['a'] << std::endl;
  std::cout << m1['b'] << std::endl;

  // you can mix between multiple containers
  std::array<std::map<std::vector<char>, double>,5> amv;
  std::vector<char> v1 = { 'a','b' };
  std::map<std::vector<char>, double> mm = { {v1,5.6} };
    amv[4] = { { {'c','d'}, 1.2} };
    amv[3] = mm;
    std::cout << amv[3][{'a', 'b'}] << std::endl;
    std::cout << amv[3][{'c', 'd'}] << std::endl;
    std::cout << amv[4][{'c', 'd'}] << std::endl;



  // function pointers
  /*std::cout << derivative_f(x_square, 10) << std::endl; // f(x) = x^2, f'(10) = 2*10 = 20
  std::cout << derivative_f( x_cube, 4 ) << std::endl; // f(x) = x^3, f'(4) = 3*4*4 = 48

  std::cout << func_x( 1 ) << std::endl; // function call
  std::cout << &func_x << std::endl; // address of a function
  std::cout << ( *&func_x )( 1 ) << std::endl; // dereference an address of a function*/

  return 0;
}
