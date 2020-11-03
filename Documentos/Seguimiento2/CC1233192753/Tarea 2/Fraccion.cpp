#include "Entero.cpp"

using namespace Entero;
namespace Fraccion
{
  double partefrac(double numero)
  {
    double fnumero;
    int inumero = entero(numero);
    fnumero = numero - inumero;
    return fnumero;
  }
}
