/*
La formula usada en este codigo viene del libro C++ para ciencias e ingenieria.
Seccion 14.6
*/

#include<iostream>
#include<cmath>

using namespace std;

float f(float x)
{
  return 1/x;
}

float delta_sums(float a, float b, int k)
{
  float s=0;
  float n = pow(2, k);
  float delta_k = (b-a)/pow(2, k);

  for(int i=1; i<=n-1; i+=2)
    {
      s+= f(a + i*delta_k);
    }

  return delta_k*s;
}

int main()
{
  int k;
  float a=1, b=2;
  float T0, T_k, delta_k;

  cout << "Este programa integra la funcion 1/x " << endl;
  cout << "Introduzca los límites (a, b) y el orden del calculo k para la regla de trapezoide" << endl;
  
  cin >> a;
  cin >> b;
  cin >> k;
  
  T0 = (1.0/2.0)*(f(a) + f(b))*(b-a);
  
  if(k==0)
    {
      T_k=T0;
    }

  int j=1;
  
  while(j<=k)
    {
      T_k = (0.5)*T0 + delta_sums(a, b, j);
      T0 = T_k;
      j=j+1;
    }

  cout << "El valor de la integral es: " << endl;
  cout << T_k << endl;

  return 0;
}
