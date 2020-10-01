#include <iostream>
#include <cmath>
#include "exp.h"

using std::cout;
using std::endl; 

Exponencial::Exponencial(double x, int n)
{
	if (n > N_m or n < 0)
	  {
		cout << "Por favor inserte un número mayor que cero y menor que  " << N_m << endl;
		N = N_m;
	}

	else
		N = n;
	
	X = x;
}

double Exponencial::exp()
{
	double s = 0;
	
	for (int i = 0; i <= N; i++)
		s += pow(X, i)/F(i);
	return s;
}

long long int Exponencial::F(int n)
{
	int k = 1;
	
	if (n == 0)
		return 1;

	else
	  {
		for (int i = n; i >= 1; i--)
			k *= i;
	}

	return k; 
}
