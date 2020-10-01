#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>


using std::cout;
using std::setw;
using std::endl;
using std::vector;


int main(int argc, char const *argv[])
{
    srand(time(NULL)); //inicializacion de la semilla 

    int i;
    int dado1, dado2;
    vector< int > frecuencia(13, 0);     

    // se llena el arreglo de frecuancias con 
    // el experimento de tirar los dados
    
    for (i = 0; i < 36000; i++){
        dado1 = 1 + rand()%6;
        dado2 = 1 + rand()%6;

        frecuencia[ dado1 + dado2 ]++;
    }

    // se imprime en pantalla en forma de tabla 
    cout << "Suma    Frecuancia" << endl;
    cout << "--------------------" << endl;
    
    for (i = 2; i < frecuencia.size(); i++)
        cout << setw(2) << i << setw(12) << frecuencia[i] << endl;

    return 0;
}
