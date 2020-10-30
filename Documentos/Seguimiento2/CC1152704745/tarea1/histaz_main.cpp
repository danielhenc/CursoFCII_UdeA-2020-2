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
	const char *arrSust[10] = {"ninio","senior","perro","ciudad","carro","capucho","agente del ESMAD","papa bomba","zapato","empanada"};
	const char *arrVrb[10] = {"manejo","salto","corrio","camino","paso","se comio","se esfumo","zumbo","enseño","se escapo"};
	const char *arrPrep[10] = {"a","desde","encima","bajo","sobre","contra","hacia","junto","tras","a través"};

	const char *arrConect[5] = {"entonces ","luego ","pero ","sin saberlo ","mientras "};


	const char *arrConectF[5] = {"Finalmente ","Sin esperarse ","Cuando se creyo todo perdido ","Valientemente ","Asi pues "};

	const int len_h = 1000;  // longitud máxima de las horias

	// cadena de caracteres para guardar la historia
	
	char hist[len_h] = "";
	int comienzo = 1 + rand() % 2; // número aleatorio entre 1 y 2 para decidir el comienzo de la horia

	if (comienzo == 1){
		strcat(hist,"Era martes en la tarde y llovia. ");
	}
	else{
		strcat(hist,"En la intersección yacían todos los carros detenidos. ");
	}
	
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
	
	strcat(hist,f_art1);
	hist[5] = ' '; // se estaba añadiendo un caracter adicional en esta posición

	// se añaden las demás palabras

	int art2 = rand_num(0);    // números aleatorios para las demás palabras
	int sust1 = rand_num(2);
	int sust2 = rand_num(2);
	int vrb = rand_num(2);
	int prep = rand_num(2);


	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,", ");

	// se añade una frase adicional con un conector

	int con1 = rand_num(1);	
	art1 = rand_num(0); 
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,arrConect[con1]);
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist," ");

	// se añade una frase adicional con un conector

	art1 = rand_num(0);
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,"y ");
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,", ");

	// se añade una frase adicional con un conector

	con1 = rand_num(1);	
	art1 = rand_num(0); 
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,arrConect[con1]);
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,". ");

	// Se añade otro ciclo como el anterior.

	// se guarda el primer artículo en una cadena de chars para poner el primero en mayúscula
	art1 = rand_num(0);
	char f_art2[5] = {char(toupper(arrArt[art1][0]))};  // se guarda el primer char en mayúscula

	for (int j=1; j <= sizeof(f_art1); j++){
		// se añaden los demás chars dela artículo
		f_art2[j] = arrArt[art1][j];
		if (int(arrArt[art1][j]) == 0){
			// si se llega al final del artículo, se sale del for
			break;
		}
	}
	
	strcat(hist,f_art2);
	hist[5] = ' '; // se estaba añadiendo un caracter adicional en esta posición

	// se añaden las demás palabras

	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);


	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,", ");

	// se añade una frase adicional con un conector

	con1 = rand_num(1);	
	art1 = rand_num(0); 
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,arrConect[con1]);
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist," ");

	// se añade una frase adicional con un conector

	art1 = rand_num(0);
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,"y ");
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,", ");

	// se añade una frase adicional con un conector

	con1 = rand_num(1);	
	art1 = rand_num(0); 
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,arrConect[con1]);
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,". ");

	// se añade la parte final de la historia
	
	con1 = rand_num(1);	
	art1 = rand_num(0); 
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,arrConectF[con1]);
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist," ");

	// se añade una frase adicional con un conector

	art1 = rand_num(0);
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,"y ");
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,", ");

	// se añade una frase adicional con un conector

	con1 = rand_num(1);	
	art1 = rand_num(0); 
	art2 = rand_num(0);    // números aleatorios para las demás palabras
	sust1 = rand_num(2);
	sust2 = rand_num(2);
	vrb = rand_num(2);
	prep = rand_num(2);

	strcat(hist,arrConect[con1]);
	strcat(hist,arrArt[art1]);
	strcat(hist," ");
	strcat(hist,arrSust[sust1]);
	strcat(hist," ");
	strcat(hist,arrVrb[vrb]);
	strcat(hist," ");
	strcat(hist,arrPrep[prep]);
	strcat(hist," ");
	strcat(hist,arrArt[art2]);
	strcat(hist," ");
	strcat(hist,arrSust[sust2]);
	strcat(hist,". ");


	cout << hist << endl;
	
	return 0;
}


// -------------------- Funciones -----------------------------------------------------------------------------------

int rand_num(int n){
	// Genera números aleatorios dependiendo si n es 0 o cualquier otr número distinto
	switch(n){
		case 0:
			// números aleatorios del 0 al 3 para elegir los artículos
			return rand() % 3;
			break;

		case 1:
			// números aleatorios del 0 al 4 para elegir los conectores
			return rand() % 4;
			break;
	
		case 2:
			// números aleatorios del 0 al 9 para elegir las demás palabras
			return rand() % 9;
			break;
		
		default:
			return 0;
	}	
}
