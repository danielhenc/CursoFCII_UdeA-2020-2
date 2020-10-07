#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void jugar(); //aquí se va a definir todo el juego

int main(void){
	char tiro, pausa;
	do{
		cout << "-----Deseas jugar? presiona y para jugar o n para salir-----" << endl;
        tiro= getchar();
        pausa= getchar();
        if(tiro== 'y' || tiro== 'Y') //mientras la persona precione "y", en minúscula o mayúscula, se correrá el juego
            jugar();
	}
	while(tiro== 'y' || tiro== 'Y'); //para esperar las respuestas siguientes
	system("pausa");
	return 0;
	}

void jugar(){
	int dado1, dado2, dado3, dado4, suma, suma2;
	
    srand(time(NULL));

    dado1 = 1 + rand() % 6; //número aleatorio del 1 al 6, los dado 1 y 2 equivalen al lanzamiento inicial
    dado2 = 1 + rand() % 6;
    suma = dado1 + dado2;

    if(suma== 7 || suma== 11){ //si el jugador saca un 7 o un 11 en el primer lanzamiento gana y se acaba la partida
		cout << "       Tiraste un " << suma << endl;
		cout << "Felicitaciones, ganaste!" << endl;
		return;
		}
    else if(suma== 2 || suma== 3 || suma== 12){ //si saca 2, 3, 4 en el primer lanzamiento pierde y se acaba la partida
		cout << "       Tiraste un " << suma << endl;
		cout << "Perdiste, la casa gana!" << endl;
		return;
		}
    else{
		cout << "Punto! Tiraste un " << suma << endl; //si saca otro número el primer lanzamiento es su punto y hay que tirar de nuevo
		do{ //se tiran los dados hasta que el nuevo lanzamiento sea igual al primero o se saque un 7
			dado3= 1 + rand() % 6; //los dados 3 y 4 corresponden al nuevo lanzamiento 
			dado4= 1 + rand() % 6;
			suma2= dado3 + dado4;
			cout << "       Tiraste un " << suma2 << endl;
			if(suma2== suma){ //si el nuevo lanzamiento equivale al punto gana y se acaba la partida
				cout << "Felicitaciones, ganaste!" << endl;
				return;
				}
			}
		while(suma2 != 7); // si el nuevo lanzamiento es un 7 pierde y se acaba la partida.
		cout << "Perdiste, la casa gana!" << endl;
        }
	}
