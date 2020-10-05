#include <iostream>

class ExpFunction{
public:
	ExpFunction(double, int); //Constructor
	double exp(); //funcion exponencial
	long long int Fact(int); //funcion factorial 
	int N_max = 30; // orden maximo 

private:	
	int N;
	double X; 
};