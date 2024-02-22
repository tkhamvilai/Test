#include <iostream>
#include "Plane.h"
#include "Polymorphism.h"
#include <array>

// 2/22
// Polymorphism
// Virtual functions (virtual, override, final)
// Virtual Deconstructor
// Pure Virtual function & Abstract class

int main()
{
	Animal animal1;
	//animal1.a; // error
	animal1.b = 2;
	//animal1.c = 3; // error

	Dog dog1;
	Cat cat1;
	dog1.func();
	cat1.func();
	std::cout << dog1.b << std::endl;
	std::cout << cat1.b << std::endl;

	Animal animal2 = dog1;
	//animal2.d = 10; // error
	std::cout << animal2.b << std::endl;

	std::cout << &animal2 << "," << &dog1 << std::endl;

	Animal* animal3 = &dog1; // pointer
	Animal& animal4 = cat1; // reference
	// animal3 and animal4 represent the
	// base class portion of dog1 and cat1

	// I cannot tell all these three objects
	// to call the same function even if they
	// are all animal.
	//animal1.speak();
	//dog1.speak();
	//cat1.speak();

	std::array<Animal*,3> farm = { &animal1, &dog1, &cat1 };
	for ( auto a : farm )
	{
		a->speak(); // only "???" is printed out
	}

	//Base b; // error, Base is an abstract class
	Derived d;
	return 0;
}

