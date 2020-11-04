//Seguimiento 3. Resuelva el ejercicio 6 de la seccion 8.4 del libro Guia (Bronson 2ed).
/*a. Escriba una función llamada leerBytes() que lea y despliegue n caracteres
empezando desde cualquier posición en un archivo. La función deberá aceptar
tres argumentos: un nombre de objeto de archivo, el desplazamiento del primer
carácter que se va a leer y el número de caracteres que se leerán. (Nota: El pro-
totipo para leerBytes() deberá ser void leerBytes(fstream&, long,
int).)*/


#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip>


using namespace std;

void leerBytes(ifstream&, long, int);

void leerBytes(ifstream& archivo , long n, int N){
	char cadena[N+1];
	archivo.seekg(0);
	archivo.ignore(n);
	archivo.getline(cadena, N+1);
	cout<<cadena<<endl;
						}


int main()
{

string nombre_archivo = "ArchivoSeguimiento3.txt";

ifstream archivo_in;
archivo_in.open(nombre_archivo.c_str());

if (archivo_in.fail()){
	cout << nombre_archivo << " No pudo abrirse, revise si existe."<<endl;
	exit(1);
			}

archivo_in.seekg (0, archivo_in.end);
int cantidad = archivo_in.tellg();
archivo_in.seekg (0, archivo_in.beg);

long n;
int N;

cout << "Caracteres en el texto: " << cantidad-1 <<endl;
cout << "Ingrese el caracter en el que quiere iniciar: ";
cin >> n; 
cout << "Ingrese cuántos cararcteres quiere ver: ";
cin >> N;
cout<<endl;

leerBytes(archivo_in, n, N);

 return 0; 
}
