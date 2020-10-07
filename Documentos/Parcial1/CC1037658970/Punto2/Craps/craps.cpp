/**
 * @author Valentina Roquemen Echeverry
 * @brief  Se diseña un a clase para que el usuario
 *         juegue el famoso juego de casino: Craps
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "craps.h"

using namespace std;

Craps::Craps()
{
	srand(time(NULL));

}

void Craps::lanzamiento()
{
	char lanza;

	cout<<"Oprime cualquier tecla para lanzar los dados\n";
	cin>>lanza;

	dice1 = (1+rand()%6);
	dice2 = (1+rand()%6);
	sum = dice1+dice2;

	cout<<"Obtuviste un: "<<sum<<"\n";
}

void Craps::play()
{
	lanzamiento();
	if (sum==7 or sum==11)
		cout<<"Ganaste!\n";

	else if (sum==2 or sum==3 or sum==12)
		cout<<"Craps! Perdiste!\n";
	
	else if (sum==4 or sum==5 or sum==6 or sum==8 or sum==9 or sum==10)
	{
		int sum_copy=sum;
		cout<<"Punto!\n";
		while(sum!=0)
		{
			lanzamiento();
			if(sum==7)
			{
				cout<<"Perdiste!\n";
				sum=0;
			}
			else if(sum==sum_copy)
			{
				cout<<"Ganaste!\n";
				sum=0;
			}
		}
	}	
}

void Craps::mainMenu()
{
	char choose='1';

	while(choose!='2')
	{
		cout<<"--------------------------------------------\n";
		cout<<"--------------------------------------------\n";

		cout<<"¿Quieres jugar un juego? (elige una opcion)\n";
		cout<<"1. Deseas jugar.\n";
		cout<<"2. Deseas salir de aca.\n";
		cin>>choose;
		cout<<"--------------------------------------------\n";
		cout<<"--------------------------------------------\n";

		if(choose=='1')
		{
			cout<<"Vamos a jugar Craps!\n";	
			play();
		}
		else if(choose=='2')
			cout<<"Espero que juguemos en otra ocasion\n";
		
		else
			cout<<"Por favor da una opcion valida\n";
	}
}