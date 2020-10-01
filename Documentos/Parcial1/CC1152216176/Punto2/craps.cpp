#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
 
int main()
{
	//Definicion de variables
	int dado1;
	int dado2;
	int punto;
	int total = 0;
	int jugar = 1;
	int menu;

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
			}

			//Perder en el primer lanzaiento
			else if(total == 2 or total == 3 or total == 12)
			{
				cout << "¡CRAPS! \nLa casa gana mejor suerte para la proxima\n\n";
				cout << "0. Salir\n1. Jugar de nuevo\n";
				cin >> jugar;
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
					if(total == punto) cout << "Total: " << total << " ¡Tenemos un ganador!\n\n";

					//Imprimir mensaje si cae 7
					else if(total == 7) cout << "Total: " << total << " La casa gana mejor suerte para la proxima\n\n";

					else cout << "Total: " << total << " es diferente del punto " << punto << "\n\n";
				}
			}

			//Menu para seguir juagando o salir
			cout << "0. Salir\n1. Jugar de nuevo\n";
			cin >> jugar;
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
