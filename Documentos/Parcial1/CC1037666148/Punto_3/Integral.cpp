#include <iostream>
#include <cmath>

using namespace std;

float Trapezoidal_method(float,float,int);
float f(float);
float m(float,float,int);
float T0(float,float);
float suma_f(float,float);



int main()

{
  float a;
  float b;
  float I;
  cout << "Ingrese el límite inferior: " << endl;
  cin >> a;
  cout << "Ingrese el límite superior: " << endl;
  cin >> b;

  I = Trapezoidal_method(a,b,20);
  cout << "El valor de la integral es: " << I <<endl;
  
  
    
  return 0;

}



float f(float x)
{
  return x;
}



float m(float a,float b,int k)
{
  float dx;
  dx = (b-a)/k;
  return dx;
}



float suma_f(float a,float idx,int n)
{
  float sumf = 0;
  for (int i = 1; i<=n; i++)
    {
      sumf +=f(a+i*idx);

    }
  return sumf;
}



float T0(float a,float b)
{
  float T;
  T = (f(a)+f(b))*0.5;
  return T;
}



float Trapezoidal_method(float a,float b,int n)
{
  float T = T0(a,b);
  float dx = m(a,b,n);
  cout << dx << endl;
  T = dx*(T*0.5+suma_f(a,dx,n));
  return T;
}


