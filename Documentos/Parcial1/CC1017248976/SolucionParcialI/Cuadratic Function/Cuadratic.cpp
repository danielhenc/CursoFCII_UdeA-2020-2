#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "CuadraticClass.h" //importar clase creada

using namespace std;

//Inicializacion variables
Cuadratic::Cuadratic(){
  float a=1;
  float b=1;
  float c=1;
  float x1=1;
  float x2=1;
  float x11=1;
  float x12=1;
  float x21=1;
  float x22=1;
}
//Esta funcion imprime un mensaje de bienvenida
void Cuadratic::DisplayMessage(){
  cout<<"Con este código encontraremos las raíces de un polinomio cuadrático del tipo ax^2+bx+c \n";
  cout<<"Recurde que el caso óptimo es en el cual a,b,c tienen valores.\n";
  cout<<"Pueden ocasionar errores si no hace una adecuada selección de qué valores puden o no ser cero, téngalo presente.";
}
//Con esta funcion el usuario pasa los valores de las variable
void Cuadratic::SetValues(){
  cout << "\n Ingrese los valores de a, b y c para calcular las raices\n";
  cout<< "a = ";
  cin>> a;
  cout<<"b = ";
  cin>> b;
  cout<<"c = ";
  cin>> c;    //float x11,x12,x21,x22;
  cout << "Se encontrarán las raices para el polinomio: " << a <<"x^2 + "<< b << "x + "<< c <<" \n";
}

//Con esta funcion se calcula el discriminante del polinomio
float Cuadratic::Discriminant(float a, float b, float c){
  float D=0;
  D = pow(b,2.0)-(4.0*a*c);
  return D;
}

//Esta funcion se encarga de encontrar las raices para el polinomio
float Cuadratic::Root(float a, float b, float c){
  float D=0;
  D=Discriminant(a, b, c);
  //selecciona si la raiz sera compleja o real
  if(D >= 0){ //para raices reales
    float r=0;
    r = sqrt(D);
    x1=(( -1 * b) - r) / (a * 2.0);
    x2=(( -1 * b) + r) / (2.0 * a);
    return x1, x2;
  }
  else { //para raices complejas
    float r=0;
    r=sqrt(-D);
    x11= (-b) / (2.0 * a);
    x12= (r) / (2.0 * a);
    x21= (-b) / (2.0 * a);
    x22= (- r ) / (2.0 * a);
    return x11,x12,x21,x22;
  }
}
//Esta funcion se encarga de imprimir el resultado obtenido para las raices del polinomio
void Cuadratic::Result(){
  float D;
  D=Discriminant(a, b, c);
  if(D>=0){ //para raices reales
    x1, x2 = Root(a,b,c);
    cout<<"Las raices son: \n";
    cout<<"x1= "<< setprecision(3) << x1 <<"\n";
    cout<<"x2= "<< setprecision(3) << x2 <<"\n";
  }
  else{ //para raices complejas
    x11,x12,x21,x22 = Root(a, b, c);
    cout<<"Las raices son: \n";
    cout<<"x1= "<<setprecision(3)<< x11 <<" + "<<setprecision(3)<<x12<<"i\n";
    cout<<"x2= "<<setprecision(3)<< x21 <<" - "<<setprecision(3)<<-x22<<"i\n";
  }

}
