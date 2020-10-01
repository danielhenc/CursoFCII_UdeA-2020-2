#include "exp.h"

using std::cout;

int main()
{
	double x = 3;
	int N = 9;

	Exponencial exponencial(x, N);

	cout << "La funcion exponencial en x = " << x;
	cout << " Con orden N = " << N;
	cout << " es " << exponencial.exp() << "\n";

	return 0;
}
