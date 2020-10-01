
/*
Prototitpo de la clase CuadEqSol que halla las raices de un polinomio de segundo grado
de la forma ax^2 + bx + c
*/

class CuadEqSol
{
	public:
		CuadEqSol(); //constructor 
		void inValues(); //función para obtener a, b, c del usuario
		void getRoots(); //función para solucionar el polinomio

	private:
		float a; float b; float c; //coeficiente privados para trabajar con ellos facilmente
};




