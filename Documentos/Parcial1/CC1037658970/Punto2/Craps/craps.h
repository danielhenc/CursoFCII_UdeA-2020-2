/**
 * @author Valentina Roquemen Echeverry
 * @brief  Se diseña un a clase para que el usuario
 *         juegue el famoso juego de casino: Craps
 */

class Craps
{
public:
	Craps();

	/*
	* Se realiza el lanzamiento de dos dados
	* y se muestra en pantalla el resultado
	* de la suma.
	*/
	void lanzamiento();

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
	
};