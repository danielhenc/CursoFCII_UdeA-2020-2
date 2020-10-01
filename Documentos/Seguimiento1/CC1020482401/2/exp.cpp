#include <iostream>
#include <cmath>
#include "exp.h"

using std::cout;
using std::endl; 

// method/function definitions of the class exp()
ExpFunction::ExpFunction(double x, int n)
{
	if (n > N_max or n < 0){
		cout << "N must be a positive integer less tha or equal to " << N_max << endl;
		N = N_max;
	}

	else
		N = n;
	
	X = x;
}

double ExpFunction::exp()
{
	double sum = 0;
	
	for (int i = 0; i <= N; i++)
		sum += pow(X, i)/Fact(i);
	return sum;
}

long long int ExpFunction::Fact(int n)
{
	int product = 1;
	
	if (n == 0)
		return 1;

	else{
		for (int i = n; i >= 1; i--)
			product *= i;
	}

	return product; 
}