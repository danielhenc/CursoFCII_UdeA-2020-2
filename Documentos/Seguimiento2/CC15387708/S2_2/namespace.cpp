#include <iostream>
#include <cmath>

using namespace std;

namespace partenumero
{
  int entero( double a )
  {
    return a;
  }

  double partefracc( double b )
  {
    return abs(b - entero(b));
  }
}
