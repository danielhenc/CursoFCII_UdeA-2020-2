#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "TrapezoidalClass.h" //Incluir la clase

using namespace std;

//Inicializacion de variables
TrapezoidRule::TrapezoidRule(){
  float a=0;
  float b=0;
  float A=0;
  float B=0;
  float C=0;
  float x=0;
  float f=0;
  float I=0;
  int k=0;
}

//Esta funcion impreme un mensaje de bienvenida
void TrapezoidRule::DisplayMessage(){
  cout<<"Este código sirve para calcular la integral definida del polinomio cuadrático con forma AX^2 + BX +C en el intervalo [a,b]";
}


// Esta funcion permite que el usuario asigne los valores de las variables
void TrapezoidRule::SetValues(){
  cout << "\n Ingrese los valores de A, B y C para calcular la integral de dicho Polinomio\n";
  cout<< "A = ";
  cin>> A;
  cout<<"B = ";
  cin>> B;
  cout<<"C = ";
  cin>> C;
  cout<<"\nIngrese ahora en qué intervalo desea integrar \n";
  cout <<"a= ";
  cin >> a;
  cout << "b= ";
  cin >> b;
  cout << "Finalmente, ingrese el número de términos k que desearía calcular, sugerimos usar un valor mayor a 100 (no vaya tampoco a excederse y estallar su computador)\n";
  cin >> k;
  cout << "Se encontrará la integral para el polinomio: " << A <<"x^2 + "<< B << "x + "<< C <<"   en el intervalo: ["<< a <<","<< b <<"] "<<" \n";
}

// Esta funcion es la funcion que define expresion que queremos integrar
// En este caso particular vamos a integrar un polinomio cuadratico, pero en caso de querer integrar otra funcion basta con modificar esta funcion
float TrapezoidRule::Function(float x){
  float f;
  f=A*(pow(x,2))+B*x+C;
  return f;
} 


//ESta funcion aplica el algoritmo para la integracion usando la regla del trapecio
float TrapezoidRule::Rule(){
  float step;
  step=(b-a)/k; //Delta x
  I= 0.5*(Function(a)+Function(b));
  for (int i = 0; i < k; i++){
    I += Function(a+ step * i);
  }
  I *= step;
  return I;
}

//Esta funcion imprime el resultado de la integral
void TrapezoidRule::Result(){
  float I;
  I=Rule();
  cout << "El valor de la integral es: " << I <<"\n";
}
