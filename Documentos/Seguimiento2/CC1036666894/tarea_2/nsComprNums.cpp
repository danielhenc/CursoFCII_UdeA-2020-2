#include <iostream>
#include <string>
using namespace std;

namespace nsComprNums  //Crear el espacio de nombres
{  
  int entero(string str)  //Funcion que va a devolver parte entera
  {
    int ent = stoi(str);  //Convierte el string que recibe la funcion en un entero
    return ent;
  }

  double partefracc(string str)  //Funcion que retorna la parte decimal
  {
    double valFracc = 0;
    double parteFracc = 0;
    int value = entero(str); //Llama a la funcion anterior
    valFracc = stod(str);    //Convierte el numero ingresado en un double
    //cout << "El valor del str convertido en double es: " << valFracc << endl;
    parteFracc = valFracc - value;  //Saca la parte decimal restando el numero con su parte entera
    
    if (parteFracc<0.0) parteFracc=-parteFracc;  //Siempre retornar la parte decimal como numero positivo
    
    return parteFracc;
  }
}
