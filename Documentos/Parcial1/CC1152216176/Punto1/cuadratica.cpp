#include<iomanip>
#include<iostream>
using namespace std;

#include"cuadratica.h"

//Constructor
QuadEc::QuadEc(float A,float B,float C)
{
	set(A,B,C);
}

//Definir constantes de la ecuacion
void QuadEc::set(float A,float B,float C)
{
	a = A;
	b = B;
	c = C; 
}

//Muestra la forma de la ecuacion
void QuadEc::show()
{
	cout << "(" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0";
}

//Calcula las raices de la ecuacion y las imprime
void QuadEc::roots()
{
	//Caso de ecuacion lineal
	if(a == 0)
	{
		cout << "La ecuacion no es cuadratica, la raiz es " << (-c/b) << "\n";
	}

	//Raices reales
	else if(b*b > 4*a*c)
	{
		cout << "Las raices de la ecuacion ";
		show();
		cout << " son x = " << fixed << setprecision(2) << (-b+sqrt(b*b-4.0*a*c))/(2.0*a);
		cout << "y x = " << fixed << setprecision(2) << (-b-sqrt(b*b-4.0*a*c))/(2.0*a) << "\n";
	}

	//Raices complejas
	else if(b*b < 4*a*c)
	{
		cout << "Las raices de la ecuacion ";
		show();
		cout << " son x = " << fixed << setprecision(2) << -b/(2.0*a) << " + " << fixed << setprecision(2) << sqrt(4.0*a*c-b*b)/abs(2.0*a) << "i ";
		cout << "y x = " << fixed << setprecision(2) << -b/(2.0*a) << " - " << fixed << setprecision(2) << sqrt(4.0*a*c-b*b)/abs(2.0*a) << "i\n";
	}

	//Raiz unica
	else if(b*b == 4*a*c)
	{
		cout << "La raiz de la ecuacion ";
		show();
		cout << " es x = " << -b/(2.0*a) << "\n";
	}
}
