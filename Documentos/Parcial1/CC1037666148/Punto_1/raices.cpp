#include <iostream>
#include <cmath>
#include <iomanip>
#include "raices.h"

using namespace std;

C_raices :: C_raices(double A,double B,double C) //Constructor.
{
  a = A;
  b = B;
  c = C;
  bool imaginario = false; //Variable que definirá si la raíz es imaginario o no.
}

//función para encontrar el determinante
double C_raices :: det()
{
  double deter;
  double l;
  
  l = pow(b,2)-4*a*c;
  if (l<0)
    {
      deter = sqrt(-l);
      imaginario = true;
    }
  else
    {
      imaginario = false;
      deter = sqrt(l);
    }
  return deter;
}


// Calculan cada uno de los términos de las raices
double C_raices ::  term1()
{
  return -b/(2*a);
}

double C_raices :: term2(double determ)
{
  return determ/(2*a);
}

//Función que imprime las raices
void C_raices :: raices()
{
  double raiz1;
  double raiz2;
  double Determ = det();
  if (imaginario)
    {
      cout << "Raíz 1 = " << setprecision(3) << term1() << " + i" << setprecision(3) << term2(Determ) << endl;
      cout << "Raíz 1 = " << setprecision(3) << term1() << " - i" << setprecision(3) << term2(Determ) << endl;
    }
  else
    {
      raiz1 = term1() + term2(Determ);
      raiz2 = term1() - term2(Determ);
      cout << "Raíz 1 = " << setprecision(3) << raiz1 << endl;
      cout << "Raíz 2 = " << setprecision(3) << raiz2 << endl;
    }
  
}






