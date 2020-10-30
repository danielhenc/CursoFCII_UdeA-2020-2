#include<iostream>
#include</home/anacristina/Semestre_9/FCII/CursoFCII_UdeA-2020-2/Documentos/Seguimiento2/CC1044508251/intNumber.cpp>
#include <iomanip>
#include<string>

using namespace std;
using namespace intNumber; // Funciones que devuelven int y double.

int main()
{
  // Ingresar el numero
  double x;
  cout << "Ingrese un numero: " << endl;
  cin >> x;

  //================================================================
  //PUNTO 5 - Parte C -- Para namespace con solo la funcion enteros
  /*
  cout << "\nParte entera: " << enteros(x) << endl;
  //*/

  //================================================================
  //PUNTO 6 - Parte C -- Para namespace con solo ambas funciones, enteros y partefracc
  //*
  cout << "\nParte entera: " << enteros(x) << endl;
  cout << "Parte decimal: " << partefracc(x) << endl;
  //*/
}  
