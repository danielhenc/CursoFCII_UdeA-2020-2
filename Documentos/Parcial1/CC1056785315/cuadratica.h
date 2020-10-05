#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class Cuadratica
{
public :
  Cuadratica(float, float, float);
  vector<float> Raices(); // Calcula las raices
  void Imp_Raices(); // Para imprimir los resultados
  
private :
  float a,b,c,discriminante;
};
