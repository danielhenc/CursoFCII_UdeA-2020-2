#include "part_int_fracc.cpp"
#include <iostream>


using namespace std;
using namespace part_int_fracc;

int main()
{
  double x;
  cout << "Este programa muestra la parte entera y fraccionaria de un número.\n"<< "Ingrese un número:" <<endl;
  cin >> x;
  cout << "La parte entera de " << x << " es: " << entero(x)<< endl;
  cout << "La parte fraccionaria de " << x << " es: " << partefracc(x)<<endl;
  return 0;
}
