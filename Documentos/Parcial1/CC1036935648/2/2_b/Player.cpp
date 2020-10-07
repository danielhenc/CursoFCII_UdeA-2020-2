#include "Player.h"

Player::Player()
{
    cashInBank = 1000000; //Cada jugador inicia con un millón
}

unsigned int Player::getCashInBank()
{
    return cashInBank;
}

unsigned int Player::addCash(unsigned int cash)
{
    cashInBank += cash;
    return getCashInBank();
}

unsigned int Player::takeOffCash(unsigned int cash)
{
    /* El jugador no puede tener menos de 0 pesos en el banco */
    cashInBank = (cash < cashInBank)? cashInBank - cash : 0;
    return getCashInBank();
}
