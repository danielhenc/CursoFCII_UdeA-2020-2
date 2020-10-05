/* Johan Alexis Carrillo Toro - 1214734681
	EThis is the craps game, the rules are the same that those in the numeral a but
	now the player can bet. There is an initial amount of 1000000$ and the player can
	continue until decide to retire or get out of money*/


#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <iostream>

using namespace std;


// Prototypes
float ask_bet( float );  // This is used to ask the player to bet
char ask_keep_playing( float );  // ask the player if want to keep playing
void tease( float, float );  // tease the player about his bet
int craps();  // This is the main core of the craps game
void show_rambo();  // show a rambo ascii in screen when the player loses all his money


// main function of the program
int main(){

	float bet;  // This is the player's bet
	float remaining = 1000000;  // This is the remaining money that the player has, the initial amount is 1000000
	char answer = 'Y';  // This is used to ask the player if wants to keep playing
	int result;  // This is the result of a game of craps can be 0 (lose) or 1 (win)
	srand(time(NULL));  // Seed for the random function using pc's clock


	cout << "Bienvenido a craps! Un juego que solo l@s mas mach@s pecho peludo juegan hasta el final! (ò_óˇ)\n";
	cout << "Cuentas con un monto inicial de 1'000.000$, puedes jugar hasta ";
	cout << "que te quedes sin dinero o te retires. \nMucha suerte!\n" << endl;

	cout << "Comencemos el juego!" << endl;

	// starts the game
	while(answer=='Y' or answer=='y'){  // The cycle keeps until the player says wants to stop or runs out of money

		if(remaining<=0){  // if the player loses all his money the program breaks
			cout << "\nUhh, parece que alguien está quebrado.\n";
			cout << "Puedes volver a jugar luego, si es que tu mami te da dinero... =D\n" << endl;
			show_rambo();
			return 0;
		}

		bet = ask_bet(remaining);  // ask the player to do a bet

		tease(bet, remaining);  // tease the player about his bet

		result = craps();  // play craps

		if(result==1)  // if the player wins earn more money
			remaining += bet;
		else  // if the player loses
			remaining -= bet;

		answer = ask_keep_playing(remaining);
	}
}


float ask_bet(float remaining){
	// Ask the player to bet and returns the bet the player does

	float bet;

	cout << "Has una apuesta jugosa ( ͡° ͜ʖ ͡°)" << endl;
	cin >> bet;

	while(bet>remaining){  // evaluate if the bet is valid
		cout << "Ambos sabemos que no tienes tanto dinero! jaja. \n";
		cout << "(╯°□°)╯ Ingresa una apuesta valida de una vez!" << endl;
		cin >> bet;
	}

	return bet;
}

char ask_keep_playing(float remaining){
	// ask the player if wants to keep playing 

	char answer;

	cout << "Tu saldo actual es de: " << setprecision(9) << remaining << "\n";
	if(remaining!=0){
		cout << "\nQuieres seguir jugando?\n";
		cout << "Escribe Y/y si quieres seguir jugando, ingresa otra letra para salir" << endl;
		cin >> answer;

		if(answer=='Y' or answer=='y')  // If the player wants to keep playing
			cout << "Estas valiente hoy, eh? Eso me gusta =D" << endl;
		else{  // if the player decide to leave the game
			cout << "Ya te vas? Trae mas dinero la proxima vez! :3\n";
			cout << "Tu monto final es de: " << setprecision(9) << remaining << endl;
			exit(0);  // close the program
		}
	}
	else
		answer = 'Y';
	return answer;
}

void tease(float bet, float remaining){
	// Here it is stated an amount of senteces to tease the player about his bet... just because it's fun :p

	if(bet>=(remaining*0.8))
		cout << "Apostando a lo grande, eh? Que valiente!" << endl;
	else if(bet>(remaining*0.3) and bet<(remaining*0.8))
		cout << "El que poco apuesta poco pierde... pero tambien poco gana" << endl;
	else
		cout << "Apostando tan poco? Parece que alguien tiene miedo... ¯\\_( ͡° ͜ʖ ͡°)_/¯" << endl;
}

int craps(){  // this is barely the same as the code made in the point 2a
	// If the player wins the result is equal to 1, if loses the return is 0

	int dice1, dice2, sum, point;
	char dummy;
	int result;  // This variable is set 1 if the player wins or 0 if loses


	cout << "\nIntroduce cualquier tecla para tirar los dados" << endl;
	cin >> dummy;  // This is used to interact with the player

	dice1 = 1 + rand()%6;  // random number between 1 and 6
	dice2 = 1 + rand()%6;
	sum = dice1 + dice2;

	if( sum==7 or sum==11 ){  // In this case the player wins
		cout << "La suma de ambos dados fue: " << sum << "\n";
		cout << "Felicidades! Ganaste! =D" << endl;
		result = 1;
		return result;
	}
	else if( sum==2 or sum==3 or sum==12 ){  // In this case the player loses
		cout << "La suma de ambos dados fue: " << sum << "\n";
		cout << "Que mala suerte, la casa gana D= Pero puedes intentarlo de nuevo!" << endl;
		result = 0;
		return result;
	}
	else{  // In this case the player gets a point
		cout << "Has obtenido un punto!" << "\n";

		point = sum;  // save the point

		do{  // if the player gets the point again wins, if gets 7 in the sum loses
			cout << "La suma fue: " << sum << endl;
			cout << "Debes sacar de nuevo tu punto para ganar" << endl;
			cout << "\nIntroduce cualquier tecla para tirar los dados de nuevo" << endl;
			cin >> dummy;

			dice1 = 1 + rand()%6;
			dice2 = 1 + rand()%6;
			sum = dice1 + dice2;

			if( sum==point ){  // In this case the player wins
				cout << "La suma de ambos dados fue: " << sum << "\n";
				cout << "Has sacado de nuevo el punto! Ganaste! =D" << endl;
				result = 1;
				return result;
			}

		} while( sum!=7 );  // In this case the player loses

		cout << "La suma fue: " << sum << endl;
		cout << "Que mala suerte, la casa se queda con tu dinero D= Pero puedes intentarlo de nuevo!" << endl;
		result = 0;
		return result;
	}
}

void show_rambo(){

	cout << "/ ﹋ \\ \n";
	cout << "(҂`_´)\n";
	cout << "<, ︻╦╤─ ҉ - - - - - - - - (X_X)\n";
	cout << "/ ﹋ \\ "  << endl; 
}