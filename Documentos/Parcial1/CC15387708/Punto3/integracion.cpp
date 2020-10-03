// Programa que evalúa una integral usando la regla trapezoidal

#include <iostream>
#include <cmath>

using namespace std;

double function(double x)
{
  // Aquí se define la función que se desea integrar
  
  double f = log( 1 + x*x );
  return f;
  
}

// En la función main de C++ se aplica la regla trapezoidal:
// ejecuta el programa para evalúar la integral

int main()
{
  // Definición de las variables y límites
  // n -> divisiones del intervalo, i -> orden del cálculo
  
  int i, n;
  double a, b, delta, suma = 0, est;

  // Datos que debe ingresar el usuario

  cout << "\nPara calcular la integral definida de f(x) = ln(1 + x²)" << endl;
  cout << "dividiendo la curva en N trapecios, escriba estos valores: \n";
  cout << "\nLímite inferior, a = "; cin >> a;
  cout << "Límite superior, b = "; cin >> b;
  cout << "Total de divisiones, N = "; cin >> n;

  delta = ( b - a)/n;
  double x[ n + 1 ], y[ n + 1 ];

  // Primer bucle for: evalúa cada punto x_i hasta x_n, para obtener cada
  // f(x_n) y todos los valores se almacenan en sus respectivos arreglos

  for ( i = 0; i <= n; i++ )
    {
      x[i] = a + i*delta;
      y[i] = function(x[i]);
    }

  // Segundo bucle for: suma repetidamente todos los elementos delta*[f(a + i*delta)]

  for ( i = 1; i < n; i++)
    {
      suma = suma + delta*y[i];
    }

  // Finalmente se calcula el estimado completo

  est = (delta/2)*( y[0] + y[n] ) + suma;

  // y se muestra el resultado en la pantalla

  cout << "\nEl resultado obtenido es: " << est << endl;

  return 0;

}
  
/*
- La regla trapezoidal aproxima el área bajo una curva, mediante el 
área bajo líneas rectas trazadas sobre la curva original. Estas líneas
rectas forman polígonos en forma de trapezoides.

- El procedimiento para usar la regla es calcular un término base
(área de un solo trapecio), dividir el intervalo n veces (en varios 
trapecios) y luego obtener la suma de todos los términos siguientes
aplicando repetidamente una formula recursiva y usando el término base.

REFERENCIAS:
[1] https://www.bragitoff.com/
[2] G.J. Bronson., C++ for Engineers and Scienists: Trapezoidal Rule
*/
  
  
  
