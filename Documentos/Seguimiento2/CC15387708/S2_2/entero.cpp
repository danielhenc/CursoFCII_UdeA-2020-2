#include <iostream>
#include <cmath>

using namespace std;

// 5. a.
int entero( int a )
{
  return a;
}

// 5. b.
int main()
{
  int a;

  cout << "Escriba un número para visulizar su parte entera: " << endl;
  cin >> a;

  cout << "\nLa parte entera del número es: " << entero( a ) << endl;

  return 0;
}
