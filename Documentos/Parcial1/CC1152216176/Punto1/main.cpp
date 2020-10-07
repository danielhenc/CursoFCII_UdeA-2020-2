#include<iostream>
using namespace std;

#include"cuadratica.h"

int main()
{
	float a;
	float b;
	float c;

	cout << "Para obtener las reices de la ecuacion cuadratica (a)x^2 + (b)x + c por favor ingrese los valores de las constantes\n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	QuadEc ecuacion(a,b,c);
	ecuacion.roots();
}
