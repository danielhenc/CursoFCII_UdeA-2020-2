#include <iostream>

#include <fstream>

#include <cstdlib>

#include <string>

using namespace std;

void leerBytes(fstream & , long, int); // prototipo

int main() {
  string nombreArchivoIn = "input.dat";
  fstream archivoIn(nombreArchivoIn.c_str(), ios:: in );
  
  long despl;
  int n;

  cout << "Ingrese el desplazamiento" << endl;
  cin >> despl;

  cout << "Ingrese el numero de caracteres a leer" << endl;
  cin >> n;
  
  leerBytes(archivoIn, despl, n);

  return 0;
}

void leerBytes(fstream & archivoIn, long despl, int n) {
  if (archivoIn.fail()) {
    cout << "No se puede abrir el archivo" << endl;
    exit(1);
  }
  string chars = "";
  archivoIn.seekg(despl);
  int i = 0;
  while (archivoIn.good() && i < n) {
    chars += archivoIn.get();
    i += 1;
  }
  cout << chars << endl;
  archivoIn.close();

}
