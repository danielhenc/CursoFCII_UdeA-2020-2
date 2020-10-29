/*
Generador de frases y textos aleatorios usando apuntadores en arreglos 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring> 

using namespace std;

void randomSentence( void );  // prototipo de función 

int main()
{
	int Nfrase = 5; //número de frases en texto 
	int userA; 

	srand( time( NULL ) ); //semilla 

	cout << "Ingrese 0 para una frase o 1 para un texto de " << Nfrase << " frases" << endl;
	cin >> userA;

	if( userA == 0 )
	{
		randomSentence(); 
	}
	else if ( userA == 1 )
	{
		for( int i=0; i<Nfrase; i++)
		{
			randomSentence(); 
		}
	}

	return 0;
}


void randomSentence( void ) //genera la frase aleatoria 
{
	const char *articulo[4] = {"el", "un", "algun", "ningun"};
	const char *sustantivo[5] = {"ninio", "senior", "perro", "ciudad", "auto"};
	const char *verbo[5] = {"manejo", "salto", "corrio", "camino", "paso"}; 
	const char *preposicion[5] = {"a", "desde", "encima de", "debajo de", "sobre"};

	char frase[60] = ""; //inicializa la frase vacía

	//generamos números aleatorios
	int aR, sR, vR, pR, aR1, sR1;

	aR = rand() % 4; sR = rand() % 5; vR = rand() % 5; pR = rand() % 5;
	aR1 = rand() % 4; sR1 = rand() % 5;

	//construimos frase 
	strcat(frase, *(articulo +  aR)); strcat(frase, " "); //articulo
	strcat(frase, *(sustantivo +  sR)); strcat(frase, " "); //sustantivo
	strcat(frase, *(verbo +  vR)); strcat(frase, " "); //verbo
	strcat(frase, *(preposicion +  pR)); strcat(frase, " "); //preposición
	strcat(frase, *(articulo +  aR1)); strcat(frase, " "); //articulo 1
	strcat(frase, *(sustantivo +  sR1)); strcat(frase, ". "); //sustantivo 1

	frase[0] = toupper(frase[0]); //mayuscula al principio
	
	cout << frase; //imprime frase 

}
