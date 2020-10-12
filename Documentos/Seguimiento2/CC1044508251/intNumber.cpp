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
  int enteros(string n) // Funcion devuelve parte entera
  {
    int N = stof(n);
    return N;
  }
}
*/

//===============================================
//PUNTO 6 - Parte C
//*
namespace intNumber

{  
  int enteros(string n) // Funcion que devuelve parte entera
  {
    int N = stof(n);
    return N;
  }

  float partefracc(string n) // Funcion que devuelve parte decimal
  {
    int pos = n.find('.');
    string dec = "0";

    for(int i=pos; i<n.size(); i++)
      {
	dec = dec+n[i];
      }
    
    float res = stof(dec);
    return res;
  }
}
//*/
