#include <iostream>

class Exponencial{
public:
	Exponencial(double, int); //Nuestri constructor
	double exp(); //Exponencial
	long long int F(int); //Factorial 
	int N_m = 20; // Orden máximo 

private:	
	int N;
	double X; 
};
