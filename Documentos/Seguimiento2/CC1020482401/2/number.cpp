#include <iostream>

namespace numComponents{
	
	int entero(double number){
		return number;
	}

	double partefracc(double number){
		return number - entero(number);
	}
}