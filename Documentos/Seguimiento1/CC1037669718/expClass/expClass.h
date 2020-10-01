#include<iostream>
#include<cmath>

using namespace std;

class expClass{
 public:
  expClass(double, unsigned int);
  void set(double, unsigned int);
  void calculate();
  void print();

 private:
  double x; // input
  unsigned int N; // precision
  double r; //result
  unsigned int factorial(unsigned int);
};
