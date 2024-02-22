#ifndef POLYMORPHISM
#define POLYMORPHISM

#include <iostream>

// Animal is a base class
class Animal
{
	int a; // a is private
public:
	int b; // b is public
	// Animal::speak() is a
	// virtual function
	virtual void speak();
	// if the original object
	// is instianted from a base
	// class, it will use this
	// function; otherwise, 
	// if the original object
	// instianted from a derived
	// class, the program will use
	// the function in te derived
	// class

// only derived classes
// can access protected members
protected: 
	int c;
};

// Dog is a derived class
// from the Animal class
class Dog : public Animal
{
public:
	int d;
	void func();
	// override keyword (optional)
	// explicitly
	// tells the compiler that this
	// function is overrriding another
	// function in the base class
	void speak() override;
};

// Cat is another derived class
class Cat : public Animal
{
public:
	int e;
	void func();
	void speak() override;
};

// Abstract Class & Pure Virtual Function
// A class that has a pure virtual function
// is called an abstract class
class Base {
public:
	// {} means that this function has
	// an empty implementation 
	virtual void func1() {};

	// = 0 means that this function doesn't
	// have an implementation, a.k.a.,
	// a pure virtual function
	// the implementation of a pure virtual
	// function needs to be implemented in
	// a derived class.
	// No object can be instantiated from
	// a class with a ure virtual function
	// aka Abstract class
	// An abstract class is used when you
	// want to force someone to create an
	// implementation of this function in
	// the derived class
	virtual void func2() = 0;
};

class Derived : public Base
{
	void func2();
};

#endif