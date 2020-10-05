/*
Definición de la clase CRAPSgame 
*/

class CRAPSgame
{
	public:
		CRAPSgame( void ); //costructor
		void beginGame( void ); //inicializa el juego
		char uPlay( void ); //pregunta si continúa jugando
		float getApuesta( void ); //obtiene la apuesta del usuario
		void showMessage( int ); //Mensajes a lo largo del juego
		int Dados( void ); //Genera el número aleatorio 
							// y devuelve 1 "gana" o 0 "pierde" 0 2 "sigue intentado"
		void toPlay( void ); //estructura todo el juego
		void continueGame ( char ); //sigue jugando 

	private:
		float SaldoenBanco; //saldo en banco 
		int nTiro; //contador de lanzamientos
		int userPunto; //en caso de guardar punto
};