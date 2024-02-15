#include <iostream>
#include <array>
#include <vector>
#include <map>
#include "Plane.h"

// 2/15
// static and global
// const
// template function
// template class

// const in front of a function means that the function is returning a constant variable
const double func( const float a ) // a is read-only
{
	return a;
}

const double& func2()
{
	double b = 2;
	std::cout << b << "," << & b << std::endl;
	return b;
}

template <typename asdf, typename qwer>
void myFunction( asdf input, asdf input2, int input3, qwer input4)
{
	input4++;
	std::cout << input << std::endl; // need to print an input here regardless of the datatype of this input variable
}

template <typename T> // template class
class MyClass { // MyClass is the name of the class
private:
	T x; // x is a private variable member with a datatype T
public: // public function members
	MyClass( T xx )
		:x{ xx }
	{
	}

	T getvalue()
	{
		return x;
	}
};


int main()
{
	// template class
	MyClass<int> obj(5);
	std::cout << obj.getvalue() << std::endl;
	MyClass<char> obj( 'c');
	std::cout << obj.getvalue() << std::endl;

	// template
	// template allows you to use a datatype as an input to a function or a class
	// All containers utilize template
	std::array<int, 3> a = { 1,2,3 };
	std::array<float, 3> b = { 1,2,3 };
	std::vector<char> c = { 'a','b' };
	std::map<int, std::array<char,8>> d;

	myFunction<char,double>( 'a', 'b',6, 2.3);
	myFunction<int,char>( 6,5,7, '5' );
	myFunction<float, std::array<int, 3>>( 5.34,0.1,8, a );

	// const - variable/function/input&output arguments
	// const makes variable/function read-only

	//const int x = 1; // const is typically used as a warning (so that you get a compilation error)
	//x = x + 1;
	//std::cout << x << std::endl;

	//const int* p = &x; // const pointer pointing to constant variable
	//double y = func(10);
	//y++;

	//const double& z = func2();
	//std::cout << z << "," << & z << std::endl;

	return 0;
}

