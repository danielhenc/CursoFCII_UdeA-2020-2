
#include "Entero.cpp"

using namespace Entero;

double partefrac(double numero)
{
  double fnumero;
  int inumero = entero(numero);
  fnumero = numero - inumero;
  return fnumero;
}
