#include <iostream>
#include <cmath>
#include "cuadratica.h"

using namespace std;

int main()
{
  double a, b, c;
  
  cout << "\nIngrese los coeficientes de la ecuación cuadrática ax² + bx + c = 0"
       << '\n' << endl;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;
  
  Cuadratica ecuacion(a, b, c);
  cout << "\nLa ecuación queda así: "; ecuacion.imprimirEcuacion();

  if (ecuacion.obtenerDiscriminante() < 0)
    cout << "\nLa ecuación tiene raíces complejas conjugadas." << endl;
  else if (ecuacion.obtenerDiscriminante() == 0)
    {
      cout
	<< "\nLa ecuación tiene raíces reales iguales: es un cuadrado perfecto."
	<< endl;
    }
  else if (ecuacion.obtenerDiscriminante() > 0)
    cout << "\nLa ecuación tiene raices reales diferentes." << endl;

  cout << "\nRaíces:" << endl;
  ecuacion.imprimirRaices();
  
  return 0;
}
