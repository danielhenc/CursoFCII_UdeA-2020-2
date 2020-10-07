/*
Implmentación de la clase CuadEqSol
*/

#include <iostream>
#include <cmath>
#include <math.h>
#include "ecuacioncuad-P1.h" 

using namespace std;


CuadEqSol::CuadEqSol()
{
	inValues(); 
}

void CuadEqSol::inValues()
{
	cout << "Bienvenido! \nEste programa calculará las raices de la ecuación ax^2 + bx + c = 0 " << endl;
	cout << "\nPor favor ingrese las constantes a, b, c en el orden que se le solicite \n" << endl;

	cout << "Ingrese a" << endl;
	cin >> a; //Obtenemos a

	cout << "Ingrese b" << endl;
	cin >> b; //Obtenemos b

	cout << "Ingrese c" << endl;
	cin >> c; //Obtenemos c

	// confirmamos el polinimio ingresado
	cout << "\nLa ecuación ingresada es: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

void CuadEqSol::getRoots()
{
	//definimos a, b, c para usar
	float va = a; float vb = b; float vc = c;

	float disc = vb*vb - 4.0*va*vc; //calculamos el discriminante

	// Separamos los casos para raices complejas y reales 
	if(disc < 0) //raices complejas
	{
		float Realr = -vb/(2.0*va); //calculamos la parte real
		float Compr = pow(abs(disc), 0.5)/(2.0*va); //calculamos la parte imaginaria

		cout << "Las raices son complejas: " << endl;
		cout << roundf(Realr * 100) / 100 << " ± " << roundf(Compr * 100) / 100 << "i"<< endl;
	}

	else if(disc >= 0) //raices reales
	{
		float r1 = (-vb+pow(disc, 0.5))/(2.0*va); //calculamos raiz 1
		float r2 = (-vb-pow(disc, 0.5))/(2.0*va); //calculamos raiz 2

		cout << "Las raices son reales: " << endl;
		cout << roundf(r1 * 100) / 100 << " y " << roundf(r2 * 100) / 100 << endl;
	}

}










