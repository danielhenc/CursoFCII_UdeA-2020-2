#include "cuenta.h"
#include <iostream>

using std::cout;
using std::endl;

Cuenta::Cuenta(double saldo)
{
    if(saldo < 0)
    {
        cout << "Error: El saldo debe ser mayor o igual a cero." << endl;
        cout << "Saldo actual: 0" << endl;
        saldo = 0;
    }
    else
        this->saldo = saldo; 
}

double Cuenta::abonar(double toAdd)
{
    if(toAdd < 0)
        cout << "Error: El saldo a abonar debe ser mayor a cero" << endl;
    else
        saldo += toAdd;
    return saldo;        
}

double Cuenta::cargar(double to)
{
    if((to >= 0) && (saldo - to) >= 0)
        saldo -= to;
    else if(saldo - to < 0)
        cout << "Error: El monto a cargar excedio el saldo de la cuenta." << endl;
    else
        cout << "Error: valor invalido" << endl; 
    return saldo;
}

double Cuenta::getSaldo()
{
    return saldo;
}

CuentaAhorros::CuentaAhorros(double saldo, double interes)
{
    //TODO: change this
    this->saldo = saldo;
    this->interes = interes;
}

double CuentaAhorros::calcularInteres()
{
    return saldo * interes;
}

void CuentaAhorros::setInteres(double interes)
{
    if(interes < 0)
        cout << "Error: La tasa de interes debe ser mayor o igual a cero" << endl;
    else
        this->interes = interes;
}

CuentaCheques::CuentaCheques(double saldo, double cuota)
{
    //TODO: change this
    this->saldo = saldo;
    this->cuota = cuota;
}

double CuentaCheques::abonar(double to_add)
{
    if(saldo + to_add - cuota < 0)
        cout << "Error: El saldo actual es muy bajo para realizar esta transaccion." << endl;
    else if( saldo < Cuenta::abonar(to_add) ) //Verificar si se agregó dinero al saldo
        saldo -= cuota; //Cobrar la cuota por la transacción
    return saldo;
}

double CuentaCheques::cargar(double to)
{
    if( saldo - to - cuota)
        cout << "Error: El saldo actual es muy bajo para realizar esta transaccion." << endl;
    else if( saldo > Cuota::cargar(to)) //Verificar que se realice el retiro
        saldo -= cuota;
    return saldo;
}
