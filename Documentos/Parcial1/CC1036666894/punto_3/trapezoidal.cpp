#include <iostream> 
#include <cmath>

using namespace std;

float funcion(float); 

int main(){

  float a=0;
  float b=0;
  float I=0;
  float dx=0;

  //limites de la integral  
  cout << "Escriba los límites de la integral" << endl;
  
  cout << "límite inferior (a): ";
  cin >> a;
  
  cout << "Límite superior (b): ";
  cin >> b;
  
  float i; //particiones
  
  cout << "Escriba el numero de particiones para hacer a la funcion: " ;
  cin >> i;
  
  dx = (b-a)/i; //delta de x

  
  while(a<=b){ //regla trapezoidal
    
    I += (funcion(a)+funcion(a+dx))*dx/2;
    a += dx;
  }

  
  cout << "El valor de la integral es: " << I << endl;


  
  return 0;
}
//funcion a evaluar su integral
float funcion(float x){

  float func = 1/x;

  return func;
}
