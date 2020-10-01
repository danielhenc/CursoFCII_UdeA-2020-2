#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;   // estas dos funciones se usan para imprimir los resultados
using std::fixed;          // aproximando a dos cifras decimales

class quad_solve{
	public:
	quad_solve();          // constructor de la clase 
	void set_coefs();      // para dar valores a los coeficientes del polinomio
	void show_coefs();     // muestra al polinomio con los coeficientes

	void poly_roots();     // devuelve las raíces del polinomio

	private:
	double a,b,c;          // coeficientes del polinomio
	double det;            // determinante de los coeficientes del polinomio 
	double p_roots[2];     // arreglo que contiene las raíces del polinomio

	void determinant();    // calcula el determinante

	void r_roots();        // calcula las raices reales si det >= 0
	void im_roots();       // calcula las raíces complejas si det < 0
};
