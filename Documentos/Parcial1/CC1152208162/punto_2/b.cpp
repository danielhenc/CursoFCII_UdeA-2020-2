#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int jugar(); //aquí se va a definir todo el juego
void dialogo(); //para las frases random
float SaldoenBanco = 1000000; 

int main(){
  int Apuesta = 0; //se inicializa el valor de la apuesta
  char tiro, pausa;
	do{
		cout << "-----Deseas jugar? presiona y para jugar o n para salir-----" << endl;
        tiro= getchar();
        pausa= getchar();
        if(tiro== 'y' || tiro== 'Y') //mientras la persona precione "y", en minúscula o mayúscula, se correrá el juego
        while(SaldoenBanco >= Apuesta ){
			cout << "Ingresa tu apuesta ";
			cin >> Apuesta; 
			if(Apuesta > SaldoenBanco || SaldoenBanco == 0) { //para verificar que la apuesta no exeda al saldo en banco
				cout << "Estás tirando muy algo, no tienes fondos " << endl;
				break;
				}
			else if(jugar() == 1){ //si el jugador gana se suma la apuesta al saldo
					SaldoenBanco += Apuesta;
					cout << "Tu nuevo saldo es: " << SaldoenBanco << endl;
					}
			else{ //si el jugador pierde se resta la apuesta del saldo
				SaldoenBanco -= Apuesta;
				cout << "Tu nuevo saldo es: " << SaldoenBanco << endl;
				}
		dialogo(); //se generan frases a lo largo del juego
		Apuesta = 0;
		}
	}
	while(tiro== 'y' || tiro== 'Y'); //para esperar las respuestas siguientes
	system("pausa");
	return 0;
}
int jugar(){
	int dado1, dado2, dado3, dado4, suma, suma2, ganar;
    srand(time(NULL));

    dado1 = 1 + rand() % 6; //número aleatorio del 1 al 6, los dado 1 y 2 equivalen al lanzamiento inicial
    dado2 = 1 + rand() % 6;
    suma = dado1 + dado2;

    if(suma== 7 || suma== 11){ //si el jugador saca un 7 o un 11 en el primer lanzamiento gana y se acaba la partida
		cout << "       Tiraste un " << suma << endl;
		cout << "Felicitaciones, ganaste!" << endl;
		ganar= 1;
		}
    else if(suma== 2 || suma== 3 || suma== 12){ //si saca 2, 3, 4 en el primer lanzamiento pierde y se acaba la partida
		cout << "       Tiraste un " << suma << endl;
		cout << "Perdiste, la casa gana!" << endl;
		ganar= 0;
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
				ganar= 1;
				}
			}
		while(suma2 != 7); // si el nuevo lanzamiento es un 7 pierde y se acaba la partida.
		cout << "Perdiste, la casa gana!" << endl;
		ganar= 0;
        }
	return ganar; //para saber si el jugador ganó o perdió
	}

void dialogo(){ //para mostrar diálogos según el saldo que se tenga

  if(SaldoenBanco <= 10000)
      cout << "Estás en las últimas, pilas "<< endl;
      
  else if(SaldoenBanco >= 10000 and SaldoenBanco <= 100000)
      cout << "Mucha loca si te vas ya "<< endl;
      
  else if(SaldoenBanco >= 100000 and SaldoenBanco <= 1000000)
      cout << "Puedes dar más, sigue "<< endl;
     
  else if(SaldoenBanco >= 2000000 and SaldoenBanco <= 3000000)
      cout << "Eso campeón! "<< endl;
 
  else if(SaldoenBanco >= 8000000)
      cout << "Nos vas a quebrar! mejor andate "<< endl;

}
