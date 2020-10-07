/*Punto 3
INTEGRACIÓN NUMÉRICA.Proyecto asociado al parcial uno. Investigue en que consiste la “LA REGLA TRAPEZOIDAL".Cree un programa en c++ para hacer integrales numéricas usando este método.
*/

#include <iostream> 			//Para print y esas cosas xd
#include <cmath>    			//funciones matematicas como sin y pow

using namespace std;  			//no escribir tanto

const float e = 2.71828;  		//Esto por si se quiere integrar e^x

double f( float );        		//Función a integrar
float trap(float, float, int);		//Función trapecios, recibe limite inferior, superior y precisión

double f( float x){			//Función a integrar, si se desea probar con x^2 o e^x comentar y descomentar las lineas respectivas.
	return sin(x);
//	return x*x;
// 	return pow(e,x);
		}

//La fórmula que se programa a continuación se tomó del libro guía "C++ para ingeniería y ciencias" en la sección 14.6.

float trap(float a,float b, int n){
	float Tk = 0.5*( f(a) + f(b) )*(b-a);  
	for(int k = 0; k <= n; k++){
		float  suma = 0;
		float dx = ( (b-a)/pow(2,k) );
		for (int i = 0; i <= pow(2,k)-1; i++){
			if (i%2 != 0){
			suma = suma + f( a + i*dx );
				      }
				    }
		Tk = 0.5*Tk + dx*suma;
			   }
	return Tk;
	     }

int main()
{

cout << "\nBuenas buenas, vamos a integrar f(x) = sin(x) pues, ingresame el limite inferior, superior y la precisión respectivamente porfa. \nCuidado con la precisión eh, puede que se demore un rato si abusas de ella.\n" << endl;

float a1,b1,n1; //Variables que el usuario ingresará.

cout <<"Limite inferior: ";
cin >> a1;
cout<<"Limite superior: ";
cin>>b1;
cout<<"Precisión: ";
cin>>n1;

double res;
res = trap(a1,b1,n1);
	cout<<"int_{"<< a1<<"}^{"<<b1<<"} sin(x)dx = "<< res <<endl;

return 0;
}


