#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Quadratic
{
 public:
  Quadratic(); //Constructor
  float disc(float, float, float);
  vector<float> roots(float, float, float);
  void showRoots();

 private:
  vector<float> x;
};
