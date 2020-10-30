#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void leerBytes(fstream&, long, int);

int main()
{

	string archivo; //Para guardar el archivo
	long off; //Para guardar la posición del caracter inicial
	int N; //Para guardar la cantidad de caracteres que se quieren mostrar
	
	cout << "Introduzca el nombre del archivo que desea abrir: ";
	cin >> archivo;

	fstream archivo_en(archivo.c_str());

	cout << "Ingrese el número de caracteres que desea ver y la posición inicial: ";
	cin >> N >> off;
	
	leerBytes(archivo_en, off, N);
	
	return 0;
}

void leerBytes(fstream& archivo_entr, long offset, int n){

	char ch;
	long pos;
	
	if (archivo_entr.fail()) //Comprueba la apertura con exito
	{
		cout << "El archivo no se abrió con éxito." << endl;
		exit(1);
		}

	for(pos= offset;  pos <= offset + n - 1; pos++) //Para moverse por el archivo desde la posición inicial hasta que se completen n carácteres
	{
		archivo_entr.seekg(pos, ios::beg);
		ch = archivo_entr.get();
		cout << ch << " ";
		}
		
	archivo_entr.close();
	cout << endl;
	}
