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

const char *arrConect[5] = {"entonces ","luego ","sin embargo ","sin saberlo ","mientras "};

const char *arrSust2[5] = {"capucho","agente del ESMAD","papa bomba","zapato","empanada"};
const char *arrVrb2[5] = {"se comió","se esfumó","zumbó","enseñó","se escapó"};
const char *arrPrep2[5] = {"contra","hacia","junto","tras","a través"};

const char *arrConect2[5] = {"Finalmente","Sin esperarse","Cuando se creyó todo perdido","Al contrario","Así pues"};

int rand_num(int);      // Función para generar números aleatorios

void print_sentence0();  // Funciónes para generar una frase aleatoria
void print_sentence1();
void print_sentence2();
void print_sentence3();

void print_story();     // Función para generar una historia

int main(){
	srand(time(NULL));
	
	// Se genera la historia
	print_story();

	return 0;
}


// -------------------- Funciones -----------------------------------------------------------------------------------

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

void print_story(){
	int inicio = 1 + rand() % 2;
	int con1 = rand() % 4;
	int con2 = rand() % 4;

	int conF = rand() % 4;
	
	int conF1 = rand() % 4;
	int conF2 = rand() % 4;

	// Inicio de la historia, hay dos posibles

	if (inicio == 1){
		print_sentence0();
	}
	else{
		print_sentence1();
	}	

	// Cuerpo de la historia

	cout << ", " << arrConect[con1];
	print_sentence2();
	cout << ", y como ";
	print_sentence3();
	cout << ", ";
	print_sentence3();
	cout << ", y " << arrConect[con2];
	print_sentence2();
	cout << ". ";

	// Final de la historia

	cout << arrConect2[conF] << " " ;
	print_sentence3();
	cout << " puesto que ";
	print_sentence2();
	cout << ", " << arrConect[conF1];
	print_sentence3();
	cout << ", y " << arrConect[conF2];
	print_sentence2();
	cout << "." << endl;
}

void print_sentence0(){
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
	cout << "Era martes en la tarde y llovía. " << arrMayusArt[art1] << " " << arrSust[sust1] << " " << arrVrb[vrb] << " " << arrPrep[prep];
	cout  << " "  << arrArt[art2] << " " <<  arrSust[sust2];
}

void print_sentence1(){
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
	cout << "En la intersección yacían todos los carros detenidos. " << arrMayusArt[art1] << " " << arrSust2[sust1] << " " << arrVrb2[vrb] << " " << arrPrep2[prep];
	cout  << " "  << arrArt[art2] << " " <<  arrSust2[sust2];
}

void print_sentence2(){
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
	cout << arrArt[art1] << " " << arrSust2[sust1] << " " << arrVrb[vrb] << " " << arrPrep2[prep];
	cout  << " "  << arrArt[art2] << " " <<  arrSust[sust2];
}

void print_sentence3(){
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
	cout << arrArt[art1] << " " << arrSust[sust1] << " " << arrVrb2[vrb] << " " << arrPrep[prep];
	cout  << " "  << arrArt[art2] << " " <<  arrSust2[sust2];
}
