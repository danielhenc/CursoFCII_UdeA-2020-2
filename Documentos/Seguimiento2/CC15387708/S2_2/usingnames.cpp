#include "names.cpp"

using namespace ent;

int main()
{
  double b;

  cout << "Escriba un número para visulizar su parte entera: " << endl;
  cin >> b;

  cout << "\nLa parte entera del número es: " << entero( b ) << endl;

  return 0;
}
