/**
 * @author Valentina Roquemen Echeverry
 * @brief  Se diseña un a clase para que el usuario
 *         juegue el famoso juego de casino: Craps
 *         (Ahora en su version mejorada, con apuestas)
 */

class Craps
{
public:
	Craps();

	/*
	* Se le pregunta al usario cuanto desea apostar
	*/
	void apostar();

	/*
	* Se realiza el lanzamiento de dos dados
	* y se muestra en pantalla el resultado
	* de la suma.
	*/
	void lanzamiento();

	/*
	* Dependiendo del resultado del juego 
	* suma o resta al saldo del banco
	*/
	void resultadoApuesta(bool);

	/*
	* Imprime las reglas del juego
	*/
	void reglasJuego();

	/*
	* Se lanzan los dados y se toman las 
	* decisiones segun las reglas del juego
	*/
	void play();

	/*
	* Se decide si se va a jugar o terminar con
	* el programa
	*/
	void mainMenu();

private:
	int dice1; // Dado 1
	int dice2; // Dado 2
	int sum; // Suma del lanzamiento de los dados
	int SaldoenBanco = 1000000; // Saldo inicial para apostar  
	int apuestaValue; // Valor de la apuesta que se realiza en el turno
	
};