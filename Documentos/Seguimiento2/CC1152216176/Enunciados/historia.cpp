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

	//Arreglo de caracteres para almacenar la historia
	char historia[250] = {};

	//Arreglo que almacena los numeros aleatorios que generaran cada enunciado
	int generador[6];

	srand(time(NULL));

	//Ciclo para generar 5 enunciados diferentes para formar la historia
	for(int i = 1 ; i <= 5 ; i++)
	{
		//Numeros aleatorios para cada enunciado:

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
		strcat(historia, articulo[generador[0]]);
		//Si es la primer palabra de la historia va en mayuscula
		if (i==1) historia[0] = toupper(articulo[generador[0]][0]);
		strcat(historia, " ");
    
		//Resto del enunciado
		strcat(historia, sustantivo[generador[1]]);
		strcat(historia, " ");
		strcat(historia, verbo[generador[2]]);
		strcat(historia, " ");
		strcat(historia, preposicion[generador[3]]);
		strcat(historia, " ");
		strcat(historia, articulo[generador[4]]);
		strcat(historia, " ");
		strcat(historia, sustantivo[generador[5]]);

		//Si es el ultimo enunciado de la historia termina en punto final
		if (i==5) strcat(historia, ".");
		//De lo contrario se pone una coma y un espacio
		else strcat(historia, ", ");
	}
	//Imprimir historia
	cout << historia << "\n";
	return 0;
}
