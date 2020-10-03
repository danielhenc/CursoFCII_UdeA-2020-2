/**
 * @author Andrés Santiago Duque Escobar
 * @brief  Punto 2 del parcial 1 (Juego de craps)
 **/
#include <iostream>
#include "Craps.h"

using std::cout;
using std::endl;

int main()
{
    Craps craps;
    int round = 1; //ronda actual
    Craps::gameState gameStatus;

    cout << "Nuevo juego..." << endl;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "Ronda " << round++ << "..." << endl;
        cout << "=====================================" << endl;
        gameStatus = craps.playRound();
        cout << "Sacaste " << craps.getDiceResult() << " al tirar los dados" << endl;
    }while(gameStatus == Craps::game_continue);

    if(gameStatus == Craps::player_win)
        cout << "Felicidades!! Ganaste el juego" << endl;
    else
        cout << "Perdiste el juego :(" << endl;
    return 0;
}
