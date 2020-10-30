// Seguimiento 2_1_a Daniel Estrada Acevedo

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cstring>

// Macro to calculate the size of the array
#define len(array) sizeof(array)/sizeof(array[0]) 

using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{	
	srand(time(NULL)); //initializartion of random seed

	// ===== preset words to generate the sentences ======
	const char (*article[]) = {"el ", "un ", "algun ", "ningun "}; 
	const char (*noun[]) = {"ninio ", "senior ", "perro ", "ciudad ", "auto "};
	const char (*verb[]) = {"manejo ", "salto ", "corrio ", "camino ", "paso "};
	const char (*preposition[]) = {"a ", "desde ", "encima de ", "debajo de ", "sobre "};
	// ===================================================
	
	int art_num, sus_num, verb_num, prep_num, art2_num, sus2_num;
	char sentence[200] = {0}; // Char array to concatenate the words
	char aux_word[20] = {0}; // Auxiliary char array used to capitalize the first word or add . in last one


	for (int i = 0; i < 20; i++){

		//==== random indexes to make the sentence ====
		art_num = rand()%len(article);
		sus_num = rand()%len(noun);
		verb_num = rand()%len(verb);
		prep_num = rand()%len(preposition);
		art2_num = rand()%len(article);
		sus2_num = rand()%len(noun);
		//=============================================
		

		strcpy(aux_word,*(article + art_num));
		aux_word[0] = toupper(aux_word[0]); //capitalizing
		strcat(sentence, aux_word);
		
		strcat(sentence, *(noun + sus_num));
		strcat(sentence, *(verb + verb_num));
		strcat(sentence, *(preposition + prep_num));
		strcat(sentence, *(article+ art2_num));

		strcpy(aux_word,*(noun + sus2_num));
		aux_word[strlen(aux_word)-1] = '.'; // adding '.'
		strcat(sentence, aux_word);
		
		cout << "Oracion #" << i+1 << ": ";
		cout << sentence << endl;

		sentence[0] = 0; // cleaning the char array for put the follow sentence
	}

	return 0;
}
