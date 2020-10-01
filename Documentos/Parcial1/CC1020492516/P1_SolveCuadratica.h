/* Primer punto del parcial:
Una ecuación cuadrática es una ecuación que tiene la forma ax^2+bx+co que puede mani-pularse en forma algebraica en esta forma. En esta ecuaciónxes la variable desconocida, ya,bycson constantes conocidas. Escriba un programa en C++ para resolver las raíces de unaecuación cuadrática. Despliegue las raíces con dos cifras decimales (las soluciones puedenser un numero complejo ).nota: Usando las técnicas de programación orientada a objetos (POO) que hemos estudiado,cree una clase que nos devuelva las raíces. */


// ### Definición de clase ### // SolveCuadratica.h

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class SolveCuadratica
{
public:
	float x1 = 0; 			//Solución 1
	float x2 = 0; 			//Solución 2
SolveCuadratica(); 			// el constructor que inicializará las variables
float Tomarctes(); 			//Función que recibirá las entradas a,b,c
void Solveeq( double, double, double ); //Función que resolverá la ecuación
void Resultado(); 			// Función que mostrará el resultado

private:				//Estas variables privadas las podemos usar por todo el código.
	float a;
	float b;
	float c;
float d; 				// El discriminante no lo necesita el usuario para nada. 
float t1; 				//Para las soluciones complejas albergamos termino 1 y termino 2
float t2;
}; 					// fin de la clase


