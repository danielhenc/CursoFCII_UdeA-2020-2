/*
Solución al ejercicio 6 de la sección 8.4 del Branson 2ed

Este programa lee n caracteres de un archivo y los almacena en una cadena

*/

#include <iostream>
#include <fstream> //flujo de archivo
#include <cstdlib> // necesario para exit()
#include <string>

using namespace std;

void leerBytes( ifstream&, long, int ); //prototipo a
void leerBytes2( ifstream&, long, int, char [] ); //prototipo b

//main
int main()
{
	string nombre_archivo; 
	ifstream archivo_entr; 
	int N;
	long depl;
	char user;

	cout << "Ingrese el nombre del archivo a leer" << endl;
	getline(cin, nombre_archivo);

	archivo_entr.open(nombre_archivo.c_str()); // abre el archivo

	if (archivo_entr.fail()) // comprueba una apertura con exito
	{
		cout << "\nEl archivo " << nombre_archivo << " no se abrió con éxito"
		<< "\nPor favor compruebe que el archivo existe en realidad." << endl;
		exit(1);
	}
	cout << "\nEl archivo se ha abierto con éxito para lectura.\n";

	cout << "Ingrese número de caracteres a leer" << endl;
	cin >> N;

	cout << "Ingrese el desplazamiento del primer argumento a leer " << endl;
	cin >> depl;

	char entradas[ N-1 ]; //define arreglo para almacenar 

	cout << "¿desea almacenar lo que quiere leer? (y/n)" << endl;
	cin >> user;

	if ( user == 'y' )
	{
		leerBytes2(archivo_entr, depl, N, entradas);
	}

	else if ( user == 'n' )
	{
		leerBytes(archivo_entr, depl, N);
	}

	return 0;
}

//implementacion de las funciones

void leerBytes( ifstream& archivo, long char1, int nChar )
{
	char cVar; int cont; 

	archivo.ignore( char1 ); //ignora los caracteres 

	//lee los caracteres 
	archivo >> cVar;
	cont = 0;

	while ( !archivo.eof() && cont<nChar )
	{
		cout << "se leyó: " << cVar << endl; //muestra lo leido
		archivo >> cVar;
		cont += 1;
	}

}

void leerBytes2( ifstream& archivo , long char1, int nChar, char entries[] )
{
	char cVar; int cont;

	archivo.ignore( char1 ); //ignora los caracteres

	archivo >> cVar;
	cont = 0;
	while ( !archivo.eof() && cont<nChar )
	{
		*(entries + cont) = cVar; //almacena lo leido
		archivo >> cVar;
		cont += 1;
	}

	cout << "almacenados: " << entries << endl; //muestra lo leido y almacenado

}


