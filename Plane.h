#ifndef PLANE // include guard
#define PLANE
class Plane
{
private: // not necessary, private is default setting of a class
	int wing;

public:
	int get_wing();
	void set_wing(int wing);
};
#endif