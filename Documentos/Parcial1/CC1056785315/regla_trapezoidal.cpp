#include <iostream>
#include <cmath>

using namespace std;

double f_integrando(double);

int main()
{
  float a, b, paso;
  int N;
  double integral = 0;
  
  cout << "Ingrese el limite inferior de la integral: "; 
  cin >> a;
  
  cout << "\nAhora el limite superior: "; 
  cin >> b;
  
  cout << "\nIngrese el numero de trapezoides que quiere que el metodo utilice: ";
  cin >> N;
  
  paso = (b - a)/N; // Ancho de cada trapezoide

  for (int i = 1; i < N; i++)
    {
      // Sumatoria de la formula general
      integral += f_integrando(a + i*paso);
    }

  // Lo restante en la formula para calcular la integral
  integral = (2*integral + f_integrando(a) + f_integrando(b))*paso/2;

  cout << "\nLa integral entre " << a << " y " << b << " de la funcion establecida es: " << fixed << integral << endl;

  return 0;
}

double f_integrando(double x) // Funcion a integrar
{
  return exp(sin(pow(x,2)));
}
