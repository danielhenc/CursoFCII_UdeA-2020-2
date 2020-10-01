#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  //a
  float sigma, mu, x;
  mu = 90;
  sigma = 4;
  x = 80;
  float f = (1/(sigma*sqrt(2*M_PI)))*exp(-0.5*pow((x-mu)/sigma,2));
  cout << "f = " << f << " para los valores propuestos en el ejercicio los cuales corresponden a: x = 80, mu = 90 y sigma = 4" << endl;

  //b
  cout << "Escriba valores de x, mu y sigma para calcular el valor de f" << endl;
  cout << "mu = ";
  cin >> mu;
  cout << "sigma = ";
  cin >> sigma;
  cout << "x = ";
  cin >> x;
  f = (1/(sigma*sqrt(2*M_PI)))*exp(-0.5*pow((x-mu)/sigma,2));
  cout << "f = " << f << " con sus datos" << endl;
}
