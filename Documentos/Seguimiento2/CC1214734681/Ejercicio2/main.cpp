//Johan Carrillo - 1214734681
#include <iostream>
#include <string>
#include "number_library.cpp"  // integer_part, frac_part

using namespace std;
using namespace number_library;


// main function of the program
int main(){

	double number;
	string frac;

	cout << "Inserte un numero, separando el decimal con un punto \".\" " << endl;
	cin >> number;  // reads the number as string


	cout << "La parte entera del numero es: " << integer_part(number) << endl;

	frac = to_string(frac_part(number)).erase(0, 1);  // delete the first cero in the decimal part
	cout << "La parte decimal del numero es: " << frac << endl;

	return 0;
}




