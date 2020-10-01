/**
 * Se prueba el metodo del trapezoide para integrar
 * un funcion de prueba 1/x con limites de 1 a 2
 * y se llega a una precision tal que se generan 2^7 trapezoides.
 * 
 * @note La libreria trapezoide.h solo realiza la implementacion
 *		 del metodo trapezoide y aun no esta programada para recibir
 *		 funciones especiales, si desea probar con una funcion 
 *		 diferente para integrar puede cambiar el método de la clase
 *		 MetodoTrapezoide llamado Funcion. 
 *		 Y los otros atributos para la integracion deben de ser ingresados
 *       desde este programa, cuando se define la clase.
 *		 
 * @author Valentina Roquemen Echeverry
 */

#include "trapezoide.h" 

int main()
{
	float lim_inf = 1., lim_sup = 2.;
	int k = 7;

	MetodoTrapezoide myIntegral(lim_inf,lim_sup,k);

	myIntegral.imprimirResultados();

	return 0; 
} 