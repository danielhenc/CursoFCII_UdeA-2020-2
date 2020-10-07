/*
Implementación de la clase CRAPSgame 
*/

#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "craps.h"

using namespace std;

CRAPSgame::CRAPSgame( void )
{
	srand( time( NULL ) ); //semilla que se corre solo una vez
	beginGame();
}

void CRAPSgame::beginGame( void )
{
	SaldoenBanco = 1000000; //inicializa el saldo en banco
	nTiro = 0; //inicializa el número de tiros
	userPunto = 0; // inicializa punto de usuario
	char a1; //definimos respuesta 1

	cout << "¡Bienvenido al juego CRAPS!" << endl;
	cout << "\nSu partida empieza con un saldo de " << SaldoenBanco << endl;
	cout << "¿desea conocer las reglas? (y/n)" << endl;

	//pregunta si el usuario quiere ver las reglas y la respuesta debe ser 'y' o 'n' 
	cin >> a1;

	if( a1 == 'y' ) //si es 'y', las muestra
	{
		cout << "Se tiran dos dados de seis caras y la suma de estos determina sus puntos \n"
		<< "si en el primer tiro sus puntos son 7 u 11, usted gana. Si son 2, 3, 12 pierde \n"
		<< "Y, si son 4, 5, 6, 8, 9, 10; deberá tirar los dados hasta " 
		<< "que vuelva a sacar el mismo número para ganar. \nPero, CUIDADO, si en esos intentos saca 7, " 
		<< "usted PIERDE" << endl;   
	}
	//en caso contrario no hace nada 

	cout << setprecision(12) << " \n ¡Suerte! \n " << endl;

}

char CRAPSgame::uPlay( void )
{
	//pregunta si el usuario quiere tirar los dados 
	char ap;
	cout << "¿desea tirar los dados? (y/n)" << endl;
	cin >> ap;

	if( ap == 'n')
	{
		continueGame( ap ); // se despide del usuario
	}

	return ap;
}

float CRAPSgame::getApuesta( void )
{
	//pide la apuesta al usuario 
	float apu;
	cout << "ingrese su apuesta (debe ser menor o igual al saldo que tenga en el banco)" << endl;
	cin >> apu;

	//verifica que cumpla con las condiciones dadas
	while(apu > SaldoenBanco || apu < 0)
	{
		cout << "Ingrese su apuesta nuevamente" << endl;
		cin >> apu;
	}

	return apu;
}

int CRAPSgame::Dados( void )
{
	int value;
	int dado1 = 1 + rand() % 6; // tiro aleatorio dado1
	int dado2 = 1 + rand() % 6; // tiro aleatorio dado2

	int puntos = dado1 + dado2; //puntos del usuario

	cout << "Sacó: " << puntos << endl; //muestra el valor de los dados

	if( nTiro == 0 ) //evalua condiciones del primer lanzamiento
	{
		if( puntos == 7 || puntos == 11) 
		{
			value = 1; //gana
		}
		else if( puntos == 2 || puntos == 3 || puntos == 12)
		{
			value = 0; //pierde
		}
		else
		{
			cout << "tu número es " << puntos << " sigue lanzando..." << endl;
			userPunto = puntos; //almacena los puntos del usuario
			value = 2; //sigue intentando
		}	
	}

	else if( nTiro > 0 ) //evalúa condiciones despues del primer lanzamiento
	{
		if( puntos == userPunto)
		{
			value = 1; //gana
		}
		else if( puntos == 7)
		{
			value = 0; //pierde
		}
		else
		{
			cout << "sigue intentando..." << endl;
			value = 2; //sigue intentando 
		}
	}

	return value;
}

void CRAPSgame::toPlay( void )
{
	char keepPlay; float userMoney; int WLoT;
	char at;

	keepPlay = uPlay(); //pregunta si va a tirar los dados

	while(keepPlay == 'y')
	{
		userMoney = getApuesta(); //obtiene la apuesta del usuario
		WLoT = Dados(); //obtiene el valor de los dados 

		if( WLoT == 1 )
		{
			SaldoenBanco += userMoney;
			cout << "¡GANÓ! " << "su nuevo saldo es:" << SaldoenBanco << endl;
			showMessage( WLoT); //mensajes para el usuario
			//pregunta si el usuario quiere seguir jugando
			cout << "¿desea seguir apostando? (y/n)" << endl;
			cin >> at; // respuesta del usuario
			break; //se sale del Loop	
		}
		else if( WLoT == 0 )
		{
			SaldoenBanco -= userMoney;
			cout << "¡PERDIÓ! " << "su nuevo saldo es: " << SaldoenBanco << endl;
			showMessage( WLoT); //mensajes para el usuario

			//si queda en ceros, se sale del juego
			if(SaldoenBanco <= 0 )
			{
				cout << "Lo siento, se ha quedado sin fondos. No puede jugar más" << endl;
				at = 'n';
				break;
			}

			//pregunta si el usuario quiere seguir jugando
			cout << "¿desea seguir apostando? (y/n)" << endl;
			cin >> at; // respuesta del usuario
			break; //se sale del Loop
		}
		else if( WLoT == 2 )
		{
			cout << "Está en un punto muerto, no gana ni pierde" << endl;
			nTiro += 1; //suma al numero de tiros
			showMessage( WLoT);  //mensajes para el usuario
			keepPlay = uPlay();
		}
	}

	continueGame( at ); //evalúa si el usuario quiere seguir jugando

}

void CRAPSgame::continueGame( char aa2 )
{
	// Se despide del usuario si no quiere jugar más
	if( aa2 == 'n')
	{
		cout << "Se ha terminado el juego, su saldo final es: " << SaldoenBanco << endl;
		cout << "Esperamos vuelva pronto" << endl;
	}
	// Corre el juego de nuevo manteniendo el saldo en banco
	else if( aa2 == 'y')
	{
		cout << "¡Qué arriesgado! Sigamos jugando entonces" << endl;
		nTiro = 0;
		toPlay();
	}
}

void CRAPSgame::showMessage( int uM )
{
	//usa el número de tiros, el saldo en banco y si ganó o perdió para hablar con el usuario
	if( SaldoenBanco > 1500000 && uM == 1 )
	{
		cout << "Vea pues, va muy bien! así le puede comprar cositas a la pareja" << endl;
	}
	else if( nTiro > 5 && uM == 2 )
	{
		cout << "He visto pocos perseverar tanto... No sé si felicitarlo o preocuparme " << endl;
	}
	else if( SaldoenBanco < 200000 && uM == 0 )
	{
		cout << "Eso es tener muy mala suerte ¿no cree?" << endl;
	}
	else if( nTiro == 1 && uM == 1)
	{
		cout << "Tiene mucha suerte usted, debería arriegarse y seguir" << endl;
	}
}

