#include "Polymorphism.h"

void Dog::func()
{
	//this->a = 1; // error, 
	// a is private
	this->b = 3;
	this->c = 4;
}

void Cat::func()
{
	this->b = 5;
	this->c = 6;
}

void Animal::speak()
{
	std::cout << "???" << std::endl;
}

void Dog::speak()
{
	std::cout << "Woof" << std::endl;
}

void Cat::speak()
{
	std::cout << "Meow" << std::endl;
}

void Derived::func2()
{
	std::cout << "Implemented" << std::endl;
}