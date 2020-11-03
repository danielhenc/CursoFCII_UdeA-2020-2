
#include "namespacewithfunctions.cpp" //Importar la biblioteca que se hizo
#include <math.h>

using namespace Conversion;  //Espacio de nombre creado


int main(){ 
  float numero;
  cout << "Ingrese el valor del número que desea convertir" << endl;
    cin >> numero;
  cout << "La parte entera del número ingresado es: " << entero(numero) << endl ;
  cout << "La parte fraccionaria del número ingresado es: "<<  partefracc(numero) << endl;
}
