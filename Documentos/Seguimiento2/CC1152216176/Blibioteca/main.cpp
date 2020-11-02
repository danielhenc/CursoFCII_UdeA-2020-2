#include "entFrac.cpp"
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace entFrac;
using namespace std;

int main()
{
	//Inicializar el numero para probar las funciones
	float num;
	//Se utiliza un numero aleatorio para testear las funciones con diferentes numeros sin tener que compilar el codigo varias veces
	srand(time(NULL));
	//Se obtiene un numero aleatorio entre 0 y 100 con 4 cifras decimales
	num = (rand() % 1000000)/10000.;
	//Se imprime el valor de prueva y el resultado obtenido por las funciones definidas
	cout << "El numero original es: " << fixed << setprecision(4) << num << "\n";
	cout << "Su parte entera es: " << fixed << setprecision(4) << entero(num) << "\n";
	cout << "Su parte decimal es: " << fixed << setprecision(4) << fraccion(num) << "\n";
	/*A la hora de imprimir los resultados se debe tener cuidado con la precision de los resultados ya que la parte decimal puede
	presentar errores en las ultimas cifras si se tiene una precision muy alta*/
	return(0);
}
