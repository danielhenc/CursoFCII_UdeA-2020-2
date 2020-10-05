#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double);//Prototipo de la función a integrar

int main()
{
  //Definición de los límites de integración.
  double a, b;
  cout << "Defina los límites de integración a y b, con a < b." << endl;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  //Definición del orden de la aproximación de la integral
  int orden;
  cout << "Defina el orden de la aproximación de la integral." << endl;
  cout << "Orden = ";
  cin >> orden;

  //T_k es la aproximación de orden k a la integral desde a hasta b de f(x)dx
  double T_k;

  //Definición del T_0
  const double T_0 = 0.5*(f(a) + f(b))*(b - a);

  //Se usará la convención de que T_j = T_(k-1)
  double T_j = T_0;

  //Ancho de los trapecios
  double dx_k;

  //Definición de la precisión con que se muestran los resultados
  int precision;
  cout << "Defina el número de cifras decimales para los resultados." << endl;
  cout << "Precisión = ";
  cin >> precision;

  cout << "T_0 = " << fixed << setprecision(precision) << T_0 << endl;

  double suma_k;
  for (int k = 1; k <= orden; k++)
    {
      //Definición del ancho de los trapecios
      dx_k = (b - a)/pow(2, k);

      //Sumatoria desde i=1 hasta i=2^(k-1) de f(a + (2*i - 1)*dx_k)
      //Que es equivalente a hacer
      //Sumatoria desde i=1 hasta i=2^k - 1 de f(a + i*dx_k) sobre lo i impares
      suma_k = 0;
      for (int i = 1; i <= pow(2, k-1); i++)
	suma_k += f(a + (2*i - 1)*dx_k);

      //Aquí k² = n, y n es el número de particiones del intervalo [a ; b]
      T_k = 0.5*T_j + dx_k*suma_k;
      T_j = T_k;
      
      cout << "T_" << k << " = " << fixed << setprecision(precision)
	   << T_k << endl;
    }
  return 0;
}

double f(double x)
{//Poner aquí la función que se desea integrar
  return exp(-pow(x,2));
}
