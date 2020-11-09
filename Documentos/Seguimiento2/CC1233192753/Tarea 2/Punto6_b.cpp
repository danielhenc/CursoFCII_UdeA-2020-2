#include "Punto6_a.h"
using namespace std;

int main()
{
  double Value;
  cout<<"Ingrese un numero decimal"<<endl;
  cin>>Value;
  cout<<"La parte entera de "<<fixed<<Value<<" es "<<entero(Value)<<endl;
  cout<<"La parte deciaml de "<<fixed<<Value<<" es "<<partefrac(Value)<<endl;

  return 0;

}
