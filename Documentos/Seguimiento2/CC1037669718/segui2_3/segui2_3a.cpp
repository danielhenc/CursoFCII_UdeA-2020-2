#include "leerBytes_a.h"

int main(){
  string filename = "./texto.txt";
  long pos;
  long size;
  ifstream file(filename);

  if( file.fail() ){
    cout << "No se pudo abrir el archivo\n";
    return 0;
  }

  cout << "Ingrese la posición inicial y el número de caracteres que desea extraer separados por un espacio\n";
  cin >> pos >> size ;
  
  leerBytes(file , pos , size );

  cout << endl;

  return 0;
}
