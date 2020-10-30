#include <iostream>
#include <cstring>
#include <cstdlib>  // rand
#include <ctime>  // time
#include <cctype>  // toupper

using namespace std;

// prototypes
void sentence( char * );


int main(){

	int num, tamano;  // number of sentence in the paragraph

	cout << "Introduzca cuantas oraciones quiere que tenga el parrafo" << endl;
	cin >> num;

	srand(time(NULL));  // initial seed
	tamano = num*50;  // size of the paragraph array
	char paragraph[tamano];

	for(int i=0; i<num; i++){

		sentence(paragraph);  // add every sentence to the paragraph
	}

	cout << paragraph << endl;  // I don't understand why this works with "paragraph" and not "*paragraph"

	return 0;

}

void sentence(char *paragraph){
	// this function creates a sentence using premade arrays

	int end_sentence;

	// initialization of pointers
	char articulo[4][7] = {"el", "un", "algun", "ningun"};
	char sustantivo[5][7] = {"ninio", "senior", "perro", "ciudad", "auto"};
	char verbo[5][7] = {"manejo", "salto", "corrio", "camino", "paso"};
	char preposicion[5][10] = {"a", "desde", "encima de", "debajo de", "sobre"};
	char separacion[4][3] = {" ", ", ", ". ", ".\n"};
	char oracion[200] = {NULL};  // will contain the concatenation

	// every sentence has random words in the following sequence: articulo, sustantivo, 
	//	verbo, preposición, articulo y sustantivo
	strcat(oracion, *(articulo + rand()%4));
	strcat(oracion, *separacion);  // add an empty space after every word
	strcat(oracion, *(sustantivo + rand()%5));
	strcat(oracion, *separacion);
	strcat(oracion, *(verbo + rand()%5));
	strcat(oracion, *separacion);
	strcat(oracion, *(preposicion + rand()%5));
	strcat(oracion, *separacion);
	strcat(oracion, *(articulo + rand()%4));
	strcat(oracion, *separacion);
	strcat(oracion, *(sustantivo + rand()%5));

	// add random separation between every sentence
	end_sentence = 1 + rand()%3;
	strcat(oracion, *(separacion + end_sentence));
	*oracion = std::toupper(*oracion);  //Capitalizing

	strcat(paragraph, oracion);  // saving the new sentence in paragraph
}