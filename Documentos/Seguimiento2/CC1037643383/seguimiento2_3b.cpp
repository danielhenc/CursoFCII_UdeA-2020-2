#include <iostream>
#include <fstream> //flujo de archivo
#include <cstdlib> // necesario para exit()
#include <string>

using namespace std;

void leerBytes(fstream&, long, int, char []);

int main()
{
	string nombre_archivo = "prueba.txt"; 
	fstream archivo_ent; 
	int n;
	long caracter_inicial;

	cout << "Ingrese el nombre del archivo a leer" << endl;
	getline(cin, nombre_archivo);

	archivo_ent.open(nombre_archivo.c_str()); // abre el archivo

	if (archivo_ent.fail())
	{
		cout << "\nEl archivo no pudo ser abierto, por favor compruebe si el nombre del archivo es correcto." << endl;
		exit(1);
	}

	cout << "Ingrese el valor de la posición inicial del argumento a leer " << endl;
	cin >> caracter_inicial;

	cout << "Ingrese el número de caracteres que desea leer" << endl;
	cin >> n;

	char entradas[n-1]; //Se define un arreglo en el cual se van a almacenar los caracteres 

	leerBytes(archivo_ent, caracter_inicial, n, entradas);
  

	return 0;
}

void leerBytes(fstream& archivo, long caracter1, int caracter_n, char entradas[]) //Se define la función con un 4to argumento
{                                                                                  //Donde el 4to ejercicio es el arreglo de caracteres almacenados
	char car; int m;

	archivo.ignore(caracter1); 

	archivo >> car;
	m = 0;
	while (!archivo.eof() && m<caracter_n)
	{
		*(entradas + m) = car; 
		archivo >> car;
		m += 1;
	}

	cout << "Caracteres almacenados: " << entradas << endl; //muestra los caracteres almacenados 

}
