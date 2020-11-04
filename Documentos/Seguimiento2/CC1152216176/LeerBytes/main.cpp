#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "leerBytes.cpp"

using namespace leerBytes;

int main()
{
  string nombre_entrada = "it.txt";
	string nombre_salida;
  long desp;
  int numcar;

  ifstream archivo_entrada(nombre_entrada.c_str());

  cout << "Ingrese la posición inicial del estracto que desea obtener del texto\n";
  cin >> desp;
	cout << "Ingrese el numero de caracteres que desea obtener del texto\n";
  cin >> numcar;

  leerBytesa(archivo_entrada, desp, numcar);

	cout << "\n";
	cout << "Ingrese la dirección del área de almacenamiento\n";
	cin >> nombre_salida;

	leerBytesb(archivo_entrada, desp, numcar, nombre_salida);

  return 0;
}
