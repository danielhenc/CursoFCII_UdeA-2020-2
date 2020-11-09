#include <iomanip>
#include "intfrac_func.cpp"

using namespace infunc;
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main(){
	// arreglo de números reales de prueba
	double n_test[10] = {235.1234,23.513,3.124,0.4341,22.6523,2345.3,666.666,5513.745,123.525,6.6};

	// prueba de las funciones definidas
	for (int i=0; i<10; i++){
		
		int int_part = get_int_part(n_test[i]); // calculo de la parte entera
		double frac_part = get_frac_part(n_test[i]); // calculo de la parte fraccionaria

		// impresión de los resultados
		cout << setw(8) << "Numero: " << setw(8) <<  n_test[i];
		cout << setw(14) << "\tParte entera: " << setw(8) << int_part;
		cout << setw(20) << "\tParte fraccionaria: " << setw(8) << frac_part << endl;

		}

	return 0;
}

