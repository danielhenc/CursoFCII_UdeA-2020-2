#include<iostream>
#include<cmath>

using namespace std;

int main(){
  cout << "Punto 6a sección 3.6:\n";
  double mu = 90., sigma = 4., x = 80., pi = atan(1)*4, y;
  y = pow(2*pi*sigma*sigma ,-0.5)*exp(-0.5*pow((x-mu)/sigma,2));
  cout << "El resultado es " << y << "\n";
  return 0;
};
