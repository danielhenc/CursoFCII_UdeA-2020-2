#include "cuadratica.h"

int main()
{
  float a1,a2,a3;
  cout << "Ingrese los coeficientes reales a, b y c de la ecuacion ax² + bx + c cuyas raices necesita:" << endl;
  cout << "a = ";
  cin >> a1;
  cout << "b = ";
  cin >> a2;
  cout << "c = ";
  cin >> a3;
  Cuadratica raices1(a1,a2,a3);
  raices1.Imp_Raices(); // Se imprimen en pantalla las raices
  return 0;
}
