#include "partes.cpp"
#include<iostream>

using namespace partes;
using namespace std;

int main(){
  double x;

  cout << "La parte entera de -5.72 es: " << entero(-5.72) << "\n";
  cout << "La parte fraccionaria de -5.72 es: " << partefracc(-5.72) << "\n";
  cout << "La suma de ambas partes es: " << entero(-5.72) + partefracc(-5.72) << "\n\n";

  cout << "La parte entera de 256.879 es: " << entero(256.879) << "\n";
  cout << "La parte fraccionaria de 256.879 es: " << partefracc(256.879) << "\n";
  cout << "La suma de ambas partes es: " << entero(256.879) + partefracc(256.879) << "\n\n";

  cout << "Ingrese un número real cualquiera\n";
  cin >> x;

  cout << "La parte entera de este número es: " << entero(x) << "\n";
  cout << "La parte fraccionaria de este número es: " << partefracc(x) << "\n";
  cout << "La suma de ambas partes es: " << entero(x) + partefracc(x) << "\n";

  return 0;
}
