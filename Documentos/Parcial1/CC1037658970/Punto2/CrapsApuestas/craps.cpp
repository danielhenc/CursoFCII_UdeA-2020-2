/**
 * @author Valentina Roquemen Echeverry
 * @brief  Se diseña un a clase para que el usuario
 *         juegue el famoso juego de casino: Craps
 */

#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include "craps.h"

using namespace std;

Craps::Craps()
{
	srand(time(NULL));

}

void Craps::reglasJuego()
{
	cout<<"\n Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros.\n";
	cout<<"Una vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores.\n";
	cout<<" - Si la suma es 7 u 11 en el primer tiro, el jugador gana.\n";
	cout<<" - Si la suma es 2, 3 o 12 en el primer tiro (llamado Craps), el jugador pierde.\n";
	cout<<" - Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se convierte en el punto del jugador.\n"; 
	cout<<"   Para ganar, el jugador debe seguir tirando los dados hasta que salga otra vez su punto.\n";
	cout<<"   El jugador pierde si tira un 7 antes de llegar a su punto.\n\n";
}

void Craps::apostar()
{
	int i=0;

	while (i==0)
	{
		cout<<"\nIngresa el valor que desea apostar, recuerda que debe de ser menor o igual a "<<SaldoenBanco<<": \n";
		cin>>apuestaValue;
		
		if (!cin.good()) 
		{
        	cin.clear();
			cin.ignore(10000, '\n');
        	apuestaValue = -1;
        	
    	}

		if (apuestaValue>SaldoenBanco)
			cout<<"Crees tener mas dinero del que realmente tienes? \n";
		else if (apuestaValue<0)
			cout<<"Tratas de apostar un valor invalido. \n";
		else if (apuestaValue==0)
			cout<<"Que poco arriesgado! El que no arriesga, no gana. \n";
		else if (apuestaValue<=SaldoenBanco and apuestaValue>=0.7*SaldoenBanco)
		{
			cout<<"Alguien se siente suertudo hoy. \n\n";
			i = 1;
		}
		else if (apuestaValue>0 and apuestaValue<0.7*SaldoenBanco)
		{
			cout<<"La prudencia es un don que no todos poseen. Suerte. \n\n";
			i = 1;
		}

	}
	cin.clear();
	cin.ignore(10000, '\n');
}

void Craps::lanzamiento()
{
	char lanza;

	cout<<"Oprime cualquier tecla para lanzar los dados\n";
	cin>>lanza;
	cin.clear();
	cin.ignore(10000, '\n');

	dice1 = (1+rand()%6);
	dice2 = (1+rand()%6);
	sum = dice1+dice2;

	cout<<"Obtuviste un: "<<sum<<"\n";
}

void Craps::resultadoApuesta(bool win)
{
	if (win)
		SaldoenBanco += apuestaValue;
	else
		SaldoenBanco -= apuestaValue;

}

void Craps::play()
{
	cin.clear();
	cin.ignore(10000, '\n');
	apostar();
	lanzamiento();
	if (sum==7 or sum==11)
	{
		cout<<"Ganaste!\n";
		resultadoApuesta(true);
	}

	else if (sum==2 or sum==3 or sum==12)
	{
		cout<<"Craps! Perdiste!\n";
		resultadoApuesta(false);

	}
	
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
				resultadoApuesta(false);
			}
			else if(sum==sum_copy)
			{
				cout<<"Ganaste!\n";
				sum=0;
				resultadoApuesta(true);
			}
		}
	}	
}

void Craps::mainMenu()
{
	char choose='1';

	while(choose!='4')
	{
		cout<<"--------------------------------------------\n";
		cout<<"--------------------------------------------\n";

		cout<<"¿Quieres jugar un juego? (elige una opcion)\n";
		cout<<"1. Deseas jugar.\n";
		cout<<"2. Deseas salir de aca.\n";
		cout<<"3. Deseas conocer las reglas del juego.\n";
		cin>>choose;
		cout<<"--------------------------------------------\n";
		cout<<"--------------------------------------------\n";

		switch (choose)
		{
			case '1':
				if(SaldoenBanco>0)
				{
					cout<<"Vamos a jugar Craps!\n";	
					play();
					cout<<"Su saldo en el banco es de "<<SaldoenBanco<<" de pesos\n\n";
				}
				else
				{
					cout<<"Saldo insuficiente, vuelve en otra ocasion\n";
					choose='4';
				}
				break;

		    case '2':
				cout<<"Puedes cambiar tus fichas por "<<SaldoenBanco<<" pesos.\n";
				cout<<"Espero que juguemos en otra ocasion\n";
				choose='4';
				break;
			case '3':
				reglasJuego();
				break;

			default:
				cout<<"Por favor ingresa una opcion valida\n";

		}

	
	}
}	
	