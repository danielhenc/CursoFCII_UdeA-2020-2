/* Johan Alexis Carrillo Toro - 1214734681

	This is the craps game, rules are easy: the player throws two dice, if the sum equal 
	7 or 11 in the first throw the player wins. If the sum is 2, 3 or 12 in the first throw
	the player loses. If the sum is 4, 5, 6, 8, 9 o 10 in the first throw, this sum becomes
	the player's "point". To achieve victory the player must keep throwing until the sum is
	again his point. If the sum is equal to 7 before the point is obtained the player loses.*/


#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <iostream>

using namespace std;


// main function of the program
int main(){

	cout << "Bienvenido a craps!" << endl;

	srand(time(NULL));  // Seed for the random function using pc's clock
	int dice1, dice2, sum, point;
	char dummy;

	cout << "Introduce cualquier tecla para tirar los dados" << endl;
	cin >> dummy;  // This is used to interact with the player

	dice1 = 1 + rand()%6;  // random number between 1 and 6
	dice2 = 1 + rand()%6;
	sum = dice1 + dice2;

	if( sum==7 or sum==11 ){  // In this case the player wins
		cout << "La suma de ambos dados fue: " << sum << "\n";
		cout << "Felicidades! Ganaste!" << endl;
		return 0;
	}
	else if( sum==2 or sum==3 or sum==12 ){  // In this case the player loses
		cout << "La suma de ambos dados fue: " << sum << "\n";
		cout << "Que mala suerte, la casa gana. Pero puedes intentarlo de nuevo!" << endl;
		return 0;
	}
	else{  // In this case the player gets a point
		cout << "Has obtenido un punto!" << "\n";

		point = sum;  // save the point

		do{  // if the player gets the point again wins, if gets 7 in the sum loses
			cout << "La suma fue: " << sum << endl;
			cout << "Debes sacar de nuevo tu punto para ganar" << endl;
			cout << "Introduce cualquier tecla para tirar los dados de nuevo" << endl;
			cin >> dummy;

			dice1 = 1 + rand()%6;
			dice2 = 1 + rand()%6;
			sum = dice1 + dice2;

			if( sum==point ){  // In this case the player wins
				cout << "La suma de ambos dados fue: " << sum << "\n";
				cout << "Has sacado de nuevo el punto! Ganaste!" << endl;
				return 0;
			}

		} while( sum!=7 );  // In this case the player loses

		cout << "La suma fue: " << sum << endl;
		cout << "Que mala suerte, la casa gana. Pero puedes intentarlo de nuevo!" << endl;
		return 0;
	}
}