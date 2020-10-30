#include "namespace.cpp"

using namespace partenumero;

int main()
{
  double c;

  cout << "Escriba un número para separar en parte entera y decimal:" << endl;
  cin >> c;

  cout << "\nLa parte entera es: " << entero( c ) << endl;
  cout << "la parte decimal es: " << partefracc( c ) << endl;

  return 0;
}
