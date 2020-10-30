#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

using std::srand;
using std::cout;
using std::cin;
using std::endl;
using std::toupper;
using std::strcat;

int rand_num(int);

int main(){
	srand(time(NULL));

	// arreglos de apuntadores a las cadenas de caracteres

	const char *arrArt[4] = {"el","un","algun","ningun"};
	const char *arrSust[5] = {"ninio","senior","perro","ciudad","carro"};
	const char *arrVrb[5] = {"manejo","salto","corrio","camino","paso"};
	const char *arrPrep[5] = {"a","desde","encima","bajo","sobre"};

	const int len_fras = 30;  // longitud máxima de las frases
	const int num_fras = 20;  // número de frases a generar

	for (int i=0; i < num_fras; i++){	
		char fras[len_fras] = "";   // arreglo para guardar las frases

		
		// se guarda el primer artículo en una cadena de chars para poner el primero en mayúscula
		int art1 = rand_num(0);
		char f_art1[5] = {char(toupper(arrArt[art1][0]))};  // se guarda el primer char en mayúscula

		for (int j=1; j <= sizeof(f_art1); j++){
			// se añaden los demás chars dela artículo
			f_art1[j] = arrArt[art1][j];
			if (int(arrArt[art1][j]) == 0){
				// si se llega al final del artículo, se sale del for
				break;
			}
		}
	
		strcat(fras,f_art1);
		fras[5] = ' '; // se estaba añadiendo un caracter adicional en esta posición

		// se añaden las demás palabras

		int art2 = rand_num(0);    // números aleatorios para las demás palabras
		int sust1 = rand_num(1);
		int sust2 = rand_num(1);
		int vrb = rand_num(1);
		int prep = rand_num(1);


		strcat(fras," ");
		strcat(fras,arrSust[sust1]);
		strcat(fras," ");
		strcat(fras,arrVrb[vrb]);
		strcat(fras," ");
		strcat(fras,arrPrep[prep]);
		strcat(fras," ");
		strcat(fras,arrArt[art2]);
		strcat(fras," ");
		strcat(fras,arrSust[sust2]);
		strcat(fras,".");

		// finalmente se imprime cada frase

		cout << fras << endl;
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

