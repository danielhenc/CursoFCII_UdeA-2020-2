#include "Entero.cpp"

using namespace Entero;

using namespace std;

int main()
{
  double Value;
  cout<<"Ingrese un numero"<<endl;
  cin>>Value;
  cout<<"La parte entera de "<<fixed<<Value<<" es "<<entero(Value)<<endl;

}
