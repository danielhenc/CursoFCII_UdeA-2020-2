#include<iostream>
#include<cmath>
#include<vector>
#include <iomanip>

#include "quadratic.h"

using namespace std;

Quadratic::Quadratic()
{
  x = {0, 0, 0, 0};
}

float Quadratic::disc(float a, float b, float c)
{
  return b*b - 4*a*c;
}

vector<float> Quadratic::roots(float a, float b, float c)
{
  x = {0, 0, 0, 0};
  
  float d = disc(a, b, c);
  
  if(d>=0)
    {

      x[0] = (-b + sqrt(d))/2.0;
      x[1] = 0;
      x[2] = (-b - sqrt(d))/2.0;
      x[3] = 0;
      
    }
  else
    {

      x[0] = -b/2.0;
      x[1] = sqrt(abs(d))/2.0;

      x[2] = -b/2.0;
      x[3] = -sqrt(abs(d))/2.0;
      
      }
  
  return x;
}


void Quadratic::showRoots()
{
  cout << "x"<< 1 <<" = (" << fixed << setprecision(2) << x[0] << ", " << x[1] << ")" << endl;
  cout << "x"<< 2 <<" = (" << fixed << setprecision(2) << x[2] << ", " << x[3] << ")" << endl;
}
