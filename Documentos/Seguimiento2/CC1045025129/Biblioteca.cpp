#include <iostream> 

using namespace std;

namespace EntFrac{

  int entero(float a){ //Devuelve un entero
    return a;}


  float partefracc(float b){ //Devuelve la parte fraccionaria
    return b-entero(b);}
  
}
