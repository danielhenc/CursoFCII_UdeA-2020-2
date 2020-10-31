#include <iostream>
#include <iomanip>
#include <cmath>


namespace part_int_fracc 
{
  
  int entero(int x)
  {
    return x;
  }
  double partefracc(double x)
  { 
    double z = x - entero(x);
    return z;
  }

}
