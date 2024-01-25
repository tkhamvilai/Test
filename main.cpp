#include <iostream>
#define ABC 1
#define DEF



int main() {
  float i = ABC;
#if WIN32
  // this part of code will be compiled only if you're using Windows
  double x = 2;
#else
  // this part of code will be compiled only if you're not using Windows
  double x = 3;
#endif
  double a = 1.1;


#if ABC
  double x;
#endif
  int y = 4;


#if ABC
  double x;
#endif
  return 0;
}