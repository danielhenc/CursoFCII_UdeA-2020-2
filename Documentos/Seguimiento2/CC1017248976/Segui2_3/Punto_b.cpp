#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>


using namespace std;

void leerBytes(ifstream&, string&, long, int);
int fsize(ifstream&);

int main()
{
	string fileName;
	long int offset;
	int nchar;	
    string InfoContainer;

	cout << "Ingrese el nombre del archivo" << endl;
	cout  << "luego el caracter en el que desea que se inicie" << endl;
	cout  << "y finalmente la cantidad de caracteres a leer:" << endl;
	cin >> fileName >> offset >> nchar;

	ifstream File_in(fileName);

	if (!File_in){
	  cout << "\nEl archivo no pudo abrirse" << endl;
	  cout <<"Por favor verifique el nombre del archivo" << endl;
		exit(1);
	}

	leerBytes(File_in, InfoContainer, offset, nchar);
    cout<< InfoContainer<<endl;

	return 0;
}

void leerBytes(ifstream& File,string& info , long offset, int nchar){
	char c;
	int fileSize = fsize(File); 
	int m = fileSize - offset; 

	if (offset > fileSize){
		cout << "Los parámetros de entrada son inválidos " << endl;
		exit(2); 
	}

	else if ( nchar > m ){
		cout << "desde " << offset << " solo hay " << m << " caracteres" << endl;
		nchar = m;
	}

	File.seekg(offset, ios::beg);
	
	for (int i = 0; i < nchar; i++) info += File.get();
}

int fsize(ifstream& File){
	int size = 0;

	File.seekg(0, ios::end); 
	size = File.tellg(); 

	return size;
}
