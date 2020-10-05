#include <iostream> //Se importan las librerías
#include <cmath>

using namespace std;
float Funcion(float); //Se nombra la función que va a recibir el integrando

int main(){
  float a = 0; //Límite inferior de la integral
  float b = 4; //Límite superior de la integral
  float k = 10000; //Número de fragmentos en que se desea partir el intervalo de integración
  float dx = (b-a)/k; //Ancho de cada uno de los fragmentos, que representa la altura de los trapecios
  float Integral = 0; //Se inicializa la variable que calcula la integral
  //En el siguiente while se calcula la integral de la función dada
  while(a<=b){ 
    Integral += (Funcion(a)+Funcion(a+dx))*dx/2; //Se suma de manera iterada el valor del área del trapecio hasta que se barra todo el intervalo de integración
    a += dx; }
  cout << "El valor de la integral es: " << Integral << endl;
  return 0;}

float Funcion(float x){
  float f = pow(x,3); //Definición de una posible función a integrar
  return f;
}
