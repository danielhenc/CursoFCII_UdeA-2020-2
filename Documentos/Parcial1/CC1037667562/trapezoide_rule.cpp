/*
Implementación de la regla del trapezoide de paneles iguales para integración de funciones 
por defecto se calcula el area bajo la curva de f(x) = x^2
si desea cambiar la función, modifique usersFunct
los otros parametros como la precisión y los límites de integración son ingresados
por el usuario durante la ejecución del código. 
*/ 

#include <iostream>
#include <cmath>

using namespace std;

//Declarar primero los prototipos
int getPrecision( void ); //obtener precision que quiere el usuario
float getLowLim( void ); //obtener límite inferior
float getUpLim( void ); //obtener limite superior
float usersFunct( float ); //función a la cual se le calcula la integral
float TrapRule( void ); //regla del trapezoide


//Luego el main
int main()
{
	float estInt;

	cout << "Bienvenido! \neste programa calcula integrales por la regla del trapezoide" << endl;
	cout << "Debe ingresar los límites de integración [a,b] (tal que a<b) y la precisión" << endl;
	cout << " " << endl;

	estInt = TrapRule(); //implementa el método

	//imprime el valor de la integral
	cout << "Integral estimada: " << estInt << endl; 

	return 0;
}


//Luego implementa las funciones

float usersFunct(float x) //función que debe modificar el usuario para elegir que quiere integrar
{
	float y = pow(x, 2);

	return y;
}

int getPrecision( void )
{
	int k;
	cout << "Ingrese la precisión (k) con la que desea hacer su cálculo (n = 2^k)" << endl;
	cout << "k es un entero entre 0 y 12. Y, n es el número de paneles" << endl;

	cin >> k; //k que ingresa el usuario

	// verifica que la precisión este dentro del rango
	while( k < 0 || k > 12)
	{
		cout << "Número ingresado fuera del rango \nPor favor ingrese nuevamente k " << endl;
		cin >> k; 
	}

	// informa al usuario la precisión elegida
	cout << "precisión elegida: " << k << " tal que n = " << pow(2, k) << endl;

	return k;
}

float getLowLim( void )
{
	float a;
	cout << "Ingrese límite inferior" << endl;
	cin >> a; //obtiene el límite inferior

	return a;
}

float getUpLim( void )
{
	float b;
	cout << "Ingrese límite superior" << endl;
	cin >> b; //obtiene el límite superior

	return b;
}


float TrapRule( void )
{
	int k; int N; float a; float b; float dx;

	//solicitamos los valores al usuario
	k = getPrecision(); //precision
	a = getLowLim(); //limite inferior
	b = getUpLim(); //limite superior
	N = pow(2, k); //numero de paneles
	dx = (b-a)/N; //ancho de los paneles

	//calula la suma de todas las areas intermedias 
	float suma = 0; float xp; float Tr;
	for ( int i=1; i<N; i++ )
	{
		xp = a + i*dx;
		suma += usersFunct(xp);
	}

	//agrega el area de los paneles de los extremos al area intermedia 
	Tr = dx*( suma + 0.5*(usersFunct(b) + usersFunct(a)) );

	return Tr; //devuelve la integral
}

