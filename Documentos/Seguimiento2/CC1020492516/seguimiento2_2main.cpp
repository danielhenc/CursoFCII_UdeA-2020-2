//Main de la tarea

#include "seguimiento2_2namespace.cpp"
#include <string>

using namespace std;
using namespace partes;

int main()
{
  double x = 0;
  cout<<"Ingrese un número cualquiera: ";
  cin>> x;
  cout<< "Parte entera del número es: " << entero(x) <<endl;
  cout<<"Parte fraccionaria es: " << partefracc(x) << endl;
 
  return 0; 
	   }  
