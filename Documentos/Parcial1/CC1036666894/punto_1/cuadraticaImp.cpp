#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#include "cuadratica.h"

using namespace std;

//Constructor inicializando numeros ingresados por el usuario
cuadratica::cuadratica(float var_a, float var_b, float var_c){

  a = var_a;
  b = var_b;
  c = var_c;
}
  //Calcula el discriminante y devuelve 1 si es positivo, o 0 si es negativo
bool cuadratica::discriminante(){

  disc = pow(b,2)-4*a*c;
  
  if(disc<0){
    condition = false;
  }
  else{
    condition = true;
    }
  return condition;
}
 
//Calcula las raices de la ecuacion cuadratica dependiendo de su discriminante
void cuadratica::calculoResultado(){

  discriminante();

  //Se separa en varias soluciones, una si el discriminante es positivo y la otra si es negativo
  
  if (condition==true){
    x1 = -b/(2*a) + sqrt(disc)/(2*a);
    x2 = -b/(2*a) - sqrt(disc)/(2*a);
  }
  
  //Si el discriminante es negativo, se separa en solucion real e imaginaria
  else{
    x1r = -b/(2*a);
    x1i = sqrt(-disc)/(2*a);
    x2r = -b/(2*a);
    x2i = -sqrt(-disc)/(2*a);
  }
}

//Imprime el resultado teniendo en cuenta de nuevo el signo del discriminante
void cuadratica::imprimirResultado(){

  calculoResultado();
  
  cout << " " << endl;
  cout << "La ecuacion " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
  
  if (condition == true){
    cout << fixed << endl;
    cout << "Tiene como raices: "<< setprecision(2) << x1 << setw(4) << " y "<< setw(4) << x2 << endl;
  }
  
  //Si el discriminante es negativo, imprime la parte real y la imaginaria
  else {
    cout << fixed << endl;
    cout << "Tiene como raices: " << setprecision(2) << x1r << " + (" << x1i<< ")*i" << setw(4)<< "y " << setw(4) << x2r << " + ("<< x2i<< ")*i" << endl;
  }
}
  

