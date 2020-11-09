#include "Biblioteca.cpp" //Importar la biblioteca que se hizo
#include <math.h>

using namespace EntFrac;  //Espacio de nombre


int main(){  //Se pide el valor y se hace uso de las funciones guardadas en el espacio de nombre
  float valor;
  cout << "Ingrese el valor del número" << endl;
   cin >> valor;
  cout << "La parte entera del número es: " << entero(valor) << endl ;
  cout << "La parte fraccionaria del número es: "<<  partefracc(valor) << endl;
}
 



