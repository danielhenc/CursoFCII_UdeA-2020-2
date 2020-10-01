//Se importan las librerías
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

#include "Raices.h" //Se importa el archivo que contine la clase (Programación modular)

Raices::Raices() //Constructor
{ //Se inicializan las variables
 a = 0; 
 b = 0;
 c = 0;
 Raiz[0] = 1;
 Raiz[1] = 1;
 
}

void Raices::AsignarValores() //Se pide al usuario que ingrese los coeficientes del polinomio
{ 
  cout <<  "Recuerde que la expresión a ingresar debe tener la forma ax^2+bx+c=0\n Ingrese el valor de a " ;
  cin >> a;

  cout <<  "Ingrese el valor de b ";
  cin >> b;

  cout <<  "Ingrese el valor de c ";
  cin >> c;

}

void Raices::Solucionar() //Soluciona el polonomio
{ float dis = 0; //Se inicializa el discriminante
  //Caso en el que se tiene raices reales
  if(pow(b,2) >= 4*a*c){
    dis = sqrt(pow(b,2.0)-4*a*c);
    Raiz[0] = (-1*b + dis)/(2.0*a); //Primera raíz
    Raiz[1] = (-1*b - dis)/(2.0*a); //Segunda raíz
  }
  //Caso en el que se tiene raices complejas
  else{
    dis = sqrt(-(pow(b,2)-4*a*c));
    Raiz[0] = dis/(2*a); 
    Raiz[1] = - dis/(2*a);
  }

}

void Raices::Resultados() //Se imprimen en pantalla los resultados
{ //Raices reales
  if(pow(b,2) >= 4*a*c){
    cout<<"Una de las raices de la ecuación es "<< setprecision(2) << Raiz[0] << endl;
    cout<<"La otra raíz es "<<  setprecision(2) << Raiz[1] << endl;}

  //Raices complejas
  else{
    cout<<"Una de las raices de la ecuación es "<< setprecision(2) << -b/(2*a) << "+" << setprecision(2) << Raiz[0] << "i" << endl;
    cout<<"La otra raíz es " << setprecision(2) << -b/(2*a) << "-" << "("<< setprecision(2) << Raiz[1] << ")" <<"i" <<  endl;
  }
}
