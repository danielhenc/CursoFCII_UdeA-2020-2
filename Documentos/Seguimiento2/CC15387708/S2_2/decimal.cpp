#include <iostream>
#include <cmath>

using namespace std;

// 6. a.
double partefracc( double a )
{
  double b;
  double part = modf( a, &b );
  return abs(part);
}

// 6. b.
int main()
{
  double a;

  cout << "Escriba un número para visualizar su parte decimal: " << endl;
  cin >> a;

  cout << "\nLa parte decimal del número es: " << partefracc( a ) << endl;

  return 0;
}
