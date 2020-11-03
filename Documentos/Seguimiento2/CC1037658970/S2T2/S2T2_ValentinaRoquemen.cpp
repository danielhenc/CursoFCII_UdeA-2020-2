/**
 * @author Valentina Roquemen Echeverry
 * @brief Se resuelven los ejercicios 5 y 6 de la seccion 7.5 del 
 *        libro Guia (Bronson 2ed).
 */

#include <iostream>
#include<iomanip>
#include <string.h>
#include <vector>
#include "./miBiblioteca.cpp"

using namespace std;
using namespace dataType;

int main()
{
  vector<string> values; // Vector de Strings que va a contener los valores de prueba

  values.push_back("7");
  values.push_back("5.33");
  values.push_back("73.73737373");

  cout<<"------------------------------------------------------\n";
  cout<<"|    Valor    | Parte entera |  Parte fraccionaria   |\n";
  cout<<"------------------------------------------------------\n";

  for (int i = 0; i < values.size(); i++) 
  {
    cout<<"|"<<setw(13)<<values[i]<<"|"; 
    cout<<setw(14)<<entero(values[i])<<"|"; // Se toma la parte entera del numero
    cout<<setw(23)<<partefracc(values[i])<<"|\n"; // Se toma la parte fraccionaria del numero
  }

  cout<<"------------------------------------------------------\n\n\n";

  return 0;
}