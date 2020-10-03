#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player();

    /**
     * Retorna la cantidad de dinero que el jugador
     * tiene en el banco
     */
    unsigned int getCashInBank();

    /**
     * @brief Agrega dinero al acumulado del jugador
     * @param cash  Cantidad de dinero a agregar
     * @return cantidad de dinero con la que el jugador queda
     */
    unsigned int addCash(unsigned int cash);

    /**
     * @brief Saca dinero al acumulado del jugador
     * @param cash Dinero a sacar
     * @return cantidad de dinero con la que el jugador queda
     */
    unsigned int takeOffCash(unsigned int cash);

private:

    unsigned int cashInBank; // Dinero acumulado

};

#endif // PLAYER_H
