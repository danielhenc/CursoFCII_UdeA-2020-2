/**
 * @author Andrés Santiago Duque Escobar
 * @brief  Punto 2 del parcial 1 (Juego de craps)
 **/
#include <iostream>
#include "Craps.h"
#include "Player.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

/**
 * @brief Función para jugar Craps
 * @return true si el jugador gana o false si pierde
 */
bool crapsFunction();


/**
 * @brief Maneja los mensajes que se imprimen en pantalla
 * @param gameResult   Sirve para seleccionar el tipo de mensaje
 *                     a imprimir. Debe ser true si el jugador
 *                     ganó el juego o false si lo perdió.
 */
void messages(bool gameResult);

int main()
{
    Player player;
    bool play = true; //indica si se va a jugar

    while(play)
    {
        unsigned int cashToBet; //dinero a apostar

        /*
         * Validacion de la cantidad a apostar
         */
        do
        {
            cout << endl;
            cout << "Usted dispone de "<< player.getCashInBank() << endl;
            cout << "Ingrese la cantidad que desea apostar" << endl;
            cin >> cashToBet;

            /* Validar que no exista problemas con el cin
             * https://stackoverflow.com/questions/28380544/cin-infinite-loop-when-reading-in-a-non-numeric-value
             */
            if(!cin.good())
            {
                std::string s;
                cin.clear(); //limpiar banderas de error
                cin >> s; //vaciar el búfer
                cashToBet = player.getCashInBank() + 1; //para evitar que salga del ciclo while
            }
        }while(cashToBet > player.getCashInBank());

        /* El jugador ganó? */
        if(crapsFunction())
        {
            player.addCash(cashToBet); //Darle dinero al jugador
            messages(true);
        }
        else
        {
            player.takeOffCash(cashToBet); //Tomar el dinero del jugador
            messages(false);
        }


        /* Verificar si el jugador lo ha perdido todo */
        if(player.getCashInBank() == 0)
        {
            cout << "Estás en banca rota. Consigue mas dinero y vuelve más tarde." << endl;
            break;
        }

        char s;
        cout << "Deseas jugar otra vez? (y/n)" << endl;
        cin >> s;
        if(s=='y' || s=='Y')
            play = true;
        else
            play = false;

    }

    cout << "Finalizaste el juego con "<< player.getCashInBank() << " pesos en el banco" << endl;

    return 0;
}




bool crapsFunction()
{
    Craps craps;
    Craps::gameState gameStatus;

    cout << "Nuevo juego..." << endl;
    do
    {
        gameStatus = craps.playRound();
        cout << "Sacaste " << craps.getDiceResult() << " al tirar los dados" << endl;
    }while(gameStatus == Craps::game_continue);

    if(gameStatus == Craps::player_win)
    {
        cout << "Felicidades!! Ganaste el juego" << endl;
        return true;
    }
    else
    {
        cout << "Perdiste el juego :(" << endl;
        return false;
    }
}

void messages(bool gameResult)
{
    static int consWins = 0; //Victorias consecutivas (>0 victorias <0 pérdidas

    if(gameResult) //El jugador ganó el último juego?
    {
        if(consWins < -1) //pasó de varias perdidas consecutivas a una victoria
            cout << "Tu suerte esta mejorando" << endl;
        else if( consWins == -1) //perdió una vez y ganó
            cout << "Solo fue un susto pasajero. Sigue jugando..." << endl;
        else if((consWins+1)%3 == 0 && consWins > 0) //Lleva 3*n victorias consecutivas
            cout << "Tienes muy buena suerte. Vas a quebrar a la casa!" << endl;

        consWins = (consWins < 0)? 1: consWins + 1; //actializar el numero de victorias
    }
    else
    {
        if(consWins > 1) //pasó de varias victorias consecutivas a una pérdida
            cout << "Esto no es problema. Te recuperaras..." << endl;
        else if( consWins == 1) //ganó una vez y luego perdió
            cout << "Animo, sigue jugando..." << endl;
        else if((consWins-1)%3 == 0 && consWins < 0) //Lleva 3*n pérdidas consecutivas
            cout << "Tienes muy mala suerte. Deberias pensar en tu familia..." << endl;
        consWins = (consWins > 0)? -1: consWins - 1; //actializar el numero de pérdidas
    }
}
