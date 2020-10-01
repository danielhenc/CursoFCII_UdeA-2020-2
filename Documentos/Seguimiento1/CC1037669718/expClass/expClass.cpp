#include<iostream>
using namespace std;

#include"expClass.h"

expClass::expClass(double X, unsigned int M){
  x = X; // initialize private variables
  N = M;
  calculate();
}

void expClass::set(double X, unsigned int M){
  x = X; // change private variables
  N = M;
  calculate();
}

void expClass::calculate(){
  r = 0.;
  for(unsigned int i = 0; i < N; i++) r += pow(x, i)/factorial(i);
}

void expClass::print(){
  cout << r;
}

unsigned int expClass::factorial(unsigned int M){
  unsigned int s = 1;
  for(unsigned int i = 1; i <= M; i++) s *= i;
  return s;
}
