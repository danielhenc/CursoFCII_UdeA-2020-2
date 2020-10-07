#include <iostream>
#include "trapezoidalMethod.h"

using std::cout;
using std::endl;

double function(double);

int main(int argc, char const *argv[])
{
	// the partition is introduced as parameter when the code is executed
	int n = (*argv[0] == '.') ? 1000 : *argv[0]; 
	
	double integralValue;

	trapezoidalMethod tmInstance(n);

	// functions to integrate between 0 and 5 is set here
	tmInstance.setFunction(function, 2, 5);
	// the result of the integral is calculated here
	integralValue = tmInstance.runIntegration();

	cout << "La integral da " << integralValue << endl;

	return 0;
}

double function( double x){
	return 3 * x * x - 2;
}
