#include<iostream>
#include<cmath>

using namespace std;

double gauss(double mu, double sigma, double x){
  return pow(8*atan(1)*sigma*sigma, -0.5)*exp(-0.5*pow((x-mu)/sigma,2));
}

int main(){
  double mu, sigma, x;
  cout <<  "Punto 6b seccion 3.6:\nEste programa calcula el valor de una función gaussiana normalizada\n";
  cout << "Ingrese el valor medio de la gaussiana\n";
  cin >> mu;
  cout << "Ingrese la desviación estandar de la gaussiana\n";
  cin >> sigma;
  cout << "Ingrese el valor de x para el cual quiere conocer el valor de la gaussiana\n";
  cin >> x;
  cout << "El resultado es y = " << gauss(mu, sigma, x) << "\n";
  return 0;
}

