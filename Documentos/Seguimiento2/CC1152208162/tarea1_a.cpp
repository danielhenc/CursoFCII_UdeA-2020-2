#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <vector>
#include <string> 
#include <ctype.h>

using namespace std;


int main()
{ //primero se crean arreglos de caracteres que formen cada palabra:

	char ar1[]= "el";
	char ar2[]= "un";
	char ar3[]= "algún";
	char ar4[]= "ningún";
	
	char sus1[]= "niño";
	char sus2[]= "señor";
	char sus3[]= "perro";
	char sus4[]= "ciudad";
	char sus5[]= "auto";
	
	char ver1[]= "manejó";
	char ver2[]= "saltó";
	char ver3[]= "corrió";
	char ver4[]= "caminó";
	char ver5[]= "pasó";
	
	char pre1[]= "a";
	char pre2[]= "desde";
	char pre3[]= "encima de";
	char pre4[]= "debajo de";
	char pre5[]= "sobre";
	
	//se crean también los espacios y el punto:
	char esp[]= " ";
	char pun[]= ". ";
	
	//para hacer una asignación dinámica de los arreglos que van a contener cada tipo de palabra:
	char *articulo[4], *sustantivo[5], *verbo[5], *preposicion[5]; 
	
	//se asignan las palabras correspondientes a cada arreglo:
	articulo[0]= ar1;
	articulo[1]= ar2;
	articulo[2]= ar3;
	articulo[3]= ar4;
  
	sustantivo[0]= sus1;
	sustantivo[1]= sus2;
	sustantivo[2]= sus3;
	sustantivo[3]= sus4;
	sustantivo[4]= sus5;
  
	verbo[0]= ver1;
	verbo[1]= ver2;
	verbo[2]= ver3;
	verbo[3]= ver4;
	verbo[4]= ver5;
  
	preposicion[0]= pre1;
	preposicion[1]= pre2;
	preposicion[2]= pre3;
	preposicion[3]= pre4;
	preposicion[4]= pre5;
	  
	srand(time(NULL)); //para los número aleatorios
	
	int j=0;
	while(j < 20){ //para crear 20 frases
		j++;
	char *frases[12]; //en éste arreglo se van a formar las frases
	
	//se asignan las palabras en el orden estipulado, teniendo en cuenta espacios y punto, de cada tipo de palabras se selecciona una al azar:
	frases[0]= articulo[rand()%4];
	frases[1]= esp; 
	frases[2]= sustantivo[rand()%5];
	frases[3]= esp; 
	frases[4]= verbo[rand()%5];
	frases[5]= esp;
	frases[6]= preposicion[rand()%5];
	frases[7]= esp;
	frases[8]= articulo[rand()%4];
	frases[9]= esp;
	frases[10]= sustantivo[rand()%5];
	frases[11]= pun;
	
	*frases[0]= toupper(*frases[0]); //para imprimir la primera letra en mayúscula
	cout << frases[0]; 
	*frases[8]= tolower(*frases[8]); //como *frases[0] cambia a mayúscula las primeras letras de los artículos, hay que regresarla a minúscula para el resto de la frase
	cout << frases[1] << frases[2] << frases[3] << frases[4] << frases[5] << frases[6] << frases[7] << frases[8] << frases[9] 
	<< frases[10] << frases[11] << endl;

		}

	return 0; 
}
  
