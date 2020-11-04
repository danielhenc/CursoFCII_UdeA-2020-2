/*
archivo donde se ejecuta el main para el espacio de nombres partesNum
*/

#include "partesNum.cpp"

using namespace partesNum;

int main()
{
	cout << "ingrese un número" << endl;
	float a;
	cin >> a;

	cout << "parte entera de " << a << " es " << entero(a) << endl;
	cout << "parte fraccionaria de " << a << " es " << partefracc(a) << endl;

	return 0;
}