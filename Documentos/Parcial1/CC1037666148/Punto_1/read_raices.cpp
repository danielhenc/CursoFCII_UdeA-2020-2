
#include <iostream>
#include "raices.h"


using namespace std;

int main()
{
  double A;
  double B;
  double C;
  cout << "Este programa calcula las raíces de una ecuación tipo: ax**2+bx+c=0"<< endl;
  cout << "ingrese el valor para a: " << endl;
  cin >> A;
  cout << "ingrese el valor para b: " << endl;
  cin >> B;
  cout << "ingrese el valor para c: " << endl;
  cin >> C;

  C_raices creat_raices(A,B,C);
  creat_raices.raices();
  
  
  return 0;
}
