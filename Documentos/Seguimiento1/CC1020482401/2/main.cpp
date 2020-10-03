#include "exp.h"

using std::cout;

int main(int argc, char const *argv[])
{
	double x = 2;
	int N = 4;

	ExpFunction exp_funtion(x, N);

	cout << "El valor de la funcion exponencial en x = " << x;
	cout << " con una precision de orden N = " << N;
	cout << " es " << exp_funtion.exp() << "\n";

	return 0;
}