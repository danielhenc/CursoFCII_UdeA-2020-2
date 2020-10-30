#include "CuentaCheques.h"

CuentaCheques::CuentaCheques( double saldoInicial, double costoTransaccion ): CuentaBancaria(saldoInicial)
{
	this -> costoTransaccion = costoTransaccion;
}

void CuentaCheques::abonarCheque(double abono)
{
	if (abonar(abono)){ saldo -= costoTransaccion; } // Usa el metodo abonar de la clase base para saber si hace el cobro de la transaccion
}

void CuentaCheques::cargarCheque(double retiro)
{
	if (cargar(retiro)){ saldo -= costoTransaccion; } // Usa el metodo cargar de la clase base para saber si hace el cobro de la transaccion
}
  
