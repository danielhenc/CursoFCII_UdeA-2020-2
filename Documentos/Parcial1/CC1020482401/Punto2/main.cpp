#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;


bool playCraps(void);
int print_messages(int, int, int);

int SaldoInicial = 1000000; // the player begin with this amount of money

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // seed random is initialized
    char play; // sentinel to stop the game 
    int bankrupt = 0; // this variable becomes 1 if the player lose all his money
    int SaldoenBanco = SaldoInicial; 
    int bet = 0; // this variable indicated the bet for play

    // start message
    cout << "Bienvenido al casino" << endl;
    cout << "Usted tiene " << SaldoenBanco << " USD" << endl;
    cout << "¿Desea comenzar a jugar Craps? (y/n)" << endl;
    cin >> play;


    // runs while the player wants to continue in the game or loses the money
    while(play != 'n'){
        int bad_streak = 0;
        int good_streak = 0;

        cout << "¿Cuanto quiere apostar?" << endl;
        cin >> bet;

        
        // the player can't bet more than his bank balance  
        if (bet > SaldoenBanco){
            cout << "No tiene el dinero suficiente, su saldo actual es " << SaldoenBanco << " USD" << endl;
            cout << "Intente cambiar el monto de la apuesta" << endl;
            continue;
        }
        else
            cout << "Apuesta aceptada" << endl;

        
        // start of the game 
        if (playCraps()){
            SaldoenBanco += bet;
            bad_streak = 0;
            good_streak += 1;// if the player win, her good streak grow
        }
        else{
            SaldoenBanco -= bet;
            bad_streak += 1; // if the player lose, her bad streak grow
            good_streak = 0;
        }

        // according to streak and money, a interactive message is displayed 
        bankrupt = print_messages(SaldoenBanco, bad_streak, good_streak);
        
        // lose all the money
        if (bankrupt)
            break; 

        cout << "Quiere volver a jugar ? (y/n)" << endl;
        cin >> play;
    }

    cout << "Gracias por jugar con nosotos, vuelva pronto!" << endl;

    return 0;
}


bool playCraps(void){

    int die1, die2; 
    int sum = 0; // sum of the dice numbers

    bool won = false; // variable to know when the player win or lose
    int attempNum = 0; // number of attemps
    int punto = 0; 

    // This is "Craps" Game
    while(true){
            attempNum++;

            die1 = 1 + rand()%6;
            die2 = 1 + rand()%6;
            sum = die1 + die2;

            if(attempNum == 1){
                if (sum == 7 || sum == 11){
                    cout << "\nGano en el primer intento, Felicitaciones!" << endl;
                    won = true;
                    break;
                }
                else if (sum == 2 || sum == 3 || sum == 12){
                    cout << "\nPerdió en el primer intento, mala suerte saco un craps!" << endl;
                    break;   
                }
                else
                    punto = sum;
            }
            else{
                if (sum == punto){
                    cout << "\nGano en el intento " << attempNum << ", saco  "<< sum << " otra vez."<< endl;
                    won = true;
                    break;
                }
                else if (sum == 7){
                    cout << "\nPerdió en el intento " << attempNum << ", saco "  << sum << endl;
                    break;
                }
                else;
            }
        }

    return won;
}

int print_messages (int saldo, int bad_streak, int good_streak){

    cout << "Su nuevo Saldo es " << saldo << " USD" << endl;

    if (saldo == 0){
        // the player loses all the money
        cout << "Lo sentimos, se quedo sin fondos!" << endl;
        return 1;
    }
    else if(saldo <= SaldoInicial / 4){
        if (bad_streak >= 3)
            // if the amount of money is small and the player have a bad streak
            cout << "usted se esta quebrando, no le parece?" << endl;
        else
            // in other case, when the player have good streak would continue in the game
            cout << "hagale, no pasa nada, arriesguese!" << endl;   
    }
    else
        if (good_streak >= 5){
            // if the player have a very good streak, it's better than he go out from the table
            cout << "Ahora es tiempo de cambiar sus fichas por la plata!" << endl;
        }
        else; 

    return 0;           
}