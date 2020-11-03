#include <iostream>

#include <fstream>

#include <cstdlib>

#include <string>

using namespace std;

void leerBytes(fstream & , long, int, fstream & ); // prototipo

int main() {
  string nombreArchivoIn = "input.dat";
  string nombreArchivoOut = "output.dat";
  long despl;
  int n;

  cout << "Ingrese el desplazamiento" << endl;
  cin >> despl;

  cout << "Ingrese el numero de caracteres a leer" << endl;
  cin >> n;

  fstream archivoIn(nombreArchivoIn.c_str(), ios:: in );
  fstream archivoOut(nombreArchivoOut.c_str(), ios::out);

  leerBytes(archivoIn, despl, n, archivoOut);

  return 0;
}

void leerBytes(fstream & archivoIn, long despl, int n, fstream & archivoOut) {
  if (archivoIn.fail()) {
    cout << "No se puede abrir el archivo de entrada" << endl;
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

  if (archivoOut.fail()) {
    cout << "No se puede abrir el archivo de salida" << endl;
    exit(1);
  }

  archivoOut << chars;
  archivoOut.close();
  cout << "Se ha actualizado el archivo output.dat" << endl;

}
