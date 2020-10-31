#include <iostream>
#include <cstring>
#include <cstdlib>  // rand
#include <ctime>  // time
#include <cctype>  // toupper

using namespace std;

int main(){

	srand(time(NULL));  // initial seed

	// initialization of pointers
	char articulo[4][7] = {"el", "un", "algun", "ningun"};
	char sustantivo[5][7] = {"ninio", "senior", "perro", "ciudad", "auto"};
	char verbo[5][7] = {"manejo", "salto", "corrio", "camino", "paso"};
	char preposicion[5][10] = {"a", "desde", "encima de", "debajo de", "sobre"};
	char espacio[2] = {" "};
	char punto[2] = {"."};
	char oracion[200] = {NULL};  // will contain the concatenation

	// add every word, spaces and the dot to oracion
	strcat(oracion, *(articulo + rand()%4));
	strcat(oracion, espacio);
	strcat(oracion, *(sustantivo + rand()%5));
	strcat(oracion, espacio);
	strcat(oracion, *(verbo + rand()%5));
	strcat(oracion, espacio);
	strcat(oracion, *(preposicion + rand()%5));
	strcat(oracion, espacio);
	strcat(oracion, *(articulo + rand()%4));
	strcat(oracion, espacio);
	strcat(oracion, *(sustantivo + rand()%5));
	strcat(oracion, punto);

	*oracion = std::toupper(*oracion);  //Capitalizing

	cout << oracion << endl;

	return 0;

}