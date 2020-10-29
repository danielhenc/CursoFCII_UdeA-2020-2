#include <iostream>
#include "seguimiento2_2.cpp"

using namespace Parte;
using namespace std;

int main()
{
	double num;

	cout << "Ingrese un número cualquiera (entero o decimal):" << endl;
	cin >> num;

	cout << "La parte entera del numero es: " << entera(num) << endl;
	cout << "La parte fraccional del número es: " << fraccional(num) << endl; 

	return 0;
}
