// Johan Alexis Carrillo Toro - 1214734681

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


//Prototypes
void ReadBytes( ifstream&, long, long, string );  // reads the file and save in a string

//main function
int main(){

	string file_name, chain;  // input file name
	long first_char, n_read;  // position of the first char and the number of char  to read

	cout << "Escriba el nombre del archivo a leer: " << endl;
	getline(cin, file_name);  // writes the file name

	ifstream inFile(file_name.c_str());  // open the file

	// check if the file was succesfully opened
	if (inFile.fail()){
		cout << "Error al leer el archivo" << endl;
		exit(1);
	}

	cout << "Diga cuantos caracteres se van a leer: " << endl;
	cin >> n_read;
	cout << "Diga la posicion del primer caracter que se va a leer: " << endl;
	cin >> first_char;

	ReadBytes(inFile, first_char, n_read, chain);

	inFile.close();  // close the file

	return 0;
}

// Definition of the functions
void ReadBytes(ifstream& inFile, long first_char, long n_read, string chain){
	// this function read a file and writes n character from its content
	// in a string type named chain

	char ch;

	for (long i=first_char; i<=first_char+n_read; i++){  // from first_chain reads and put in a string n_read chars
		inFile.seekg(i, ios::beg);  // goes to the i-th position
		ch = inFile.get();  // put the i-th char in ch
		chain += ch;  // saves the char in the string chain
	}
	cout << "La cadena almacenada es: \n";
	cout << chain << endl;
}