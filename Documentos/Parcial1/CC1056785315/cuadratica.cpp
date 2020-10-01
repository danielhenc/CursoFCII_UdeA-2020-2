#include "cuadratica.h"

Cuadratica::Cuadratica(float c1, float c2, float c3)
{
  a = c1;
  b = c2; // Inicializacion de los coeficientes de la ecuacion
  c = c3;
  discriminante = pow(b,2) - 4*a*c; // Para determinar si las raices son reales
                                    // o complejas
}

vector<float> Cuadratica::Raices()
{
  vector <float> x(2,0); // Para guardar y devolver las 2 raices en un vector
  if (discriminante > 0)
    {
      x[0] = (-b + sqrt(discriminante))/(2*a); // Caso raices reales diferentes
      x[1] = (-b - sqrt(discriminante))/(2*a);
    }

  else if (discriminante == 0)
    {
      x[0] = -b/(2*a); // Caso raices reales iguales
      x[1] = x[0];
    }

  else if (discriminante < 0)
    {
      x[0] = -b/(2*a); // Caso raices complejas. Como una es el conjugado de la
                       // otra, se guardan las partes real e imaginaria por
                       // separado para no lidiar con numeros complejos
      x[1] = sqrt(-discriminante)/(2*a);
    }
  return x;
}

void Cuadratica::Imp_Raices()
{
  vector<float> solucion = Raices();
  cout << "\nLas raices de la ecuacion " << a << "x² + " << b << "x + " << c << " son: ";

  // Se imprimen los resultados segun el caso
  if (discriminante > 0)
    { 
      cout << fixed << setprecision(2) << solucion[0] << " y " << solucion[1] << endl;
    }

  else if (discriminante == 0)
    {
      cout << fixed << setprecision(2) << solucion[0] << " con multiplicidad 2" << endl;
    }

  else if (discriminante < 0)
    {
      cout << fixed << setprecision(2) << "(" << solucion[0] << " + " << solucion[1] << "i) y " << "(" << solucion[0] << " - " << solucion[1] << "i)" << endl;
    }
  
}
