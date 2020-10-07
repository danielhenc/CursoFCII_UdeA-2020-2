#include "trap.h"

double f(double);
double gaussian_centered(double);


int main(){

	double int_x05 = trap_int(f, 0.0, 1.0, 10);

	std::cout << "Integral de sqrt(x) de 0 a 1: "  << int_x05 << std::endl;

	double int_gauss = trap_int(gaussian_centered, -5.0, 5.0, 10);

	std::cout << "Integral de N(x;0,1) de -5 a 5: "  << int_gauss << std::endl;
	
	return 0;
}

double f(double x){
	return std::sqrt(x);
}

double gaussian_centered(double x){
	double pi = 3.141592653589793;
	double mu = 0;
	double sigma = 1;

	double ex_1 = sigma * std::sqrt(2. * pi);
	double ex_2 =  (std::pow((x - mu),2)/std::pow(sigma,2)) * (-0.5);

	return std::exp(ex_2)/ex_1;
}

