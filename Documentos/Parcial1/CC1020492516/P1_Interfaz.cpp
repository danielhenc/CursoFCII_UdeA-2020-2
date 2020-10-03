// ### Main ### ///  Interfaz.cpp

#include "P1_SolveCuadratica.h" // incluye la definición de la clase Exponencial

int main(){

char r;		//Centinela.
cout<<" Primero que todo buenas tardes. ¿Desea resolver una ecuación del tipo ax^2 + bx + c = 0 ? (y o n)"<<endl;
cin >> r;
SolveCuadratica Cuadratica1;	//Llamamos nuestra clase
while(r == 'y'){
  Cuadratica1.Resultado();	//Solo tenemos que llamar la función resultado, ella llamará a las demás.
  cout<<" ¿Desea resolver otra ecuación cuadrática? (y o n)"<<endl;
  cin >> r;}
  return 0; 
	   } // :)
