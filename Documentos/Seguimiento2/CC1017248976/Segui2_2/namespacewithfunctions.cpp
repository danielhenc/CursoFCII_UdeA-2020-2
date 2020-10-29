#include <iostream> 

using namespace std;

namespace Conversion{

//Devuelve la parte entera del numero proporcionado
  int entero(float e){ 
    return e;
    }

//Devuelve la parte fraccionaria del numero proporcionado
  float partefracc(float f){ 
    return f-entero(f);
    }
  
}
