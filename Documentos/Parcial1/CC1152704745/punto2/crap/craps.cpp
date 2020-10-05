#include "craps.h"

craps_game::craps_game(){
	int dado_1, dado_2, player_sum;
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

void craps_game::set_values(){
	/* Función para inicializar las variables */
	dado_1 = 0;
	dado_2 = 0;
	player_sum =0;;
	next_move = true;
}

int craps_game::throw_dice(){
	/* Función que representa el lanzamiento de un dado */
	return 1 + rand() % 6; 
}

void craps_game::play_move(int lst_punto = 0){
	/* Función para jugar una movida del juego */
	dado_1 = throw_dice();
	dado_2 = throw_dice();

	std::cout << "Se tiraron los dados: " << dado_1 << " " << dado_2 << std::endl;
	
	if (lst_punto == 0){
		/* Cuando se comienza un juego nuevo, lst_punto=0 y se entra en las 
           condiciones para el primer tiro */
		
		player_sum = dado_1 + dado_2;
	
		if ((player_sum == 7) || (player_sum == 11)){
			/* Condición para ganar en el primer tiro */
			std::cout << "***** HA GANADO *****" << std::endl;
			play_again();
		}
		else if ((player_sum == 2) || (player_sum == 3) || (player_sum == 12)){
			/* Condición para perder en el primer tiro */
			std::cout << "***** CRAP: HA PERDIDO *****" << std::endl;
			play_again();
		}
		else {
			/* Si no se cumplen las condiciones anteriores, se guarda el punto y se sigue jugando */
			std::cout << "Su punto es: " << player_sum << std::endl;
			next_move = true;
		}
	} 
	else{
		int d_sum = dado_1 + dado_2;
		std::cout << "La suma de esta movida fue: " << d_sum  << std::endl;

		if (d_sum == 7){
			/* Condición para perder luego del primer tiro */ 
			std::cout << "***** CRAP: HA PERDIDO *****" << std::endl;
			play_again();
		}
		else if (d_sum == player_sum){
			/* Condición para ganar luego del primer tiro (si la suma de los dados es igual al punto) */
			std::cout << "***** HA GANADO *****" << std::endl;
			play_again();
		}
		else{
			/* Si no se cumple ninguna de las condiciones anteriores, se sigue jugando */
			std::cout << "Su punto es: " << player_sum << std::endl;
			next_move = true;
		}
	}
}

void craps_game::play(){
	/* Función que muestra la interfaz para cada juego */
	char inpt_char;

	while (next_move){
		/* Se sigue jugando siempre y cuando next_move == true */
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "Para tirar los dados, presione S, para salir presione N: ";
		std::cin >> inpt_char;

		switch (inpt_char){
			case 'S':
				play_move(player_sum);
				break;

			case 'N':
				next_move = false;
				break;

			default:
				std::cout << ">> Opción inválida" << std::endl;
		}
	}
}

void craps_game::play_again(){
	/* Función que se ejecuta luego de haber perdido o ganado. Pregunta si se desa jugar nuevamente */
	char pag;
	
	std::cout << "¿Desea jugar de nuevo? [S/N]: ";
	std::cin >> pag;

	switch (pag){
		case 'S':
			player_sum = 0;   // se reinicia el punto para una nueva partida
			next_move = true;
			break;
	
		case 'N':
			next_move = false;
			break;

		default:
			std::cout << "> Opvión inválida, saliendo de todas maneras" << std::endl;
			next_move = false;
	}
}
