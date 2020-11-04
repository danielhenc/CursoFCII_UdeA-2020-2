/*
  Al ejecutar el programa se crea un archivo de salida con el nombre y texto que el usuario digite,
  luego se ingresa el desplazamiento (desde donde comenzara a imprimir la funcion)
  y luego el numero de caracteres (cantidad de caracteres que imprimira la funcion).
  Se cierra el archivo y se abre como archivo de entrada, la funcion leerBytes lo analiza, e imprime lo digitado por el usuario.
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// prototipo funciones
void leerBytes(ifstream&,long int, int ); 
void OpenWritte(ofstream&, ifstream&);

int main(){
  ofstream archivo_sal;
  ifstream archivo_ent;
  long int desp;
  int num;
  
  OpenWritte(archivo_sal, archivo_ent);  // crea un archivo de salida para que el usuario ingrese el nombre y el texto(contenido) y luego abre un archivo de entrada que se va a pasar a la otra funcion
  cout << " " << endl;                  

  cout << "Ingrese el desplazamiento desde donde se empezara a imprimir (empieza desde 0)" << endl;
  cin >> desp;
  cout << " " << endl;

  cout << "Ingrese la cantidad de caracteres que se va a imprimir" << endl;
  cin >> num;
  cout << " " << endl;

  cout << "El texto desde la posicion " << desp << " y una cantidad de caracteres de " << num << " es: "<<endl;   
  leerBytes(archivo_ent,desp,num); // llama la funcion

  return 0;
}


// funcion donde se crea el archivo de salida, se le da un nombre y contenido, y luego abre el mismo archivo como archivo de entrada
void OpenWritte(ofstream& salArchivo, ifstream& entArchivo){
  
  string nombre;
  
  cout << "\nIntroduzca un nombre de archivo: " << endl;  
  getline(cin,nombre);
  
  salArchivo.open(nombre.c_str());  // se abre el archivo con el nombre digitado por el usuario
  
  if (salArchivo.fail()){  // comprueba una apertura exitosa
  
    cout << "No se pudo abrir el archivo" << endl;
    exit(1);
  }

  string texto;
  
  cout << "\nIngrese el texto del archivo (presione enter para terminar)" << endl;
  getline(cin,texto);
  salArchivo << texto << endl;

  salArchivo.close();  // se cierra el archivo

  entArchivo.open(nombre.c_str());  //se abre el archivo como archivo de entrada

  if (entArchivo.fail()){  // comprueba una apertura exitosa
    cout << "No se pudo abrir el archivo"<< endl;
    exit(1);
  }
  
  }
  
// funcion que recibe el archivo de entrada, desplazamiento, numero de caracteres.
void leerBytes(ifstream& entArchivo, long int desplazamiento, int numCaracteres){
  entArchivo.seekg(desplazamiento,ios::beg); //se mueve a la posicion inicial del archivo
  long int offset;
  char ch;

  cout << "" << endl;

  // se obtiene letra por letra desde lo que se haya ingresado como desplazamiento
  // y la cantidad de caracteres ingresada
  for(offset = desplazamiento; offset < desplazamiento + numCaracteres; offset++){
    entArchivo.seekg(offset,ios::beg);   // se mueve a la posicion (desplazamiento) ingresada
    ch = entArchivo.get();    // se guarda cada caracter
    cout << ch;  // se imprime cada caracter
  }
  cout << "" << endl;
  cout << "" << endl;

  entArchivo.close();  // se cierra el archivo
   
}
