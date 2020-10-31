#include <iostream>
#include </home/mariaj/Documentos/Universidad/Computacional_2/tarea2.cpp> //incluye el namespace que cree

using namespace PartesNumeros; //para usar las funciones definidas en el namespace

int main()
{
	float a;
	cout << "Ingrese un número:";
	cin >> a;
	cout << "Su parte entera es " << entero(a) << endl;
	cout << "Su parte decimal es " << partefracc(a) <<endl;
	
return 0;
}

