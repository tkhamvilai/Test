#include "Plane.h"
#include <iostream>

// const keyword at the end of the class's
// function member prohibits any changes
// of variable members of the class
int Plane::get_wing() const
{
	//this->wing = 10;
	return this->wing;
}

void Plane::set_wing( int wing ) const
{
	// If Plane::set_wing is const
	wing = 10; // this is fine, wing is not
	// a class's variable member

	//this->wing = wing; // this has an error
	// this->wing is a class's variable member
}

Plane::Plane()
{
	// constructor function implementation
	// whenever an object is instantiate from a class
	// the constructor function of the class will be
	// called autonmatically
	std::cout << "Plane Created" << std::endl;
}

Plane::Plane( int wing )
{
	std::cout << "Plane Created with wing" << std::endl;
	this->wing = wing;
}

Plane::Plane( int wing, double tail ) : tail(tail)
{
	std::cout << "Plane Created with wing and tail" << std::endl;
	this->wing = wing + 1;
}

Plane::~Plane()
{
	// deconstructor function implementation
	std::cout << "Plane Destroyed" << std::endl;
}

// static keyword for a function makes
// the funtion available only in the file
// that the function is implemented.
// static function is used when you want
// your function to be accessed only 
// within a file.
static void print_something()
{
	std::cout << "print" << std::endl;
}

void another_print()
{
	print_something();
}