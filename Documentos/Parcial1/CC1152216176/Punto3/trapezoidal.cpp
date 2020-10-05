#include<iostream>
#include<cmath>

using namespace std;

//Funcion a integrar
float func(float x)
{
	//Ingrese la funcion que desea integrar con veriable x
	//return();

	//Funciones de prueva
	//return(x*x);
	//return(exp(x));
	return(sqrt(x));
}

//Funcion para calcular la integral
float trap(float a,float b,int N)
{
	//Definicion de variables
	float r = 0;
	float delta;

	//Calculo del tamaño de los intervalos en x
	delta = (b-a)/N;

	for( int i = 0; i < N; i++ )
	{
		//Area de cada trapecio
		r += 0.5*delta*(func(a + i*delta) + func(a + (i+1)*delta));
	}
	return r;
}

int main()
{
	int N;
	float a;
	float b;

	cout << "Ingrese los limites de la integral\na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	while(a > b)
	{
		cout <<"Por favor ingrese los limites de forma que a < b\na: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	}

	cout << "Ingrese la cantidad de intervalos a usar en la integral\nN: ";
	cin >> N;

	cout << "la integral es " << trap(a,b,N) << "\n";
}
