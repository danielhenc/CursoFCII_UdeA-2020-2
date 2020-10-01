#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//prototipo de funcion craps
int craps(void);
//prototipo funcion que imprime charlas
void imprimirCharla(double);

int main()
{
    srand(time(NULL));

    //saldo inicial para todos los jugados
    double SaldoenBanco = 1000000.;
    //valor de la apuesta
    double apuesta = 0.;
    //para seguir jugando mientras el usuario desee
    char answer = 'y';

    cout << "Bienvenido a Craps!" << endl;
    //fijar precision del dinero
    cout << fixed;

    while (answer == 'y') {

        cout << "\nTu saldo en el banco es de " << setprecision(2) << SaldoenBanco << " pesos" << endl;

        cout << "Deseas lanzar los dados? (y o n) ";
        cin >> answer;

        if (answer == 'n')
            break;

        cout << "Cuanto deseas apostar? ";
        cin >> apuesta;

	//se valida que la apuesta sea menor o igual que el salod en el banco.
        if (apuesta > SaldoenBanco) {
            cout << "No tienes fondos suficientes, ingresa una cifra menor" << endl;
        }
        else {

	    //se llama a a la funcion craps
            int resultado = craps();
            //se guarda el saldo actual
            double aux = SaldoenBanco;
            
            //0 simboliza que perdio el juego de craps
            if (resultado == 0) {
		//se resta el dinero apostado
                SaldoenBanco -= apuesta;
                //se valida si se perdio todo el dinero y se detiene el juego en caso tal
                if (SaldoenBanco == 0) {
                    cout << "Lo siento, te quedaste sin fondos. Ya vayase a su casa :v" << endl;
                    break;
                }
            }
            else
            	//cuando gana, entonces se suma la apuesta
                SaldoenBanco += apuesta;
            //se llama a la funcion imprimir charla, la cual usa el porcentaje relativo entre el saldo antes de jugar y el saldo despues
            //ver explicacion mas adelante
            imprimirCharla(SaldoenBanco / aux);
        }
    }

    //al final del juego, se indica cuanto dinero se tiene.
    cout << "Tu saldo final es " << setprecision(2) << SaldoenBanco << " pesos" << endl;
    return 0;
}

//funcion para el juego craps
int craps()
{
    //booleano que indica si ha ganado o no; 1 = si, 0 = no
    int resultado = 0;

    int punto = 0;

    //por si el usuario desea continuar hasta ganar
    char continuar = 'y';

    while (continuar == 'y') {
        //lanzamiento de dados
        int n1 = 1 + rand() % 6;
        int n2 = 1 + rand() % 6;
        
        int suma = n1 + n2;
        
        cout << "\nHas obtenido " << n1 << " y " << n2 << " respectivamente. La suma de estos dos valores es "
             << suma << endl;
        //El usuario gana en dos casos:
        //Cuando es la primera jugada (punto es 0) y saca 7 o 11 o cuando tiene algun punto diferente de 0 y obtiene como suma el punto que tenia
        if ((punto == 0 && (suma == 7 || suma == 11)) || (punto != 0 && suma == punto)) {
            cout << "¡¡Yass, has ganado el juego!!" << endl;
            resultado = 1;
            continuar = 'n';
        }
        //El usuario pierde en dos casos:
        //Cuando obtiene 2, 3 o 12 en la primera jugada o cuando tiene algun punto diferente de 0 y obtiene un 7 como suma
        else if ((punto == 0 && (suma == 2 || suma == 3 || suma == 12)) || (punto != 0 && suma == 7)) {
            cout << "¡¡Lo siento, has perdido el juego u.u!!" << endl;
            continuar = 'n';
        }
        else {
            //el usuario obtiene en la primera corrida 4, 5, 6, 8, 9, 10 y se le asigna a este un punto = suma
            if (punto == 0)
                punto = suma;
            cout << "Tu punto es " << punto << ", debes obtener este punto nuevamente para ganar!" << endl;
            //en este caso, se puede seguir jugando si el usuario lo desea.
            cout << "\nDeseas continuar jugando? (y o n) ";
            cin >> continuar;
        }
    }

    return resultado;
}


//funcion que imprime charla segun la "perdida" o "ganancia" relativa, es decir, la razon entre el saldo despues de apostar y el saldo anterior 
//Si por ejemplo, el nuevo saldo representa menos del 25% del anterior saldo, entonces esto quiere decir que ha perdido considerablemente
//Asi mismo, el maximo porcentaje posible es 200%, que es cuando el usuario apuesta todo su dinero y gana, entonces su dinero se duplica
//Los mensajes reflejan esta perdida o ganancia.

void imprimirCharla(double porcentaje)
{
    string charla = "";
    if (porcentaje < 0.25)
        charla = "Dios mioooo, lo has perdido casi todo, retirate!";
    if (porcentaje > 0.25 && porcentaje < 0.5)
        charla = "Perdiste una cantidad considerable de dinero, piensa bien si seguir";
    if (porcentaje > 0.5 && porcentaje < 0.75)
        charla = "Aun tienes dinero, pero procede con cautela :3";
    if (porcentaje > 0.75 && porcentaje < 1.)
        charla = "No has perdido casi nada, no azara, sigue jugando";
    if (porcentaje > 1.00 && porcentaje < 1.25)
        charla = "Meh, ganaste una miseria, esto merece otra partida xd ";
    if (porcentaje > 1.25 && porcentaje < 1.5)
        charla = "Has ganado de manera moderada, sigue jugando!! ";
    if (porcentaje > 1.5 && porcentaje < 2.)
        charla = "Estas haciendolo bien, sigue asi y seras rico";
    if (porcentaje == 2.)
        charla = "WOOOOOOOOOOOOW!! Duplicaste tu dinero! Piensa en canjear tus fichas!";
    cout << endl << charla << endl;
}
