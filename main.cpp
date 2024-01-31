#include <iostream>

// function pointers

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
double derivative_f(double (*f)(double), double x)
{
  // f is a function pointer points to a function that is an input argument to this derivative_f function
  double dx = 0.001;
  return ( f( x + dx ) - f( x - dx ) )/(2 * dx); 
}

int main()
{
  std::cout << derivative_f( x_square, 10 ) << std::endl; // f(x) = x^2, f'(1) = 2*10 = 20
  std::cout << derivative_f( x_cube, 4 ) << std::endl; // f(x) = x^3, f'(4) = 3*4*4 = 48

  std::cout << func_x( 1 ) << std::endl; // function call
  std::cout << &func_x << std::endl; // address of a function
  std::cout << (*&func_x)(1) << std::endl; // dereference an address of a function

  return 0;
}
