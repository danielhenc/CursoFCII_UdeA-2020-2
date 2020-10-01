#include "Craps.h"
#include "Dice.h"

Craps::Craps()
{
    /* Crear dos dados nuevos */
    d1 = new Dice();
    d2 = new Dice();

    isFirstRound = true; // Indicar que es la primera ronda
    lastDiceResult = 0;  // Aun no se han lanzado los dados
}

Craps::~Craps()
{
    /* Liberar memoria */
    delete d1;
    delete d2;
}

Craps::gameState Craps::playRound()
{
    int r = d1->Throw() + d2->Throw();  //lanzamiento de los dados
    gameState result;   //estado del juego

    lastDiceResult = r; //Almacenar el último resultado

    if(isFirstRound)
    {
        isFirstRound = false; // Indicar que las siguientes rondas no son la primera

        switch (r)
        {
        case 7:
        case 11:
            result = player_win;
            break;

        case 2:
        case 3:
        case 12:
            result = player_loose;
            break;

        default:
            plyPoint = r;
            result = game_continue;
            break;
        }
    }
    else
    {
        if(r == 7)
            result = player_loose;
        else if(r == plyPoint)
            result = player_win;
        else
            result = game_continue;
    }

    /*
     * Permitir nuevos juegos sin tener que crear
     * una nueva instancia de la clase Craps
     */
    if(result != game_continue)
        isFirstRound = true;

    return result;
}

int Craps::getDiceResult()
{
    return lastDiceResult;
}
