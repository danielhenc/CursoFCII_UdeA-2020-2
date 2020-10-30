#include <iostream>

using namespace std;

namespace PartesNumeros{
	
	int entero(float x){ //para mostrar la parte entera de un número
		
		int y= x;
		
		return y;
		}
	
	float partefracc(float x){ //para mostrar su parte decimal
		
		int y= entero(x);
		float z= (x - y);
		
		return z;
		}

	}
