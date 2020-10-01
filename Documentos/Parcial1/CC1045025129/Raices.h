//Se importan librerías
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

//Definición de la clase
class Raices
{
public:
  Raices(); //Constructor
  void AsignarValores(); //Función que recibe el polinomio a resolver
  void Solucionar(); //Encuentra las raices del polinomio
  void Resultados(); //Imprime las soluciones

private:
  float a;  //Asignación de los valores al polinomio de la forma ax^2+bx+c=0
  float b;
  float c;
  float Raiz[2]; //Arreglo que contiene las raices del polinomio
};
