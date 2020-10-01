/* Johan Alexis Carrillo Toro - 1214734681
	This program calculate the integral of a function using the trapezoidal rule*/


#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

// Prototypes
float function_to_integrate( float );  // Defines the function to integrate
float integrate( float, float, int );


int main(){

	cout << "Este programa calcula la integral de una funcion mediante el metodo de trapecios\n";
	cout << "Si desea cambiar cambiar los limites de integracion y el numero de pasos debe hacerlo ";
	cout << "en la seccion de inicializacion de parametros en la funcion \"main\" \n";
	cout << "Si desea cambiar la funcion a integrar debe hacerlo en la funcion \"function_to_integrate\"" << endl;

	float x_min, x_max;  // Integration interval limits
	float A;  // used to contain the calculated area value
	int k_max;  // Number of steps

	// Initialization of parameters
	x_min = 1.0;
	x_max = 2.0;
	k_max = 15;

	A = integrate(x_min, x_max, k_max);

	cout << "El area de la integral es: " << setprecision(5) << A << endl;


	return 0;
}


// Definition of the functions
float function_to_integrate(float x){
	// This is the function to integrate

	return 1.0/x;
}

float integrate(float x_min, float x_max, int k_max){
	// This function uses the trapezoidal rule to integrate

	cout << "Comenzando a integrar" << endl;

	float dx_k;  // number of partitions for the k-th step
	float T_k, sum;

	T_k = 0.5 * (function_to_integrate(x_max) + function_to_integrate(x_max)) * (x_max - x_min);  // initialized as T_0


	for(int k=1; k<=k_max; k++){

		sum = 0;  // reset the value of the partial sum of odd i index in the next for cycle
		dx_k = (x_max - x_min) / float(pow(2.0, k));  // number of partitions in the step k

		for(int i=1; i<pow(2, k); i+=2, sum += function_to_integrate(x_min + i*dx_k)); // calculates the partial sums only for odd i
		T_k = 0.5*T_k + dx_k*sum;
	}

	return T_k;  // Return the value of the integral
}

