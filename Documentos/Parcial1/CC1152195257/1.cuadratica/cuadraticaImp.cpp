#include <iostream>
#include <iomanip>
#include <cmath>
#include "cuadratica.h"

using namespace std;

Cuadratica::Cuadratica(double aa, double ab, double ac)
{
  a = aa;
  b = ab;
  c = ac;
  
  discriminante = pow(b, 2.) - 4*a*c;
  
  if (discriminante >= 0)
    {//Cuando las raíces son reales
      raiz[0][0] = (-b + sqrt(discriminante))/2.;//Re(raiz0)
      raiz[0][1] = 0;                            //Im(raiz0)
      raiz[1][0] = (-b - sqrt(discriminante))/2.;//Re(raiz1)
      raiz[1][1] = 0;                            //Im(raiz1)
    }
  else
    {//Cuando las raíces son complejas
      raiz[0][0] = -b/2.;                        //Re(raiz0)
      raiz[0][1] = sqrt(-discriminante)/2.;      //Im(raiz0)
      raiz[1][0] = -b/2.;                        //Re(raiz1)
      raiz[1][1] = -sqrt(-discriminante)/2.;     //Im(raiz1)
    }
}

void Cuadratica::imprimirEcuacion()
{
  cout << "(" << a << ")x² + (" << b << ")x + (" << c << ") = 0" << endl;
}

double Cuadratica::obtenerDiscriminante()
{
  return discriminante;
}

void Cuadratica::obtenerRaiz(double aRaiz[2][2])
{
  for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
	aRaiz[i][j] = raiz[i][j];
    }
}

void Cuadratica::imprimirRaices()
{
  int n = 2;//Número de cifras decimales
  if (discriminante < 0)
    {//Cuando las raíces son complejas
      cout << '\n';
      cout << "x0 = " << fixed << setprecision(n) << raiz[0][0] << " + "
	   << fixed << setprecision(n) << raiz[0][1] << "i" << endl;
      cout << "x1 = " << fixed << setprecision(n) << raiz[1][0] << " + "
	   << fixed << setprecision(n) << raiz[1][1] << "i" << endl;
      cout << '\n';
    }
  else if (discriminante >= 0)
    {//Cuando las raíces son reales
      cout << '\n';
      cout << "x0 = " << fixed << setprecision(n) << raiz[0][0] << endl;
      cout << "x1 = " << fixed << setprecision(n) << raiz[1][0] << endl;
      cout << '\n';
    }
}
