#ifndef PLANE // include guard
#define PLANE
class Plane
{
private: // not necessary, private is default setting of a class
	int wing; // variable member
	double tail;

public:
	// function members
	int get_wing();
	void set_wing(int wing);

	// For function members, there will be a few special functions
	// constructor and deconstructor
	Plane(); // this function is a constructor of a class Plane
	// A constructor function always has the same name as the class

	Plane(int wing); // another constructor
	Plane( int wing, double tail );

	~Plane(); // this function is a deconstructor
};
#endif