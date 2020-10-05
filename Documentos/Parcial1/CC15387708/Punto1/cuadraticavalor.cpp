// Código principal de la clase raices

#include "cuadratica.h"

int main()
{
  raices r;

  r.datos();

  cout << endl;
  double d = r.discriminante();
  r.valord(d);
  cout << endl;

  return 0;
}
