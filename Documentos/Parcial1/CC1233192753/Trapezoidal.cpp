#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Func ( double x, double A, double k, double c, int n, int t)
{
  double y;
  switch (t)
  {
    case 1:
    y=pow(x,n);
    break;

    case 2:
    y=A*sin(k*x+c);
    break;

    case 3:
    y=A*cos(k*x+c);
    break;

    case 4:
    y=exp(x);
    break;

    case 5:
    y=1/x;
    break;

    default:
    cout<< "404 not found"<<endl;
    cout<< "No se pudo encontrar la función que esta solicitando" << endl;
    exit(0);
  }
  return y;
}


double Trapezoidal ( double a, double b, int m , double A, double k, double c, int n, int t)
{
  double delta;
  delta = (b-a)/m;
  double Integral;
  double suma;
  Integral = 0.5*(Func(a, A, k, c, n, t)+Func(b, A, k, c, n, t))*delta;
  suma = 0;
  for (int i=1;i<m-1;i++)
  {
    suma+= Func(a+i*delta, A, k, c, n, t);
  }
  Integral +=  delta*suma;
  return Integral;
}


int main ()
{
  double a;
  double b;
  int m;
  double z;

  int t;

  double A = 1;
  double k=1;
  double c=0;
  int n=1;

  cout<<"Este programa utiliza la regla del trapezio para calcular de manera numérica la integral de algunas funciones"<<endl;
  cout<<"Introduzca el número de la función que desea utilizar"<<endl;
  cout<<" 1. y = x^n "<<endl;
  cout<<" 2. y = A*sin(k*x + c)"<<endl;
  cout<<" 3. y = A*cos(k*x + c)"<<endl;
  cout<<" 4. y = exp(x)"<<endl;
  cout<<" 5. y = 1/x"<<endl;
  cin>>t;

  switch (t)
  {

    case 1:
    cout<<"Función y = x^n "<<endl;
    cout<<"Introduzca un entero n"<<endl;
    cin>> n;
    break;

    case 2:
    cout<<"Función y = A*sin(k*x + c)"<<endl;
    cout<<"Introduzca la constante A"<<endl;
    cin>>A;
    cout<<"Introduzca la constante k"<<endl;
    cin>>k;
    cout<<"Introduzca la constante c"<<endl;
    cin>>c;
    break;

    case 3:
    cout<<"Función y = A*cos(k*x + c)"<<endl;
    cout<<"Introduzca la constante A"<<endl;
    cin>>A;
    cout<<"Introduzca la constante k"<<endl;
    cin>>k;
    cout<<"Introduzca la constante c"<<endl;
    cin>>c;
    break;

    case 4:
    cout<<"Función y = exp(x)"<<endl;
    break;

    case 5:
    cout<<"Función y = 1/x"<<endl;
    break;

    default: 
    cout<< "404 not found"<<endl;
    cout<< "No se pudo encontrar la función que esta solicitando" << endl;
    exit(0);
  }

  cout<<"Introduzca el limite inferior de la integral x=a"<<endl;
  cin>>a;
  cout<<"Introduzca el limite superior de la integral x=b"<<endl;
  cin>>b;
  cout<<"Introduzca el numero de divisiones m para realizar el cálculo"<<endl;
  cin>>m;


  z=Trapezoidal(a, b, m, A, k, c, n, t);
  cout<<"El valor de la integral en el intervalo ["<<a<<","<<b<<"] para la función solicitada es" <<endl;
  cout<<z<<endl;
  return 0;
}
