
#include "Dice.h"
#include <cstdlib>
#include <ctime>


bool Dice::isSeedInitiliced = false;

Dice::Dice()
{
    if(!isSeedInitiliced)
    {
        srand(time(NULL));
        Dice::isSeedInitiliced = true;
    }
}

int Dice::Throw()
{
    return rand()%6 + 1; //Números entre 1 y 6
}