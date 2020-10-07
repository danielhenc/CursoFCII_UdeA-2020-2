#include <iostream> //se incluyen las librerías necesarias
#include <cmath>
#include <iomanip>

using namespace std;

#include "raices.h" //se llama la clase

Raices::Raices(){ //constructor
    a, b, c = 0.0;
};

void Raices::asignar_datos(float A, float B, float C){ 
	a= 1.0*A; //los datos ingresados se multiplican por 1.0 para garantizar que sean float
	b= 1.0*B;
	c= 1.0*C;
	}

double Raices::calcular_raices(){
	float determinante, p1, p2;
	determinante= pow(b, 2) - 4.0*a*c; //para saber si la raíz es compleja o no
	p1= -b/(2.0*a); //primera parte de la raíz
	p2= sqrt(abs(determinante))/(2.0*a); //segunda parte de la raíz
	if (determinante < 0.0) //para imprimir las raíces complejas
		cout << "Las raíces son: x1= " << fixed << setprecision(2) << p1 << "+i" << p2 << endl
		<< setw(20) << "x2= " << fixed << setprecision(2) << p1 << "-i" << p2 << endl;
	else //para imprimir las raíces reales
		cout << "Las raíces son: x1= " << fixed << setprecision(2) << p1 + p2 << endl
		<< setw(20) << "x2= " << fixed << setprecision(2) << p1 - p2 << endl;
}
