///Implementación de la clase/// ImpCuadratica.cpp


#include <iostream>
using namespace std; //Para no escribir demasiado


#include "P1_SolveCuadratica.h" 	//La clase definida ya
	
SolveCuadratica::SolveCuadratica(){	 //El constructor, todo se inicializa en cero. 
  d = 0;
  a = 0;
  b = 0;
  c = 0;
  t1 = 0;
  t2 = 0;
} 

float SolveCuadratica::Tomarctes(){	//Función que recibe las constantes.
 	cout << "\n ingrese el valor de a, b y c respectivamente"<< " \n" << endl;

cout<<"a: ";
cin >> a;
cout<<"b: ";
cin >> b;
cout<<"c: ";
cin >> c;
cout << "Ok, la ecuación a resolver es: "<< a <<"x^2 + ("<<b<<"x) + ("<< c <<") = 0" << endl;
				}


void SolveCuadratica::Solveeq( double a, double b, double c){ //función que resuelve la ecuación

	d = b*b - 4*a*c; //Discriminante: -b^2 -4ac

	//Caso donde el discriminante es mayor, es decir, la solución es real:
	if (d>=0){
		x1 = (-b + sqrt(d) )/(2*a);			//Simplemente la fórmula del estudiante
		x2 = (-b - sqrt(d) )/(2*a);			//Solución 2
		cout<<"x1 = "<< setprecision(2) << x1 <<endl;	//Setprecision para los decimales
		cout<<"x2 = "<< setprecision(2) << x2 << endl;
		}

	//Caso donde el discriminante es menor, es decir la función es imaginaria:
	else if (d<0){
		//Como aquí hay imaginarios, entonces separamos en parte real y parte imaginaria
		float t1 = -b/(2*a);		//Término parte real
		float t2 = sqrt(-d)/(2*a);	//Termino parte imaginaria
		
		cout<<"x1 = "<< setprecision(2) << t1 <<" + i" << setprecision(2) << t2 << endl;
		cout<<"x2 = "<< setprecision(2) << t1 <<" - i" << setprecision(2) << t2 << endl;
			}

	//Otro caso por si algo.
	else{ cout<<"WTFFFF, El algoritmo no debió haber llegado aquí" << endl;}

								}

void SolveCuadratica::Resultado(){	//Función para mostra el resultado y discriminar algunos posibles casos
  Tomarctes();
	//Caso donde a=0, es decir, una ecuación lineal
  if (a==0 and b!=0){
	cout<<"Esto es un solucionador de ecuaciones cuadráticas. Si a=0 significa que no tienes una ecuación de este tipo."<<endl;
	cout<<"Igual como es facil te la pongo, la solución a tu ECUACIÓN LINEAL es: x= "<< setprecision(2) << (-c/b) << "\n" <<endl;
	  }
	//Caso donde ni siquiera tenemos una ecuación a resolver
  else if (a==0 and b ==0){
	cout<<"Esto es un solucionador de ecuaciones cuadráticas. Si a=0 significa que no tienes una ecuación de este tipo."<<endl;
	cout<<"Ey, eso qué? tenés "<< c << " = "<< "0" <<endl;
			}
	//Caso donde si tenemos una ecuación cuadrática:
  else{
  Solveeq(a,b,c);}
				  }	//Fin de la implementación.
