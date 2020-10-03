/*
Este código usa la regla del trapezoide encontrada en otras fuentes
http://test.cua.uam.mx/MN/Methods/Integracion/Trapezoidal/Trapezoidal.php o wikipedia.
*/

#include<iostream>
#include<cmath>

using namespace std;

float f(float x)
{
  return 1/x;
}

float trapz(float a, float b, float N)
{

  float delta = (b-a)/N;

  float s=0;
  if(N!=0)
    {
      for(int i=1; i<N; i++)
	{
	  s = s + f(a+i*delta);	
	}
    }

  return (delta/2.0)*( f(a) + f(b)) + delta*s;

}

int main()
{
  int N;
  float a=1, b=2;
 
  cout << "Este programa integra la funcion 1/x" << endl;
  cout << "Introduzca los límites (a, b) y el N para la regla de trapezoide" << endl;

  cin >> a;
  cin >> b;
  cin >> N;
  
  cout << "El valor de la integral es: " << endl;
  cout << trapz(a, b, N) << endl;

  return 0;
}
