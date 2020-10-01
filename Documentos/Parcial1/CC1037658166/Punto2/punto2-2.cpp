#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "punto2-2.h"

using namespace std;

CrapsGame::CrapsGame(int balance)
{
    /* 
    Inicializa el juego con un valor de dinero y establece que el estado B es falso, esto significa que aún no hay un "punto" establecido que el jugador tenga que sacar para ganar.
    */
    
    SaldoenBanco = balance;
    B = false;
}

void CrapsGame::play()
{
    
    /*
    Funcion principal, a pesar de su nombre, es la que lleva a cabo todo el juego
    */
    
    string keep;
    
    while(true)
    {
        if (!B)
        {
            determine_bet();
        }
        val = Throw_two_dices();
        
        cout << "Valor obtenido: " << val << endl;
    
        /*
        De aqui en adelante se considera un ramificación del juego en dos estados posibles denominados estado triunfo (B == true) o estado no triunfo (B == false). La nomenclatura es tomada de algunos juegos de cartas donde una pinta en particular tiene mayor valor que otras, a esta pinta se le denomina triunfo, y en cada juego se determina cual será el triunfo. En este caso, si el jugador obtiene un número diferente de 2, 3, 7, 11 ó 12 en el primero juego, obtendra un punto, que tiene que volver a obtener. A este punto se le denominará punto triunfo. De modo que la ramificación del programa resulta evidente. Si hay un punto triunfo elegido, entonces el estado será de triunfo, ni no hay un punto triunfo elegido, el estado será de no triunfo. 
        */
            if(!B)      
            {
                no_triumph_state();
            }
            else if(B)
            {
                triumph_state();
            }
    
        // are_ya_winning es una cantidad que puede tomar los valores de -1,0 ó 1. Es útil esta definición, porque si hay un juego en progreso, no se actualizará el saldo, pero si el jugador gana, are_ya_winning toma valor de 1, o si pierde, toma el valor de -1. De modo que basta una sola linea para cualquier operación de adición o sustracción del saldo.
        
        SaldoenBanco += are_ya_winning * bet_val;
        
        
        // Si se adicionó o sustrayó una cantidad en el banco. Las variables se reinician. Es hora de un nuevo juego
        if( are_ya_winning != 0)
        {
            cout << "Dado que tu apuesta era de " << bet_val << " ahora tienes " << SaldoenBanco << endl;  
            bet_val = 0;
            are_ya_winning = 0;
        }
        
        
        // Después de cada movimiento en el saldo, se revisa si el jugador entró en quiebra.
        if (SaldoenBanco == 0)
        {
            cout << "Oh, nos acabamos de quedar con todo tu dinero. Una verdadera lástima. Mejor suerte la proxima vez" << endl;
            break;
        }
        
        // Dialogo recurrente de permanencia en el juego
        
        cout << endl;
        cout << "¿Deseas volver a tirar los dado? (y/n) ";
        cin >> keep;
        
        if(keep == "n")
        {
            SaldoenBanco -= bet_val;
            cout << "Pues si no quieres tirar los dados es porque no quieres seguir ¿¿¿¿¿no????? Asumo pues, asi que adiós y muchas gracias por su colaboración. La casa se quedara con el valor de la apuesta realizada en el caso de haber. Sales con " << SaldoenBanco << endl;
            break;
        }
    }
}


void CrapsGame::determine_bet()
{
    /*
    Determina la cantidad apostada en cada ronda. El jugador puede decidir apostar o no, pero la cantidad apostada debe ser necesariamente mayor o igual que el saldo en el banco. Si el jugador intenta apostar una cantidad mayor, se generará un mensaje, y se le pedirá que vuelva a elegir la cantidad apostad, si el jugador incide en intentar apostar una cantidad mayor, se desplegará un mensaje más agresivo.
    */
        
    string is_there_a_bet;
    int saturation_counter = 0;
    
    cout << "¿Deseas apostar en esta ronda? (y/n) ";
    cin >> is_there_a_bet;
    
    if (is_there_a_bet == "y")
    {
        cout << "¿Cuánto deseas apostar en esta ronda? ";
        cin >> bet_val;

        while(bet_val > SaldoenBanco)
        {
            if (saturation_counter < 1)
            {
                saturation_counter += 1;
                cout << "No tienes esa cantidad de dinero. Recuerda que tu saldo actual es de " << SaldoenBanco << " asi que necesariamente debes ingresar una cantidad menor: ";
                cin >> bet_val;
            }
            else
            {
                cout << "¡¿Que tienes una neurona o qué?! La cantidad apostada debe ser menor a " << SaldoenBanco <<". Intenta de nuevo y PENSANDO por favor: ";
                cin >> bet_val;
            }
        }
    }
    else
    {
        bet_val = 0;
    }
}

int CrapsGame::Throw_two_dices()
{
    /*
    Genera dos numeros aleatorios de 1 a 6 y los suma.
    */
    int dice1 = 1 + rand() % 6;
    int dice2 = 1 + rand() % 6;
    
    return dice1 + dice2;  
}

void CrapsGame::no_triumph_state()
{
    if ((val == 7)||(val == 11))
    {
        cout << "Ganaste" << endl;
        are_ya_winning = 1;
    }
    else if((val == 2)||(val == 3)||(val == 12))
    {
        cout << "Perdiste" << endl;
        are_ya_winning = -1;
    }
    else
    {
        B = true;
        cout << "Ahora tu valor del triunfo es " << val << ". ¡Esfuérzate en obtenerlo!" << endl;
        triumph_val = val;
        are_ya_winning = 0;
    }
}

void CrapsGame::triumph_state()
{
    if (val == triumph_val)
    {
        cout << "Ganaste" << endl;
        are_ya_winning = 1;
        B = false;
    }
    else if (val == 7)
    {
        cout << "Craps. Perdiste" << endl;
        are_ya_winning = -1;
        B = false;
    }
}
        
           
        













