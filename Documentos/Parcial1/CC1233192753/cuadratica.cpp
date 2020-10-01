#include <iostream>
#include "cuadratica.h"
#include <cmath>
#include <iomanip>
using namespace std;

EcuacionCuadratica::EcuacionCuadratica()
{
  a = 1.0;
  b = 1.0;
  c = 1.0;
  discriminante = 0;
  double arr[3]={};

}

void EcuacionCuadratica::setValues()
{

  cout << "Este programa cacula las raices de un polinomio de grado 2" <<endl;
  cout << "Resolviendo ax^2 + bx + c = 0 " <<endl;
  cout << "Inrese el coeficiente a" <<endl;
  cin>>a;

  if (a==0)
  {
    cout << "a debe ser diferente de 0 pues el programa encuentra las raices de un polinomio de grado 2" << endl;
    cout << "Inrese el coeficiente a" <<endl;
    cin >> a;
    while (a==0)
     {
      cout << "Inrese el coeficiente a" <<endl;
      cin >> a;
    }
  }

  cout<< "Inrese el coeficiente b" <<endl;
  cin>>b;
  cout<< "Inrese el coeficiente c" <<endl;
  cin>>c;

  discriminante = b*b - 4*a*c;
  arr[0]=discriminante;
}

void EcuacionCuadratica::raiz(double a, double b, double c, double arr[])
{

  if (arr[0] > 0)
  {
    double x1;
    double x2;

    x1 = (-b + sqrt(arr[0]))/(2*a);
    x2 = (-b - sqrt(arr[0]))/(2*a);


    arr[1]=x1;
    arr[2]=x2;

  }

  else if (arr[0] == 0)
  {
    double x;

    x = -b/(2*a);


    arr[1]=x;
    arr[2]=0;

  }

  else
  {
    double Rex;
    double Imx;

    Rex = -b/(2*a);
    Imx = sqrt(-arr[0])/(2*a);


    arr[1]=Rex;
    arr[2]=Imx;


  }
}

void EcuacionCuadratica::print()
{

  raiz(a, b, c, arr);

  if(arr[0]>0)
  {

    cout<< "La ecuacion " << a << "x^2 + " << b << "x + " << c << " = 0" << " tiene soluciones " <<endl;
    cout<<fixed<<setprecision(2)<< "x1 = " << arr[1] << setw( 13 ) << "x2 = " << arr[2] <<endl;
  }

  else if (arr[0] == 0)
  {

    cout<< "La ecuacion " << a << "x^2 + " << b << "x + " << c << " = 0" << " tiene solucion " <<endl;
    cout<<fixed<<setprecision(2)<< "x = " << arr[1] <<endl;
  }

  else
  {

    cout<< "La ecuacion " << a << "x^2 + " << b << "x + " << c << " = 0" <<" tiene soluciones " <<endl;
    cout<<fixed<<setprecision(2)<<  "x1 = " << arr[1] << " + "<< arr[2] << "i" << setw( 13 ) << "x2 = " << arr[1] << " - "<< arr[2] << "i" <<endl;
  }

}
