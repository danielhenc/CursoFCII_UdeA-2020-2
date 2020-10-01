#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::rand;

class bcraps_game{
	public:
	bcraps_game();          // Constructor de la clase 

	void play();            // Función para jugar el juego

	private:
	// variables
	int dado_1, dado_2;     // Valores de cada dado
	int player_sum;         // Suma de los dados por lanzamiento
	bool next_move;         // Indicador para jugar la próxima partida	
	int banco;              // Saldo del banco
	int plays;              // Contador de turnos jugados
	int apuesta;            // Apuesta para cada turno

	// funciones
	int throw_dice();              // Función para lanzar los dados
	void set_values();             // Función que inicializa los valores de las variables del juego
	void play_move(int);       // Función para jugar cada turno
	void advice();                 // Función que da cocejos a jugador a medida que juega
	void makebeat();               // Función para hacer una apuesta por movida
	void play_again();             // Función para reiniciar el juego   
	void win();                    // Función que adiciona la apuesta al saldo en banco
	void lose();                   // Función que resta la apuesta al banco y mira si ya se acabó o no
	void nothing();                // Función que permite jugar la próxima movida si no se gano ni perdió
};
