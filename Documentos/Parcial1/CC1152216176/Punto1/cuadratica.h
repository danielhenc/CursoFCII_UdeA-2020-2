#include<iostream>
#include<cmath>

using namespace std;

class QuadEc
{
	public:
	QuadEc(float,float,float);
	void set(float,float,float);
	void show();
	void roots();

	private:
	float a;
	float b;
	float c;
};
