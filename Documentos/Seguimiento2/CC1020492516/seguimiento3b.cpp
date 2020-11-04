//seguimiento3.b
/*
b. Modifique la función leerBytes() escrita en el ejercicio 6a para almacenar
los caracteres leídos en una cadena o arreglo. La función deberá aceptar la di-
rección del área de almacenamiento como un cuarto argumento.*/

#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip>


using namespace std;

void leerBytes(ifstream&, long, int, char *cadena);

void leerBytes(ifstream& archivo , long n, int N, char *cadena){
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

char cad[N+1];
char *cadPtr = cad;
leerBytes(archivo_in, n, N, cadPtr);

 return 0; 
}
