#include <iostream>
#include <string>
using namespace std;

namespace dataType
{
  // Convierte el string a entero
  int entero(string str)
  {
    return atoi(str.c_str());
  }

  // Toma la parte fraccionaria de un numero en formato string
  float partefracc(string str)
  {
    int entero(string); // Declaracion de funcion (prototipo)

    return atof(str.c_str())-entero(str);
  }
}