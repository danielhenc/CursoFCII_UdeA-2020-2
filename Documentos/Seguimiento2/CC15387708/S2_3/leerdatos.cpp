#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void leerBytes( fstream&, long, int ); // Prototipo función punto 6(a)

string entrada = "pi.txt"; // Archivo de prueba

int main()
{
  fstream entradaDatos( entrada.c_str() );

  if ( entradaDatos.fail() )
    {
      cout << "\nPor favor verificar la ubicación del archivo de caracteres pi.txt" << endl;
      exit(1);
    }
  
  leerBytes( entradaDatos, 2L, 80L );

  return 0;

}

void leerBytes( fstream& procesarDatos, long inicial, int n)
{
  long extremo;
  char caracter;
  fstream entradaDatos( entrada.c_str() );
  entradaDatos.seekg( 0L, ios::end );
  extremo = entradaDatos.tellg();

  cout << "Empezando en la posición # " << inicial << " se despliegan " << endl;
  cout << n << " cifras del número π desde el archivo pi.txt:\n" << endl;
  
  for ( long desplazar = inicial; desplazar <= inicial + n; desplazar++)
    {
      entradaDatos.seekg( desplazar, ios::beg );
      caracter = entradaDatos.get();
      cout << caracter << "";
    }
  
  entradaDatos.close();
  cout << endl;

}
