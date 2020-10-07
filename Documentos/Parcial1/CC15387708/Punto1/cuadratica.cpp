// Implementación de la clase raices

#include "cuadratica.h"

void raices::datos()
{
  cout << "\nResuelve las raices r1 y r2 de una ecuación cuadrática" << endl;
  cout << "digitando el valor de los coeficientes: " << endl;
  cout << "\na = "; cin >> a;
  cout << "b = "; cin >> b;
  cout << "c = "; cin >> c;
}

double raices::discriminante()
{
  double d = b * b;
  d -= (4 * a * c);
  return d;
}

void raices::valord(double d)
{
  if (d == 0)
    {
      cout << "\nLas raíces son reales e iguales:" << endl;
      x1 = (-1 * b)/(2 * a);
      x2 = x1;
      cout << "r1 = " << fixed << setprecision(2) << x1
	   << ", y r2 = " << fixed << setprecision(2) << x2 << endl;
    }
  else if (d > 0)
    {
      cout << "Las raíces son reales y diferentes:" << endl;
      x1 = ((-1 * b) + sqrt(d))/(2 * a);
      x2 = ((-1 * b) - sqrt(d))/(2 * a);
      cout << "r1 = " << fixed << setprecision(2) << x1
	   << ", y r2 = " << fixed << setprecision(2) << x2 << endl;
    }
  else
    {
      cout << "Las raíces son imaginarias:" << endl;
      x1 = (-1 * b)/(2 * a);
      x2 = (sqrt(-d))/(2 * a);
      cout << "r1 = " << fixed << setprecision(2) << x1 << " + i" << fixed << setprecision(2) << x2 ;
      cout << ", y r2 = " << fixed << setprecision(2) << x1 << " - i" << fixed << setprecision(2) << x2 << endl;
    }
}
