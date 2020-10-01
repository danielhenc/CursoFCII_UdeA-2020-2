#include "bcrap.h"

bcraps_game::bcraps_game(){
	int dado_1, dado_2, player_sum, banco, plays, apuesta;
	bool next_move;

	set_values();
	
	srand(time(NULL));

	std::cout << "**********CRAP GAME**********" << std::endl;
	std::cout << "       _____    _____        " << std::endl;
	std::cout << "      /___ /|  /___ /|       " << std::endl;
	std::cout << "     | .. | | |... | |       " << std::endl;
	std::cout << "     |____|/  |____|/        " << std::endl;
	std::cout << "*****************************" << std::endl;
}

void bcraps_game::set_values(){
	dado_1 = 0;
	dado_2 = 0;
	player_sum = 0;
	banco = 1000000;
	plays = 0;
	apuesta = 0;
	next_move = true;
}

int bcraps_game::throw_dice(){
	/* Función para lanzar un dado */
	return 1 + rand() % 6;
}

void bcraps_game::play(){
	/* Función para jugar el juego*/
	
	char inpt_char; // Opción para decidir si se tiran los dados

	while (next_move){
		/* Se sigue jugando siempre y cuando next_move == true */
		std::cout << "----------------------------------------------------------------" << std::endl;
		advice();
		std::cout << "Para tirar los dados, presione S, para salir presione N: ";
		std::cin >> inpt_char;

		switch (inpt_char){
			case 'S':
				makebeat();
				play_move(apuesta);
				break;

			case 'N':
				std::cout << "> Se ha retirado con un saldo de: " << banco << std::endl;
				next_move = false;
				break;

			default:
				std::cout << ">> Opción inválida" << std::endl;
		}
	}

}

void bcraps_game::makebeat(){
	std::cout << "El saldo en el banco es: " << banco << std::endl;
	std::cout << "> Ingrese una apuesta menor o igual al saldo en banco: ";
	std::cin >> apuesta;
	
	while (apuesta > banco){
		std::cout << ">>> OJO: no puede apostar más de lo que ya tiene" << std::endl;
		std::cout << "> Ingrese un nuevo valor menor o igual a su saldo en banco: ";
		std::cin >> apuesta;
	}
}

void bcraps_game::play_move(int apuesta){
	/* Función para jugar un turno */

	dado_1 = throw_dice();
	dado_2 = throw_dice();

	plays += 1;

	std::cout << "Se tiraron los dados: " << dado_1 << " " << dado_2 << std::endl;

	if (player_sum == 0){
		/* Cuando se comienza un juego nuevo, lst_punto=0 y se entra en las 
           condiciones para el primer tiro */
		
		int p_sum = dado_1 + dado_2;
	
		if ((player_sum == 7) || (player_sum == 11)){
			/* Condición para ganar en el primer tiro */
			std::cout << "***** HA GANADO *****" << std::endl;
			std::cout << "> Tire de nuevo para determinar su punto" << std::endl;
			win();
		}
		else if ((player_sum == 2) || (player_sum == 3) || (player_sum == 12)){
			/* Condición para perder en el primer tiro */
			std::cout << "***** CRAP: HA PERDIDO *****" << std::endl;
			std::cout << "Su punto es: " << p_sum << std::endl;
			player_sum = p_sum;
			lose();
		}
		else {
			/* Si no se cumplen las condiciones anteriores, se guarda el punto y se sigue jugando */
			std::cout << "Su punto es: " << p_sum << std::endl;
			player_sum = p_sum;
			nothing();	
		}
	} 
	else{
		int d_sum = dado_1 + dado_2;
		std::cout << "La suma de esta movida fue: " << d_sum  << std::endl;

		if (d_sum == 7){
			/* Condición para perder luego del primer tiro */ 
			std::cout << "Su punto es: " << player_sum << std::endl;
			std::cout << "***** CRAP: HA PERDIDO *****" << std::endl;
			lose();
		}
		else if (d_sum == player_sum){
			/* Condición para ganar luego del primer tiro (si la suma de los dados es igual al punto) */
			std::cout << "Su punto es: " << player_sum << std::endl;
			std::cout << "***** HA GANADO *****" << std::endl;
			win();
		}
		else{
			/* Si no se cumple ninguna de las condiciones anteriores, se sigue jugando */
			std::cout << "Su punto es: " << player_sum << std::endl;
			nothing();
		}
	}
}

void bcraps_game::win(){
	/* Se ejecuta si se gana la apuesta */
	std::cout << "> Felicidades, ha gando la apuesta" << std::endl;
	banco += apuesta;
	std::cout << "> Su saldo en banco es: " << banco << std::endl; 
}

void bcraps_game::lose(){
	/* Se ejecuta si se pierde la apuesta */
	std::cout << "> Lo siento, ha perdido su apuesta" << std::endl;
	banco -= apuesta;
	if (banco > 0){
		std::cout << "> Su saldo en banco es: " << banco << std::endl; 
	}
	else{
		std::cout << "> Desgraciadamente ha perdido todo su dinero. Compre más fichas" << std::endl;
		play_again();
	}
}

void bcraps_game::nothing(){
	/* Se ejecuta si no se pierde ni se gana */
	std::cout << "> No pasa nada, siga tranquilo" << std::endl;
	std::cout << "> Su saldo en banco es: " << banco << std::endl; 
}

void bcraps_game::advice(){
	switch (plays){
		case 5:
			std::cout << "CONSEJO: ";
			if (banco < 100000){
				std::cout << "~Esto se ve mal, es mejor que se retire~" << std::endl;
			}
			else if (banco > 100000 && banco < 1000000){
				std::cout << "~Todo parece en equilibrio, continúe a discreción~" << std::endl;
			}
			else{
				std::cout << "~¿Y si se arriesga un poco más?~" << std::endl;
			}
			break;
		
		case 15:
			std::cout << "CONSEJO: ";
			if (banco < 100000){
				std::cout << "~¿Sigue acá? Va a quedar en la ruina~" << std::endl;
			}
			else if (banco > 100000 && banco < 1000000){
				std::cout << "~No va a ganar nada más, es mejor retirarse~" << std::endl;
			}
			else{
				std::cout << "~Ganar demasiado a la casa es perjudicial para la salud~" << std::endl;
			}
			break;
	}

	if (((plays % 5 == 0 && plays != 5) && plays != 15) && plays > 0){
		std::cout << "CONSEJO: ";
		if (banco < 100000){
			std::cout << "~¿No ha perdido ya bastante? ¡Retírese!~" << std::endl;
		}
		else if (banco > 100000 && banco < 1000000){
			std::cout << "~Ha jugado a la segura, es el momento de arriesgarse~" << std::endl;
		}
		else{
			std::cout << "~Ganar demasiado a la casa es perjudicial para la salud~" << std::endl;
		}
	}
}


void bcraps_game::play_again(){
	/* Función que se ejecuta luego de haber perdido o ganado. Pregunta si se desa jugar nuevamente */
	char pag; // Opción para saber si se juega de nuevo
	
	std::cout << "¿Desea jugar de nuevo? [S/N]: ";
	std::cin >> pag;

	switch (pag){
		case 'S':
			/* Se reinician los valores para una nueva partida */
			std::cout << " *************************************************************** " << std::endl;
			std::cout << " -------            Iniciando un nuevo juego             ------- " << std::endl;
			set_values();
			break;
	
		case 'N':
			next_move = false;
			break;

		default:
			std::cout << "> Opvión inválida, saliendo de todas maneras" << std::endl;
			next_move = false;
	}
}
