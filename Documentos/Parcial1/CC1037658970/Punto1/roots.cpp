/**
 * Programa que realiza la prueba del calculo de las raices
 * de una funcion cuadratica.
 * @author Valentina Roquemen Echeverry
 */

#include "math2.h" 

int main()
{
	/***Ejemplo para parametros que dan raices reales***/
	float arregloParametros1[Roots::parametros] = {3,5,-2.3};
	Roots calculoRaices1(arregloParametros1);

	calculoRaices1.imprimirResultados();

	/***Ejemplo para parametros que dan raices complejas***/
	float arregloParametros2[Roots::parametros] = {3,1,7};
	Roots calculoRaices2(arregloParametros2);

	calculoRaices2.imprimirResultados();

	return 0; 
} 