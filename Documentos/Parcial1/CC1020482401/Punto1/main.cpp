#include "quadPoly.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

int main(int argc, char const *argv[])
{
	// the polynomial coefficients are set here 
	float a = 3, b = 2, c = 1;

	// the QuadPoly class is instantiated
	QuadPoly poly(a, b, c);

	// the polynomials roots are calculated 
	poly.calculate_Roots();

	// the result is displayed with 2 order precision
	cout << "las Soluciones al polinomio ";
	poly.print_equation();
	cout << " en forma (real, Img), son:" << endl;
	cout << "x+ = " << "(" << setprecision(2) << poly.Roots[0][0] << ",";
	cout << setprecision(2) << poly.Roots[0][1] << ")" << endl;
	cout << "x- = " << "(" << setprecision(2) << poly.Roots[1][0] << "," ;
	cout << setprecision(2) << poly.Roots[1][1] << ")" << endl;

	return 0;
}