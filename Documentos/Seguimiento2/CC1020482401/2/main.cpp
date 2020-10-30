#include <iostream>
#include "number.cpp"

using namespace numComponents;

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	double number;

	cout << "Ingrese un numero por favor:" << endl;
	cin >> number;

	cout << "La parte entera del numero ingresado es: " << entero(number) << endl;
	cout << "La parte fraccionaria del numero ingresado es: " << partefracc(number) << endl; 

	return 0;
}