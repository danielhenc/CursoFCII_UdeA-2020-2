// Jacobo Parodi Díez - Parcial 1 de Física Computacional II

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "punto2-2.h"

using namespace std;

int main()
{
    srand(time(NULL));
    
    int M;
    cout << "Bienvenido al juego de Craps. A continuación se presentarán las reglas del juego." << endl;
    cout << endl;
    cout << "Las reglas del juego son sencillas. Al comienzo, si sacas un 7 o un 11 ganas directamente y se te retribuye la cantidad apostada, por otro lado, si obitenes 2,3 o 12, pierdes, y pierdes, naturalmente, el dinero apostado. Sin embargo, si obtienes cualquier otro número, ese número se convertirá directamente en tu número del triunfo en el sentido que debes volver a sacarlo para ganar. Lo bueno es que tienes infinitos intentos posteriores para sacarlo, lo malo, es que si te llega a salir un 7, pierdes y nos quedamos con tu dinero. Mucha suerte, en esta temerosa aventura a la cual te enfrenterás." << endl;
    cout << endl;
    cout << "Ingrese la cantidad de dinero que pondrá en juego:  ";
    cin >> M;
    
    CrapsGame Game(M);
    Game.play();

    return 0;
}
