 /*
  Al ejecutar el programa se crea un archivo de salida con el nombre y texto que el usuario digite,
  luego se ingresa el desplazamiento (desde donde comenzara a imprimir la funcion)
  y luego el numero de caracteres (cantidad de caracteres que imprimira la funcion).
  Se cierra el archivo y se abre como archivo de entrada, la funcion leerBytes lo analiza,
  e imprime lo digitado por el usuario.
  En este caso se le da como argumento extra una direccion de memoria a la funcion leerBytes donde se guardara
  lo que debe imprimir.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

//Prototipo de funciones
void leerBytes(ifstream&,long int, int , char & );
void OpenWritte(ofstream&, ifstream&);

int main(){
  ofstream archivo_sal; //archivo salida
  ifstream archivo_ent;  //archivo entrada
  long int desp;
  int num;
  char dir;
  
  OpenWritte(archivo_sal, archivo_ent);    // crea un archivo de salida para que el usuario ingrese el nombre y el texto(contenido) y luego abre un archivo de entrada que se va a pasar a la otra funcion
  
  //se ingresa el desplazamiento y el numero de caracteres a imprimir
  cout<<"Ingrese el desplazamiento desde donde se empezara a imprimir (empieza desde 0)"<<endl;
  cin>>desp;
  cout<<"Ingrese la cantidad de caracteres que se va a imprimir"<<endl;
  cin>>num;
  cout<<"El texto desde la posicion "<< desp << " y una cantidad de caracteres de " << num << " es: "<<endl;
  leerBytes(archivo_ent,desp,num,dir);
  
  return 0;
}

// funcion donde se crea el archivo de salida, se le da un nombre y contenido, y luego abre el mismo archivo como archivo de entrada
void OpenWritte(ofstream& salArchivo, ifstream& entArchivo){
  
  string nombre;
  
  cout << "\nIntroduzca un nombre de archivo: " << endl;
  getline(cin,nombre);
  
  salArchivo.open(nombre.c_str());  // se abre el archivo con el nombre digitado por el usuario
  
  if (salArchivo.fail()){  // comprueba una apertura exitosa
    
    cout << "No se pudo abrir el archivo"<< endl;
    exit(1);
  }
  
  string texto;
  
  cout << "Ingrese el texto del archivo (presione enter para terminar)" << endl;
  getline(cin,texto);
  salArchivo << texto << endl;
  
  salArchivo.close();  // se cierra el archivo
  
  entArchivo.open(nombre.c_str());  //se abre el archivo como archivo de entrada
  
  if (entArchivo.fail()){   // comprueba una apertura exitosa
    
    cout << "No se pudo abrir el archivo"<< endl;
    exit(1);
  }
  
}

// funcion que recibe el archivo de entrada, desplazamiento, numero de caracteres, y direccion de memoria
void leerBytes(ifstream& entArchivo, long int desplazamiento, int numCaracteres, char &dir ){
  entArchivo.seekg(desplazamiento,ios::beg); //se mueve a la posicion inicial del archivo
  long int offset;
  char *ptrdir;  //puntero a la direccion de dir
  ptrdir = &dir;
  int i=0;
  
  // se obtiene letra por letra desde lo que se haya ingresado como desplazamiento
  // y la cantidad de caracteres ingresada
  for(offset = desplazamiento; offset < desplazamiento + numCaracteres; offset++){
    entArchivo.seekg(offset,ios::beg);   // se mueve a la posicion (desplazamiento) ingresada
    ptrdir[i] = entArchivo.get();  // se guarda cada caracter
    cout << ptrdir[i];    // se imprime cada caracter
    i = i+1;
  }
  cout<< " " << endl;
  cout<< " " << endl;
  entArchivo.close(); //se cierra el archivo
  
  // se imprime en notacion de apuntadores cada caracter ingresado
  // con el apuntador "apuntando" a la direccion de memoria deseada (la de dir)
  cout << "El valor del arreglo donde se almacenaron los caracteres es: " << endl;
  for(int j = 0; j < numCaracteres; j++){
    cout << *(ptrdir+j);
  }
  cout<< " " << endl;
  cout<< " " << endl;
  //cout << strlen(ptrdir) << endl;
}
