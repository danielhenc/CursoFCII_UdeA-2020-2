#include<iostream>
#include<math.h>
#include<string>

using namespace std;

/*
Creacion del NAMESPACE
*/

//===============================================
//PUNTO 5 - Parte C
/*
namespace intNumber
{
  int enteros(double n) // Funcion devuelve parte entera
  {
    int N = n;
    return N;
  }
}
//*/

//===============================================
//PUNTO 6 - Parte C
//*
namespace intNumber

{  
  int enteros(double n) // Funcion que devuelve parte entera
  {
    int N = n;
    return N;
  }

  double partefracc(double n) // Funcion que devuelve parte decimal
  {
    return n - enteros(n);
  }
}
//*/
