#include <iostream>
#include <string>

using namespace std;

class EcuacionCuadratica
{
public:
  EcuacionCuadratica();
  void setValues();
  void raiz(double, double, double, double arr[]);
  void print();

private:
  double a;
  double b;
  double c;
  double discriminante;
  double arr[3];
};
