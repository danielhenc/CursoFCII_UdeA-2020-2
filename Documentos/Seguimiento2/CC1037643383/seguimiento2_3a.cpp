#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leerBytes(fstream&, long, int);

int main()
{
  string nombre_archivo="prueba.txt";
  long caracter_inicial; // Posición inicial del caracter
  int n; // Cantidad de caracteres que se imprimirán
  
  fstream archivo_ent(nombre_archivo.c_str(), ios::in);
  
  cout << "Ingrese el nombre del archivo que desea que el programa lea " << endl;
  getline(cin, nombre_archivo);
  
  if (archivo_ent.fail())
    {
      cout << "\nEl archivo no pudo abrirse, ¿Seguro que es ese el nombre?" << endl;
      exit(1);
    }
  
  cout << "Ingrese el valor de la posición inicial del argumento a leer " << endl;
  cin >> caracter_inicial;

  cout << "Ingrese el número de caracteres que desea leer" << endl;
  cin >> n;
  
  leerBytes(archivo_ent, caracter_inicial, n); // Lee e imprime los caracteres solicitados a partir de la posición inicial, siempre que sea un valor válido
  
  cout << endl;
  return 0;
}


void leerBytes(fstream& archivo, long caracter_inicial, int n_caracter)
{
  archivo.seekg(0L, ios::end); 
  long ultimo = archivo.tellg(); 

 
  if ((caracter_inicial + n_caracter) > ultimo) // Se verifica que la cantidad de caracteres solicitada sean compatibles con la cantidad de caracteres del archivo
    {
      cout << "Las posiciones que usted ingresó se salen de la cantidad de caracteres del archivo." << endl;
    }

  else
    {
      char caracter;
      cout << "Los primeros " << n_caracter << " caracteres consecutivos desde el caracter " << caracter_inicial << " del archivo son:\n" << endl;
  
      for (int i=0; i<n_caracter; i++)
	{
	  archivo.seekg(caracter_inicial + i, ios::beg); // Se lee cada caracter
	  caracter = archivo.get();
	  cout << caracter << "  "; // Se imprimen los caracteres leídos
	}
    }  
}
