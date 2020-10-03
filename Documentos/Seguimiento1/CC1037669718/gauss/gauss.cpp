#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>

using namespace std;

double gauss(double mu, double sigma, double x){
  return pow(8*atan(1)*sigma*sigma, -0.5)*exp(-0.5*pow((x-mu)/sigma,2));
}

int main(){
  double mu, sigma, x, dx;
  cout <<  "Este programa calcula los valores de una función gaussiana normalizada alrededor de su centro y los guarda en un archivo gauss.txt\n";
  cout << "Ingrese el valor medio de la gaussiana\n";
  cin >> mu;
  cout << "Ingrese la desviación estandar de la gaussiana\n";
  cin >> sigma;

  ofstream outfile;
  outfile.open("gauss.txt");
  for(double x = mu - 4*sigma; x < mu + 4*sigma; x += 8*sigma/1000){
    outfile << setw(10) << setprecision(4) << fixed << x << "\t" << setprecision(4) << fixed << gauss(mu, sigma, x) << "\n";
  }
  outfile.close();
  return 0;
}

