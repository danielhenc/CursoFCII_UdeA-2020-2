/*
Espacio de nombres con las funciones entero y partefracc
*/

#include <iostream>
#include <cmath>

using namespace std; 

namespace partesNum
{
	int entero( float num ) //función parte entera
	{
		int num_int = num;

		return num_int; 
	}

	float partefracc( float num ) //función parte fraccionaria
	{
		int entero( float ); //prototipo

		int parteint; float pfracc;

		parteint = entero( num );
		pfracc = abs(num - parteint); 

		return pfracc;
	}
} // fin namespace
