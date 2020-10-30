#include<iostream>
#include<cstring>
#include<random>
#include<ctime>

using namespace std;

int main()
{
	//Arreglos de apuntadores
	const char *articulo[4] = {"el" , "un" , "algun" , "ningun"};
	const char *sustantivo[5] = {"ninio" , "senior" , "perro" , "ciudad" , "auto"};
	const char *verbo[5] = {"manejo" , "salto" , "corrio" , "camino" , "paso"};
	const char *preposicion[5] = {"a" , "desde" , "encima de" , "debajo de" , "sobre"};

	//Arreglo de caracteres para almacenar el enunciado final
	char enunciado[50] = {};

	//Arreglo que almacena los numeros aleatorios que generaran el enunciado
	int generador[6];

	srand(time(NULL));

	//Ciclo para generar 20 enunciados diferentes
	for(int i = 1 ; i <= 20 ; i++)
	{
		//Numeros aleatorios para:

		//Articulo
		generador[0] = rand()%4;
		//Sustantivo
		generador[1] = rand()%5;
		//Verbo
		generador[2] = rand()%5;
		//Preprosicion
		generador[3] = rand()%5;
		//Articulo
		generador[4] = rand()%4;
		//Sustantivo
		generador[5] = rand()%5;

		//Primer palabra del enunciado
		strcat(enunciado, articulo[generador[0]]);
		enunciado[0] = toupper(articulo[generador[0]][0]);
		strcat(enunciado, " ");
    
		//Resto del enunciado
		strcat(enunciado, sustantivo[generador[1]]);
		strcat(enunciado, " ");
		strcat(enunciado, verbo[generador[2]]);
		strcat(enunciado, " ");
		strcat(enunciado, preposicion[generador[3]]);
		strcat(enunciado, " ");
		strcat(enunciado, articulo[generador[4]]);
		strcat(enunciado, " ");
		strcat(enunciado, sustantivo[generador[5]]);
		strcat(enunciado, ".");
    
		//Imprimir enunciado
		cout << enunciado << "\n";
    
		//Reinicial arreglo
		enunciado[0] = {};
	}
	return 0;
}
