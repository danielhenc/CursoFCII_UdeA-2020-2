/**
 * @author Valentina Roquemen Echeverry
 * @brief  Esta libreria implemeta el metodo trapezoide
 *			par la integracion de funciones definidas. 
 *
 */
  
  
#include <iostream> 
#include <iomanip>
#include <cmath>
#include "trapezoide.h"
using namespace std;


MetodoTrapezoide::MetodoTrapezoide(float lim_inf, float lim_sup, int K)
{
	establecerParametros(lim_inf,lim_sup,K);
}

void MetodoTrapezoide::establecerParametros(float lim_inf, float lim_sup, int K)
{
	a = lim_inf;
	b = lim_sup;
	N = K;
} 

void MetodoTrapezoide::deltaX_k(int k)
{
	dx = (b-a)/pow(2,k);
}

float MetodoTrapezoide::Funcion(float x)
{
	return 1./x;
}

void MetodoTrapezoide::T_k(int k)
{
	float sumatoria=0;
	deltaX_k(k);

	for (int i = 1; i < pow(2,k); i+=2)
	{
		sumatoria += Funcion(a+i*dx);
		
	}
	t_k = 0.5*t_k + dx*sumatoria;
}

void MetodoTrapezoide::integralTrapezoide()
{
	t_k = 0.5*(Funcion(b)+Funcion(b-a))*(b-a); // Calculo de T0

	for (int k = 1; k <= N; ++k)
	{	
		T_k(k); // Se actualiza el valor de la integral
	}

	integral = t_k;
}

void MetodoTrapezoide::imprimirResultados()
{
	integralTrapezoide();
	
	cout.precision(1); 
    cout<<fixed<<"La integral de 1/x de "<<a<<" a "<<b<<" es: ";
	cout.precision(4); 
    cout<<integral<<endl;

}
