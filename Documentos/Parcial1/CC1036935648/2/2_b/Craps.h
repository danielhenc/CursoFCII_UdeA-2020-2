#ifndef CRAPS_H
#define CRAPS_H

class Dice;

class Craps
{
public:

    /**
     * Estado del juego al final de cada ronda
     */
    enum gameState
    {
        player_win,     ///< El jugador ganó el juego
        player_loose,   ///< El jugador perdió el juego
        game_continue   ///< El juedo debe continuar
    };

    Craps();
    ~Craps();

    /**
     * @brief Juega una ronda de craps
     * @return true si el jugador gana o false si el jugador pierde
     */
    gameState playRound();

    /**
     * Retorna el último resultado del lanzamiento de los dados
     */
    int getDiceResult();

private:
    bool isFirstRound;  // Indica si es la primera ronda
    int plyPoint;       // "Punto" del jugador
    int lastDiceResult; // Último resultado de los dados
    Dice *d1,*d2;       // Dados
};

#endif // CRAPS_H
