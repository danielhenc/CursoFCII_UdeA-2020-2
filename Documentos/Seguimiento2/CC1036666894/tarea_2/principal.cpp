#include "nsComprNums.cpp" //incluir el archivo con el espacio de nombres
#include <iomanip>
#include <stdio.h>
//#include <\\home\\Documentos\\Universidad\\FCII\\Seguimiento2\\tarea_2\\nsComprNums.cpp>

using namespace nsComprNums;  //usar el espacio de nombres


int main()
{
  int valorent = 0;
  double valorfracc = 0;
  string str;
  bool valido = false;
  cout << "Introduzca un numero: " << endl;
  while(!valido)
    {
      //Se va a comprobar que se ingrese un numero y que no tenga caracteres incorrectos
      //Tambien se comprueba que si se ingrese algo
      getline(cin,str);
      if (str.length() == 0){
	valido = false;
	cout << "Numero incorrecto, por favor ingrese otro numero" << endl;
      }
      else{
	valido = true;
      }	
      for(int i=0; i<str.length(); i++){
	if(!isdigit(str.at(i)) and str.at(i) != '.' and str.at(i) != '-' and str.at(i) != '+'){
	  valido = false;  
	  cout << "Numero incorrecto, por favor ingrese otro numero" << endl;
	  break;
	}
	else{
	  valido = true;
	}
      }
    }
  
  valorent = entero(str);   //llamar a la funcion que devuelve la parte entera
  valorfracc = partefracc(str);  //llamar a la funcion que devuelve la parte decimal

  
  //Imprimir parte entera y decimal del numero ingresado
  cout << "La parte entera del numero introducido es: "  << valorent << endl;
  cout << "La parte decimal del numero introducido es: "  << valorfracc << endl;

  return 0;
}
