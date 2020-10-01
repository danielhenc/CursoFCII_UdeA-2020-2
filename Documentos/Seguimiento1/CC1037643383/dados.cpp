#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  int dimArreglo = 13; // ignora el elemento cero
  int frecuencia[ dimArreglo ] = {};
  int cara1;
  int cara2;
  
  srand( time( NULL ) );
  
  for ( int tiro = 1; tiro <= 36000; tiro++ )
    {

    cara1 = 1 + rand() % 6;
    cara2 = 1 + rand() % 6;
    frecuencia[ cara1 + cara2 ]++; 
  }
  
  cout << "Cara" << setw( 13 ) << "Frecuencia" << endl;
  // imprime el valor de cada elemento del arreglo
  for ( int cara = 1; cara < dimArreglo; cara++ ){
    cout << setw( 4 ) << cara << setw( 13 ) << frecuencia[ cara ]<< endl;
  }
  
return 0; 
}
