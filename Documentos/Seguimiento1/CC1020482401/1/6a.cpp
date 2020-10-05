#include <iostream>
#include <cmath>

using std::cout; 


float normal_function(float, float, float);


int main(int argc, char const *argv[])
{

	cout << "El valor de la funcion normal centrada en 90 y con una desviación de 4 en x=80 es:\n";
	cout << normal_function(80, 90, 4) << "\n";

	return 0;
}


float normal_function(float x, float mu, float sigma)
{
	float N, z; 

	N = 1 / (sigma * sqrt(2 * M_PI));
	z = (x - mu) / sigma;

	return N * exp(-0.5 * pow(z, 2));
}