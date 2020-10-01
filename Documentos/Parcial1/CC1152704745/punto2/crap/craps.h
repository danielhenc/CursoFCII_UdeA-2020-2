#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::rand;

class craps_game{
	public:
	craps_game();             // Constructor de la clase
	
	void play();              // Función para iniciar la partida

	private:
	// vars
	int dado_1;               // Valor del dado 1
	int dado_2;               // Valor del dado 2
	int player_sum;           // Suma de los dos dados por lanzamiento
	bool next_move;           // Indica si se va a jugar la próxima movida
	
	// funcs
	void set_values();        // Función para inicializar las variables del juego
	int throw_dice();         // Función para lanzar los dados
	void play_move(int);      // Función que juega la movida
	void play_again();        // función para volver a jugar
};
