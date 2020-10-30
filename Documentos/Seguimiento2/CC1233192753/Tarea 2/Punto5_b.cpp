#include <iostream>
#include "Punto5_a.h"


using namespace std;

int main()
{
  double Nd;

  cout<<"Ingrese un numero decimal"<<endl;
  cin>>Nd;
  cout<<"La parte entera de "<<fixed<<Nd<<" es "<<entero(Nd)<<endl;



  return 0;
}
