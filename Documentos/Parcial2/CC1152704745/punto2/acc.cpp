#include "acc.h"

// ___________________ FUNCION BASE ____________________

base_acc::base_acc(double s){
	if (s < 0.0){
		cout << "Saldo inicial invalido. se asignara un valor de $0.0" << endl;
		saldo = 0.0;
	}
	else {
		cout << "Saldo asignado a $" << s << endl;
		saldo = s;
	}
};

// se define la función abonar para sumar saldo al ya existente
void base_acc::abonar(double s) {
	// la función abonar sólo debe usarse para sumar a la cuenta, por lo tanto, el monto a abonar debe ser positivo
	if (s < 0.0) {
		cout << "Monto a abonar invalido, el saldo permanece sin cambio" << endl;
	}
	else {
		cout << "Se ha abonado $" << s << " al saldo. Saldo total: $";
		saldo += s;
		cout << saldo << endl;
	}
}

// se define la función cargar para retirar dinero de la cuenta
void base_acc::cargar(double s) {
	// solo se puede retirar dinero de la cuenta si la cantidad que se quiere retirar es menor o igual a la cantidad actual
	if (s > saldo) {
		cout << "Cantidad a retirar invalida. No puede retirarse mas de lo que hay en la cuenta" << endl;
	}
	else if (s < 0.0) {
		cout << "No puede retirar una cantidad negativa. Use al función abonar" << endl;
	}
	else {
		cout << "Retirando $" << s << " de la cuenta. Saldo total: $";
		saldo -= s;
		cout << saldo << endl;
	}
}

// se define la función getSaldo, la cual devuelve el saldo actual en la cuenta
void base_acc::getSaldo() const {
	cout << "Saldo total: $" << saldo << endl;
}
