// Seguimiento 2_1_b Daniel Estrada Acevedo

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cstring>

// Macro to calculate the size of the array
#define len(array) sizeof(array)/sizeof(array[0]) 

using std::cout;
using std::endl;

// ===== preset words to generate the sentences ======
const char (*article[]) = {"el ", "un ", "algun ", "ningun "}; 
const char (*noun[]) = {"ninio ", "senior ", "perro ", "ciudad ", "auto "};
const char (*verb[]) = {"manejo ", "salto ", "corrio ", "camino ", "paso "};
const char (*preposition[]) = {"a ", "desde ", "encima de ", "debajo de ", "sobre "};
const char (*connector[]) = {"además, ", "pero, ", "sin embargo, ", "es decir, ", "por tanto, "};
const char (*puntuation[]) = {", ", ". ", ".\n"};
// ===================================================


void concat_sentence(char *, bool *, bool *, bool);


int main(int argc, char const *argv[])
{	
	srand(time(NULL)); //initializartion of random seed
	
	bool start = true, end = false;
	bool capitalize = false;
	char paragraph[2000] = {0};

	for (int i = 0; i < 50; i++){ // a paragraph with 50 sentences
		if (i==19) end = true; 
		concat_sentence(paragraph, &capitalize, &start, end);
		
	}	

	cout << paragraph << endl;

	return 0;
}


void concat_sentence(char *paragraph, bool *capitalize, bool *start, bool end){
	
	int art_num, noun_num, verb_num, prep_num, art2_num, noun2_num, connt_num, punt_num;
	char sentence[500] = {0}; // Char array to concatenate the words
	char aux_word[30] = {0}; // Auxiliary char array used to capitalize the first word or add . in last one

	//==== random indexes to make the sentence ====
	art_num = rand()%len(article);
	noun_num = rand()%len(noun);
	verb_num = rand()%len(verb);
	prep_num = rand()%len(preposition);
	art2_num = rand()%len(article);
	noun2_num = rand()%len(noun);
	connt_num = rand()%len(connector);
	punt_num = rand()%len(puntuation);
	//=============================================
	
	
	if (*start){ // start indicate when begin with article instead of connector
		strcpy(aux_word,*(article + art_num));
		aux_word[0] = toupper(aux_word[0]); //capitalizing
		strcat(sentence, aux_word);
		*start = false;
	}
	else{

		if (*capitalize){
			strcpy(aux_word, *(connector + connt_num));
			aux_word[0] = toupper(aux_word[0]); //capitalizing
			strcat(sentence, aux_word);
		}
		else	
			strcat(sentence, *(connector + connt_num));
		
		strcat(sentence,*(article + art_num));
	}

	strcat(sentence, *(noun + noun_num));
	strcat(sentence, *(verb + verb_num));
	strcat(sentence, *(preposition + prep_num));
	strcat(sentence, *(article+ art2_num));

	strcpy(aux_word,*(noun + noun2_num));
	
	if (end) // if is the end of paragraph the punctuation sign is '.'
		strcat(aux_word, puntuation[2]); // adding ".\n"	
	else{
		cout << aux_word << "   " << *(puntuation + punt_num) << endl ;
		strcat(aux_word, *(puntuation + punt_num)); // adding puntation sign
		if ( strcmp(*(puntuation + punt_num),".\n") == 0) *start = true;
		if ( strcmp(*(puntuation + punt_num),". " ) == 0 or *start) *capitalize = true;
	}

	strcat(sentence, aux_word);

	strcat(paragraph, sentence);// adding the generated sentence to paragraph
}
