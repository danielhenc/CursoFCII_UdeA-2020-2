#include <iostream> 
#include <cmath>

using namespace std;
float Funtion(float); //Función que estará en la integral

int main()
{
  float a, b; //Valor del límite inferior y superior respectivamente
  cout << "Escriba valores de a y b para calcular el valor de I" << endl;
  cout << "límite inferior, a = ";
  cin >> a;
  cout << "Límite superior, b = ";
  cin >> b;
  float k; //Porciones en que se partirá el intervalo de integración
  cout << "ingrese el número de 'porciones' en que quiere partir el intervalo de integración (como consejo que sea un número grande, miles), k = " ;
  cin >> k;
  float dx = (b-a)/k; //definimos la porción para cada trapecio tal como se define en el libro
  float I = 0; //Variable de la integral
  while(a<=b) //Ahora aplicamos la regla del trapecio para calcular el valor de la integral
    { 
    I += (Funtion(a)+Funtion(a+dx))*dx/2; //Se realiza la suma del área del trapecio
    a += dx;
    }
  cout << "El valor de la integral es: " << I << endl;
  return 0;
}

float Funtion(float x)
{
  float f = cos(x); //Definimos la función que queremos integrar
  return f;
}
