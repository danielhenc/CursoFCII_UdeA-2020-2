#include <iostream>
#include <string>

namespace infunc{
	
	// Función para obtener la parte entera de un número real
	int get_int_part(double num){
		int cast_int = num;  // se hace un cast de la variable double a tipo entero

		return cast_int;
	}

	double get_frac_part(double num){
		int int_part = get_int_part(num);  // se hace un cast de la variable double a tipo entero
		double frac_part = num - double(int_part);  // se resta la parte entera del número real

		return frac_part;
	}
}
