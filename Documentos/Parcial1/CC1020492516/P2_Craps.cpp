//Task
/*Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros. Una
vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores. Si la
suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),
el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se
convierte en el “punto” del jugador. Para ganar, el jugador debe seguir tirando los dados hasta que salga otra
vez “su punto”. El jugador pierde si tira un 7 antes de llegar a su punto.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib> // para la función rand
#include <ctime>  // tiempo a la c++
#include <string> // Esto nos permite meter frases en arreglos, será util para mostrar mensajes.

using namespace std;

float CrapGame(float, float); //Función con el juego Crap

float SaldoenBanco;

float CrapGame(float SaldoenBanco,float Apuesta){

  int dado1 = 0;
  int dado2 = 0;
  int suma1 = 0;
  int suma2 = 0;
  char answer1, answer2;

  answer1 = 'y'; //Respuesta para jugar es Si por default
  
while (answer1 == 'y'){ //El while estaba desde el programa anterior, que preguntaba si se deseaba volver a jugar, así que no lo quité.

	dado1 = 1 + rand() % 6;
	dado2 = 1 + rand() % 6;
	suma1 = dado1 + dado2;

    cout << "\n ( "<< dado1 <<" , "<< dado2<<" )"<< endl;  //Imprime los dados así: (1,5)

	if ( suma1 == 7 or suma1 == 11 ){			//Condición para ganar de una

	cout << "Wow, que suerte tiene, ha sacado: " << suma1 << " Ha ganado" << endl;
	SaldoenBanco = SaldoenBanco + Apuesta; //Como ganó, aumenta su saldo en lo que apostó
					}

	else if ( suma1 == 4 or suma1 == 5 or suma1 == 6 or suma1 == 8 or suma1 == 9 or suma1 == 10 ){// El punto
	
	cout << "Ha sacado: " << suma1 << " que es su punto." << endl;

		cout << "Tirar de nuevo? (y o n): ";
		cin >> answer2;		//Se pregunta si se quiere volver a tirar, aunque esta regla no se especifica.
		
		while (answer2 == 'y'){
			dado1 = 1 + rand() % 6;
			dado2 = 1 + rand() % 6;
			suma2 = dado1 + dado2;
			cout << "\n ( "<< dado1 <<" , "<< dado2<<" )"<< endl;

			if (suma2==suma1){	//Si vuelve al punto, es decir, a la suma de dados anterior, entonces ganó
				cout << "Wow, que suerte tiene, ha sacado: " << suma2 << " Y ha vuelto a su punto, ganó." << endl;
				answer2 = 'n';
				SaldoenBanco = SaldoenBanco + Apuesta; //Aumenta el saldo
					}
			else if (suma2==7){	//Condición de si saca 7, entonces pierde
				cout << "Nea, sacaste " << suma2 << " Abrite que ya perdiste." << endl;
				answer2 = 'n';	//Si pierdes la condición es No de inmediato.
				SaldoenBanco = SaldoenBanco - Apuesta;	//Se le quita lo de la apuesta.
					}
			else {			//Para cualquier otro caso
				cout << "Ha sacado: " << suma2 << " desea arriesgarse y volver a tirar? (y o n): ";
				cin >> answer2;
				}
				
					}
			}

		else { //sacó 2,3 o 12 de primerazo.
		cout << "Nea, sacaste " << suma1 << " de primerazo, abrite que ya perdiste." << endl;
		SaldoenBanco = SaldoenBanco - Apuesta;  //Pierde la apuesta.
		}

	answer1 = 'n'; //Cierra el juego. 
  }
return SaldoenBanco;
}


int main()
{

srand(time(0));  //Semilla, solo llamarla una vez

float Apuesta; //Apuesta se ingresa después por el usuario.
float SaldoenBanco = 1000000;

string fp[8] = {"¿En serio nos vas a regalar toda tu plata?","Jajajajajajaja solo le falta apostar la casa","Nea ya, en serio me estoy preocupando","Tiene más suerte un bulto de sal"," "," "," "," "}; //Frases para cuando un usuario va perdiendo, se dejan los espacios para que no siempre salga una frase.

string fg[8] = {"Ey nos vas a dejar sin plata :c","Exelente, así iba Bil Gates cuando vino","Wow mk que suerte","Papi muy bien"," "," "," "," "}; //Frases para cuando un usuario va ganando

cout<<"### CASINO EL BRAYAN ##"<<endl;
cout<<"Bienvenido al casino virtual ElBrayan, donde seguramente vas a perder. Su banco tiene disponibilidad de 1000000$, ingrese la cantidad que desea apostar: \n"<<endl;

char P1 = 'y';

while(P1=='y'){
cout<<"Apuesta: ";
cin>>Apuesta;

if(Apuesta > SaldoenBanco){ 
	cout<<"Usted no dispone de esa cifra, Igrese un valor válido: "<<endl;
			   }
else if (Apuesta <= 0){
	cout<<"Debe apostar algo. Ingrese un valor válido: "<<endl;
			}
else{
	SaldoenBanco = CrapGame(SaldoenBanco,Apuesta); //Llama a crapgame ingresando las variables saldo y apuesta
	cout<< "\n Ahora tiene: " <<SaldoenBanco<<endl; //Muestra cuánto le queda

	cout<<" Desea volver a jugar? (y o n): ";
	cin >> P1;
	cout<<endl;
		
	if(SaldoenBanco <= 500000 and SaldoenBanco>0){
		int randomfrase = rand()%9; //numero aleatorio para escoger una frase que le dirá al usuario
		cout<< fp[randomfrase] <<"\n"<<endl;
				   }
	else if (SaldoenBanco >= 2000000){
		int randomfrase = rand()%9; //numero aleatorio para escoger una frase que le dirá al usuario
		cout<< fg[randomfrase] << "\n"<<endl;
					}
	else if (SaldoenBanco <= 0){ //Si el saldo llega o baja (Aunque no debería) de cero, entonces perdió.
		cout<<"Lamento informarle que perdió, osea que nosotros ganamos, osea que no lo lamento tanto. El punto es que ya no puede jugar más. Muchas gracias, vuelva pronto. \n"<<endl;
		P1 = 'n';  //Como perdió, ya no importa si quiere volver a jugar o no, no podrá. 
				    }
	}
	   }
return 0;
}
