#include <iostream> //se incluyen las librerías necesarias
#include <cmath>
#include <iomanip>

// programa para integrar funciones por el método trapezoidal

using namespace std;

//aquí se define la función Fx que se quiere integrar:

float funcion(float x){ 
	float Fx;
	Fx= exp(x);
	return Fx;
	}


int main() { 
	float a, b, n, h, FX; //se inicializan las variables
	cout << "Ingrese el intervalo inferior a, el superior b, y el número n de trapecios \n";
	cin >> a >> b >> n;

	if (n > 3){
		float sum= 0.0;
		h= (b - a)/n; //se define el ancho del trapecio
		sum= funcion(a); //se inicia la suma en el límite inferior
		for (int i =1; i <= n - 1; i++){ //para calcular los trapecios consecutivos
			sum= sum + 2*funcion(h*i);
			}
		sum= sum + funcion(b); //la suma finaliza en el límite superior
		FX= h* sum/2; //valor de la integral
		}
	else {
		cout << "El número de trapecios debe ser mayor,no se puede calcular la integral" << endl;
		}
	cout << "El resultado de la integral es:" << FX << endl;

	return 0;
	}

