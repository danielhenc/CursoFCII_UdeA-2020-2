/**
 * @author Valentina Roquemen Echeverry
 * @brief Se resuelve  ejercicio 6 de la seccion 8.4 del 
 *        libro Guia (Bronson 2ed).
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  string nombre_archivo = "texto.txt"; // Nombre del archivo
  void leerBytesA(ifstream&,long, int); // Prototipo de la funcion del numeral A
  void leerBytesB(ifstream&,long, int, char * ); // Prototipo de la funcion del numeral B

  // Se revisa si el archivo existe 
  /*-------------------------------*/
  ifstream archivo_entr(nombre_archivo.c_str());
  
  if(archivo_entr.fail())
  {
    cout << "El archivo no existe"<< endl;
    exit(1);
  }
  /*-------------------------------*/
  
  long inicial = 6L; // Posicion inicial
  int steps = 11; // Numero de caracteres que se leeran
  char cadena[20];

  cout << "------------Numeral A -------------" << endl;
  leerBytesA(archivo_entr, inicial, steps);

  cout << "------------Numeral B -------------" << endl;
  leerBytesB(archivo_entr, inicial, steps, cadena);
  cout << cadena << endl; // Se imprime la cadena con el texto

  // Se cierra el objeto de archivo
  archivo_entr.close();
  
  
  return 0;
}

void leerBytesA(ifstream& archivo_entr, long offset, int nsteps)
{
  char ch;
  for (int i = offset; i < offset+nsteps; ++i)
  {
    archivo_entr.seekg(i, ios::beg); // Se ubica en la posicion i desde el principio
    ch = archivo_entr.get(); // Toma el caracter de dicha posicion
    cout << ch << endl; // Imprime el caracter
  }
}


void leerBytesB(ifstream& archivo_entr, long offset, int nsteps, char * cadena1)
{
  for (int i = offset; i < offset+nsteps; ++i)
  {
    archivo_entr.seekg(i, ios::beg); // Se ubica en la posicion i desde el principio
    cadena1[i-offset] = archivo_entr.get(); // Almacena por referencia el caracter
  }
}