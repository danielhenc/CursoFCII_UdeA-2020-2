#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <vector>
#include <string> 
#include <ctype.h>

using namespace std;


int main()
{ //primero se crean arreglos de caracteres que formen cada palabra:

	char ar1[]= "el/la";
	char ar2[]= "un(a)";
	char ar3[]= "algún(a)";
	char ar4[]= "ningún(a)";
	
	char sus1[]= "niño";
	char sus2[]= "señor";
	char sus3[]= "perro";
	char sus4[]= "ciudad";
	char sus5[]= "auto";
	char sus6[]= "casa";
	char sus7[]= "pared";
	char sus8[]= "laguna";
	char sus9[]= "sótano";
	char sus10[]= "viuda";
	
	char ver1[]= "manejó";
	char ver2[]= "saltó";
	char ver3[]= "corrió";
	char ver4[]= "caminó";
	char ver5[]= "pasó";
	char ver6[]= "nadó";
	char ver7[]= "abrió";
	char ver8[]= "mató";
	char ver9[]= "huyó";
	char ver10[]= "escondió";
	
	char pre1[]= "a";
	char pre2[]= "desde";
	char pre3[]= "encima de";
	char pre4[]= "debajo de";
	char pre5[]= "sobre";
	
	char con1[]= "entonces"; //se agregan conectores para formar frases compuestas
	char con2[]= "pero";
	char con3[]= "tal que";
	char con4[]= "y";
	char con5[]= "como";
	
	//se crean también los espacios, el punto, y la coma:
	char esp[]= " ";
	char pun[]= ". ";
	char co[]= ", ";
	
	//para hacer una asignación dinámica de los arreglos que van a contener cada tipo de palabra:
	char *articulo[4], *sustantivo[10], *verbo[10], *preposicion[5], *conector[5]; 
	
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
	sustantivo[5]= sus6;
	sustantivo[6]= sus7;
	sustantivo[7]= sus8;
	sustantivo[8]= sus9;
	sustantivo[9]= sus10;
  
	verbo[0]= ver1;
	verbo[1]= ver2;
	verbo[2]= ver3;
	verbo[3]= ver4;
	verbo[4]= ver5;
	verbo[5]= ver6;
	verbo[6]= ver7;
	verbo[7]= ver8;
	verbo[8]= ver9;
	verbo[9]= ver10;
  
	preposicion[0]= pre1;
	preposicion[1]= pre2;
	preposicion[2]= pre3;
	preposicion[3]= pre4;
	preposicion[4]= pre5;
	
	conector[0]= con1;
	conector[1]= con2;
	conector[2]= con3;
	conector[3]= con4;
	conector[4]= con5;
	  
	srand(time(NULL)); //para los número aleatorios
	cout << "En un lugar remoto... " ;
	int j=0;
	while(j < 8){ //para crear 20 frases
		j++;
	char *frase1[12]; //en éste arreglo se van a formar las frases
	char *frase2[14];
	
	//se asignan las palabras en el orden estipulado, teniendo en cuenta espacios y punto, de cada tipo de palabras se selecciona una al azar:
	frase1[0]= articulo[rand()%4];
	frase1[1]= esp; 
	frase1[2]= sustantivo[rand()%10];
	frase1[3]= esp; 
	frase1[4]= verbo[rand()%10];
	frase1[5]= esp;
	frase1[6]= preposicion[rand()%5];
	frase1[7]= esp;
	frase1[8]= articulo[rand()%4];
	frase1[9]= esp;
	frase1[10]= sustantivo[rand()%10];
	frase1[11]= co;
	
	frase2[0]= conector[rand()%4];
	frase2[1]= esp; 
	frase2[2]= articulo[rand()%4];
	frase2[3]= esp; 
	frase2[4]= sustantivo[rand()%10];
	frase2[5]= esp; 
	frase2[6]= verbo[rand()%10];
	frase2[7]= esp;
	frase2[8]= preposicion[rand()%5];
	frase2[9]= esp;
	frase2[10]= articulo[rand()%4];
	frase2[11]= esp;
	frase2[12]= sustantivo[rand()%10];
	frase2[13]= pun;
	
	*frase1[0]= toupper(*frase1[0]); //para imprimir la primera letra en mayúscula
	cout << frase1[0]; 
	*frase1[8]= tolower(*frase1[8]); //como *frases[0] cambia a mayúscula las primeras letras de los artículos, hay que regresarla a minúscula para el resto de la frase
	*frase2[2]= tolower(*frase2[2]);
	*frase2[10]= tolower(*frase2[10]);
	for (int i=1; i<12; i++)
	cout << frase1[i];
	for (int i=0; i<14; i++)
	cout << frase2[i];
		}
	cout << "Fín." << endl;
	return 0; 
}
  
