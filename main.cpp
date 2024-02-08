#include <iostream>
#include <array>
#include "Plane.h"
// 2/8
// constructor/deconstructor
// project assignment

int main()
{
  // Plane is a class/struct
  // plane is an object
  {
    Plane plane1;
  }
  Plane plane2( 3 );
  Plane plane3( 4, 5.6 );
  return 0;
}
