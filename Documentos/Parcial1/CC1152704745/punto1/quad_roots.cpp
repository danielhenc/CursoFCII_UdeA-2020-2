#include "quad_roots.h"

quad_solve::quad_solve(){
	/* Constructor de la clase */
	double a=0,b=0,c=0;        // coeficientes
	double det=0;              // determinante del polinomio
	double p_roots[2];         // arreglo que guarda las raíces del polinomio
}

void quad_solve::set_coefs(){
	/* Función para introducir los coeficientes del polinomio. */
	cout << "Ingrese los coeficientes del polinomio de segundo orden:" << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
}

void quad_solve::show_coefs(){
	/* Función para mostrar los coeficientes del polinomio. */
	cout << "El polinomio es de la forma: (" << a << ")*x^2 + (" << b << ")*x + (" << c << ")" << endl;
}

void quad_solve::determinant(){
	/* Función para calcular el determinante del polinomio. */
	det = b*b - 4.*a*c;
}

void quad_solve::r_roots(){
	/* Función para calcular las raíces reales. En cada entrada de p_roots se guarda cada raíz. */
	double R_r_sqrt = std::sqrt(det);
	double R_r_1 = -b;

	p_roots[0] = (R_r_1 + R_r_sqrt)*0.5/a;
	p_roots[1] = (R_r_1 - R_r_sqrt)*0.5/a;

}

void quad_solve::im_roots(){
	/* Función para calcular las raíces complejas. En p_roots se guarda la parte en la primera entrada
                                                   y la parte imaginaria en la segunda entrada */
	double IM_r_sqrt = std::sqrt(-det);
	double IM_r_1 = -b;

	p_roots[0] = IM_r_1*0.5/a;
	p_roots[1] = IM_r_sqrt*0.5/a;

}

void quad_solve::poly_roots(){
	/* Función que calcula e imprime las raíces del polinomio */
	determinant();

	cout << "ADVERTENCIA: las raíces serán aproximadas hasta la segunda cifra decimal." << endl;
	
	cout << setprecision(2) << fixed;


	/* Dependiendo del signo del determinante, se usa la función para calcular las raíces reales o
       complejas. */
	if (det < 0){
		im_roots();

		cout << "Las raíces del polinomio son complejas, y son: " << endl;
		cout << "x1 = " << p_roots[0] << " + " << p_roots[1] << "i" << endl;
		cout << "x2 = " << p_roots[0] << " - " << p_roots[1] << "i" << endl;
	}
	
	else if (det > 0){
		r_roots();

		cout << "Las raíces del polinomio son reales puras, y son: " << endl;
		cout << "x1 = " << p_roots[0] << endl;
		cout << "x2 = " << p_roots[1] << endl;
	}
	
	else if (det == 0){
		r_roots();

		cout << "El polinomio sólo tiene una raíz, y es: " << endl;
		cout << "x1 = " << p_roots[0] << endl;
	}
}
