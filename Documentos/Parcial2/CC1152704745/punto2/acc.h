#include <iostream>

using std::cout;
using std::endl;

#ifndef ACC_H
#define ACC_H

class base_acc {
	public:
	base_acc(double);
	
	void abonar(double);
	void cargar(double);
	void getSaldo() const;

	private:
	double saldo;
};

#endif
