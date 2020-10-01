#include<iostream>
#include<cmath>
#include<vector>

#include "quadratic.h"

using namespace std;

int main()
{
  cout << "Este programa resuelve la ecuacion ax^2 + bx + c =" << endl;
  cout << "Enter a, b, c: " << endl;

  float a, b, c;
  
  cin >> a;
  cin >> b;
  cin >> c;
  
  Quadratic results;

  cout << "Discriminante: " << results.disc(a, b, c) << endl;

  vector<float> R = results.roots(a, b, c);
  
  results.showRoots();
  
  return 0;
}
