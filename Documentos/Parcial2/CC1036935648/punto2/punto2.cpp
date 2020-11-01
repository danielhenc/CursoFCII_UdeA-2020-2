#include <iostream>
#include <iomanip>
#include "cuenta.h"

using namespace std;


int main()
{
    CuentaAhorros ahorros(10, 0.02);
    CuentaCheques cheques(10);
    Cuenta cuenta(-1);

    cout << "saldo ahorros: " << ahorros.getSaldo() << endl;
    cout << "saldo cheques: " << cheques.getSaldo() << endl;
    cout << "saldo cuenta: " << cuenta.getSaldo() << endl;    
}