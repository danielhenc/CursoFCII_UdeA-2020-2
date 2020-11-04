#include <iostream>
#include <sstream>
#include "./myLib.cpp"

using namespace std;

int main()
{
    cout << "===============================" << endl;
    cout << "|    Test funcion entero()    |" << endl;
    cout << "===============================" << endl;
    cout << endl;

    float number = 12345;
    stringstream stream; //stream para manejar la conversión de flotante a string
    do
    {
        stream.str(""); //garantizar que el stream está vacío
        stream << number; //asignar el número al stream
        cout << "La parte entera de " << number << " es: " << mylib::entero(stream.str()) << endl;
        number /= 10; //Actualizar el valor del número flotante
    }while(number > 0.1);

    cout << endl;
    cout << "===============================" << endl;
    cout << "|  Test funcion partefrac()   |" << endl;
    cout << "===============================" << endl;
    cout << endl;

    number = 12345; // reiniciar el número
    do
    {
        stream.str("");
        stream << number;
        cout << "La parte fraccionaria de " << number << " es: " << mylib::partefrac(stream.str()) << endl;
        number /= 10; //Actualizar el valor del número flotante
    }while(number > 0.1);

    return 0;
}
