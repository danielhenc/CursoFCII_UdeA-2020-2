#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
  //punto a.
  
	cout << "Hey, ¿Jugamos Craps o miedo?" << endl;

	srand(time(NULL));
	int dado1, dado2, suma, puntos;
	char y;

	cout << "Introduce 'Y' y enter para jugar" << endl;
	cin >> y;  

	dado1 = 1 + rand()%6;  // generamos números aleatorios entre 1 y 6 tal como lo hicimos en el trabajo anterior
	dado2 = 1 + rand()%6;
	suma = dado1 + dado2;

	if( suma==7 or suma==11 ) // condiciones para que el usuario gane
	  {  
		cout << "La suma de las caras fue: " << suma;
		cout << " Ganaste papá" << endl;
		return 0;
	}
	else if( suma==2 or suma==3 or suma==12 ) // condiciones para que el usuario pierda
	  {  
		cout << "La suma de las caras fue: " << suma;
		cout << " Craps! gana la casa" << endl;
		return 0;
	}
	else // si el usuario saca 4,5,6,8,9 o 10, entonces debe tirar nuevamente
	  {  
		cout << "Obtuviste un punto" << "\n";

		puntos = suma;  // punto obtenido por el usuario
		while( suma!=7)
		  {
		    cout << "Tu punto fue: " << suma << endl;
		    cout << "Debes tirar tu punto otra vez para ganar" << endl;
		    cout << "Introduce 'Y' y enter para tirar los dados nuevamente" << endl;
		    cin >> y;
		    dado1 = 1 + rand()%6;
		    dado2 = 1 + rand()%6;
		    suma = dado1 + dado2;

		    if( suma==puntos ) //caso en el que el usuario gane nuevamente
		      {  
		        cout << "La suma de las caras fue: " << suma;
	       		cout << " Ganaste papá!" << endl;
			return 0;
		      }
		    else if( suma==7 ) //caso en el que el usuario pierde
		      {
			cout << "La suma de las caras fue: " << suma;
			cout << " Craps! perdiste" << endl;
			return 0;
		      }

		}
		    
		
	}
} 
