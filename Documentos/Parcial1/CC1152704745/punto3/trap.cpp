#include "trap.h"

double trap_int(double f (double), double a, double b, int n){
	/* Función para calcular la integral de una función de una variable.
		INPUTS: f - función de tipo double con entrada de tipo double
		        a - límite inferior de integración de tipo double
 		        b - límite inferior de integración de tipo double
		        n - número de divisiones para hacer la integral, de tipo entero*/

	double h = (b-a)/n;  // Base de cada trapecio. Depende del número de divisiones y de los límites
	double t_int = 0;    // Valor inicial de la suma de la integral
	double xi = a;       // Valor inicial del límite inferior del trapecio

	for (int i=0; i<n; i++){
		/* Se calcula el área de los n trapecios y se va sumando*/

		double xip1 = xi + h;                // El límite superior es el inferior + h
		t_int += trap(f(xi), f(xip1), h);    // Se calcula el área del trapecio
		xi = xip1;                           // El límite inferior siguiente es el superior actual
	}

	return t_int;
}

double trap(double fi, double fip1, double h){
	/* Función que calcula el área de cada trapecio.
		INPUTS: fi   - la función evaluada en el límite inferior del trapecio, de tipo double
		        fip1 - la función evaluada en el límite superior del trapecio, de tipo duouble
		        h    - la base del trapecio, de tipo double*/

	double t1 = fi + fip1;
	double t2 = t1*h;
	
	return t2/2.;
}

