/**
 * @author Valentina Roquemen Echeverry
 * @brief  Se diseña un a clase que calcula las raices de una ecuacion
 *		   cuadratica de la forma ax^2+bx+c. Los valores a,b y c son
 *         constantes. Se imprime los resultados en pantalla. 
 */
  
#include <iostream> 
#include <iomanip>
#include <cmath>
#include "math2.h"
using namespace std;

Roots::Roots( const float arregloParametros[parametros ])
{
	establecerParametros( arregloParametros );
	calcularRaices();
}

void Roots::establecerParametros( const float array[parametros] )
{
	a = array[0];
	b = array[1];
	c = array[2];
} 

void Roots::calcularRaices()
{
	float dis = b*b-4*a*c; // Discriminante de la ecuacion

	// Se calcula las raices reales en caso de que su discriminante sea positivo
	if (dis>=0)
	{
		r_root1 = (-b+sqrt(dis))/(2*a);
		r_root2 = (-b-sqrt(dis))/(2*a);

	}

	// Se calcula las componentes reales e imaginarias en caso de que su discriminante sea negativo
	else if (dis<0)
	{
		r_root1 = -b/(2*a);
		r_root2 = -b/(2*a); 
		i_root1 = sqrt(-dis)/(2*a);
		i_root2 = -sqrt(-dis)/(2*a);		
	}
}

void Roots::imprimirResultados()
{
	cout.precision(2); 
    cout<<showpos<<"Las raices de la ecuacion cuadratica de la forma "<<a<<"x^2 "<<b<<"x "<<c<< " son:"<<endl;

    if (i_root1==0 and i_root2==0)
    {
    	cout<<fixed<<"x_1 = "<<r_root1<<endl;
    	cout<<fixed<<"x_2 = "<<r_root2<<endl;
    } 
    else
    {
    	cout<<fixed<<showpos<<"x_1 = "<<r_root1<<i_root1<<"*i"<<endl;
    	cout<<fixed<<showpos<<"x_2 = "<<r_root2<<i_root2<<"*i"<<endl;
    }
}