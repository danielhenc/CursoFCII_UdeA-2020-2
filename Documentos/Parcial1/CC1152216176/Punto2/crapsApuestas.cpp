#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//Funcion craps identica a la del programa craps.cpp con la diferencia de que cuando el jugador gana retorna un +1 y cuando pierde un -1
int craps()
{
	//Definicion de variables
	int total = 0;
	int dado1;
	int dado2;
	int punto;

	//Mensaje del primer lanzamiento
	cout << "-------------------------------\n";
	cout << "Primer lanzamiento\n";
	dado1 = 1 + rand() % 6;
	dado2 = 1 + rand() % 6;

	//Imprimir la imagen de los dados obtenidos
	if(dado1 == 1) cout << "\u2680 ";
	else if(dado1 == 2) cout << "\u2681 ";
	else if(dado1 == 3) cout << "\u2682 ";
	else if(dado1 == 4) cout << "\u2683 ";
	else if(dado1 == 5) cout << "\u2684 ";
	else if(dado1 == 6) cout << "\u2685 ";

	if(dado2 == 1) cout << "\u2680\n";
	else if(dado2 == 2) cout << "\u2681\n";
	else if(dado2 == 3) cout << "\u2682\n";
	else if(dado2 == 4) cout << "\u2683\n";
	else if(dado2 == 5) cout << "\u2684\n";
	else if(dado2 == 6) cout << "\u2685\n";

	total = dado1 + dado2;

	cout << "Total: " << total << "\n";

	//Ganar en el primer lazamiento
	if(total == 7 or total == 11)
	{
		cout << "¡Tenemos un ganador!\n\n";
		return 1;
	}

	//Perder en el primer lanzaiento
	else if(total == 2 or total == 3 or total == 12)
	{
		cout << "¡CRAPS! \nLa casa gana mejor suerte para la proxima\n\n";
		return -1;
	}

	else
	{
		//Definir el punto
		punto = total;
		total = 0;

		cout << "El punto es " << punto << "\n";

		//Realizar lanzamientos hasta que caiga 7 o el punto
		while(total != punto and total != 7)
		{
			cout << "-------------------------------\n";
			cout << "Siguiente lanzamiento\n";
			dado1 = 1 + rand() % 6;
			dado2 = 1 + rand() % 6;

			if(dado1 == 1) cout << "\u2680 ";
			else if(dado1 == 2) cout << "\u2681 ";
			else if(dado1 == 3) cout << "\u2682 ";
			else if(dado1 == 4) cout << "\u2683 ";
			else if(dado1 == 5) cout << "\u2684 ";
			else if(dado1 == 6) cout << "\u2685 ";

			if(dado2 == 1) cout << "\u2680\n";
			else if(dado2 == 2) cout << "\u2681\n";
			else if(dado2 == 3) cout << "\u2682\n";
			else if(dado2 == 4) cout << "\u2683\n";
			else if(dado2 == 5) cout << "\u2684\n";
			else if(dado2 == 6) cout << "\u2685\n";

			total = dado1 + dado2;

			//Imprimir mensaje si cae el punto
			if(total == punto)
			{
				cout << "Total: " << total << " ¡Tenemos un ganador!\n\n";
				return 1;
			}

			//Imprimir mensaje si cae 7
			else if(total == 7)
			{
				cout << "Total: " << total << " La casa gana mejor suerte para la proxima\n\n";
				return -1;
			}

			else
			{
				cout << "Total: " << total << " es diferente del punto " << punto << "\n\n";
			}
		}
	}
}

int main()
{
	//Definicion de variables
	int saldo = 1000000;
	int jugar = 1;
	int resultado;
	int menu;
	int apuesta;

	srand(time(NULL));

	//Mensaje de bienvenida
	cout << "  Bienbenido al juego Craps\n";
	cout << "-------------------------------\n";
	cout << "      ____\n";
	cout << "     /\\' .\\    _____\n";
	cout << "    /: \\___\\  / .  /\\\n";
	cout << "    \\' / . / /____/..\\\n";
	cout << "     \\/___/  \\'  '\\  /\n";
	cout << "              \\'__'\\/\n";
	cout << "-------------------------------\n";
	//Menu
	cout << "Menu: ingrese la opcion deseada\n";
	cout << "1. Jugar\n2. Reglas\n3. Salir\n";
	cin >> menu;

	//Ciclo para jugas hasta que se desee salir del juego
	while(jugar == 1)
	{
		//Seleccion 1. del menu
		if(menu == 1)
		{
			//Si el saldo es 0 no se puede seguir jugando
			if(saldo == 0)
			{
				cout << "Parece que usted se ha quedado sin saldo en su cuenta, mejor suerte para la próxima\n";
				jugar = 0;
			}

			//Realizar una apuesta
			else
			{
				if(saldo < 100000) cout << "Parece que hoy no estamos de suerte\n\n";
				else if(saldo > 5000000) cout << "Que buena racha!\n\n";

				cout << "Su saldo en este momento es de " << saldo << ", ingrese la cantidad que desea apostar\nApuesta: ";
				cin >> apuesta;

				//Mientras la apuesta supere el saldo o sea negativa repetir este mensaje
				while(apuesta > saldo or apuesta < 0)
				{
					cout << "Parece que usted no cuenta con suficiente saldo en su cuenta, ingrese la cantidad que desea apostar\nApuesta: ";
					cin >> apuesta;
				}

				//Si la apuesta es posible aplicar la funcion del juego y calcular el nuevo saldo
				saldo += craps()*apuesta;

				cout << "Su saldo ectual es de: " << saldo << "\n";
				cout << "0. Salir\n1. Jugar de nuevo\n";
				cin >> jugar;				
			}
		}

		//Seleccion 2. del menu
		else if(menu == 2)
		{
			cout << 	"El jugador tira dos dados de seis caras\nSi la suma de estos es 7 u 11 en el primer lanzamiento,el jugador gana.\nSi la suma es 2, 3 o 12 el jugador pierde.\nSi la suma es 4, 5, 6, 8, 9 o 10, esta suma se convierte en el “punto” del jugador,\npara ganar el jugador debe seguir tirando los dados hasta que salga otra vez su “punto”.\nEl jugador pierde si tira un 7 antes de llegar a su punto.\n\n";
			cout << "1. Jugar\n2. Reglas\n3. Salir\n";
			cin >> menu;
		}		

		//Seleccion 3. del menu
		else if(menu == 3) jugar = 0;

		//Mensaje si se ingresa un valor no valido en el menu
		else
		{
			cout << "por favor ingrese un valor valido\n\n";
			cout << "1. Jugar\n2. Reglas\n3. Salir\n";
			cin >> menu;
		}
	}
	
	return(0);
}
