#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::srand;
using std::cout;
using std::cin;
using std::endl;
using std::toupper;

// arreglos de apuntadores a las cadenas de caracteres

const char *arrArt[4] = {"el","un","algún","ningún"};
const char *arrMayusArt[4] = {"El","Un","Algún","Ningún"};
const char *arrSust[5] = {"niño","señor","perro","ciudad","carro"};
const char *arrVrb[5] = {"manejó","saltó","corrió","caminó","pasó"};
const char *arrPrep[5] = {"a","desde","encima","bajo","sobre"};

int rand_num(int);      // Función para generar números aleatorios
void print_sentence();  // Función para generar una frase aleatoria

int main(){
	srand(time(NULL));

	for (int i=0; i < 20; i++){
		// ciclo para generar 20 frases aleatorias
		print_sentence();
	}

	return 0;
}


// ----------------------------- Funciones ---------------------------------------------------------

int rand_num(int n){
	// Genera números aleatorios dependiendo si n es 0 o cualquier otr número distinto
	if (n == 0){
		// Si n es 0, se generan números aleatorios del 0 al 3 para los 
		// arreglos que contienen los artículos
		return rand() % 3;
	}
	else{
		// Si n es distinto de 0, se generan números aleatorios del 0 al 4
		// para el resto de los arreglos
		return rand() % 4;
	}
}

void print_sentence(){
	// Función para generar frases aleatorias

	// Números aleatorios para escoger las palabras que conforman la frase
	int art1 = rand_num(0);
	int art2 = rand_num(0);
	int sust1 = rand_num(1);
	int sust2 = rand_num(1);
	int vrb = rand_num(1);
	int prep = rand_num(1);
	
	// Se imprime cada palabra y se arma la frase. El primer arreglo son los artículos
	// en mayúsculas, y se termina la frase con un punto.
	cout << arrMayusArt[art1] << " " << arrSust[sust1] << " " << arrVrb[vrb] << " " << arrPrep[prep];
	cout  << " "  << arrArt[art2] << " " <<  arrSust[sust2] << "."  << endl;
}
