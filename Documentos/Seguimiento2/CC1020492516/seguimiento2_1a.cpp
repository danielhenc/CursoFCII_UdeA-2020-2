/*
a) Escriba un programa que utilice la generación de números aleatorios para crear enunciados. El programa debe usar
cuatro arreglos de apuntadores a char llamados articulo, sustantivo, verbo y preposicion. El programa debe crear un
enunciado, seleccionando una palabra al azar de cada arreglo en el siguiente orden: articulo, sustantivo, verbo, preposición,
articulo y sustantivo. A medida que se seleccione cada palabra, debe concatenarse con las palabras anteriores en un
arreglo de caracteres que sea lo bastante grande como para contener el enunciado completo. Las palabras deben separarse por
espacios. Cuando se imprima el enunciado final, deberá empezar con letra mayúscula y terminar con un punto. El programa
debe generar 20 enunciados de ese tipo.

Los arreglos deberán llenarse de la siguiente manera: el arreglo articulo debe contener los artículos "el", "un", "algun"
y "ningun"; el arreglo sustantivo deberá contener los sustantivos "ninio", "senior", "perro", "ciudad" y "auto"; el
arreglo verbo deberá contener los verbos "manejo", "salto", "corrio", "camino" y "paso"; el arreglo preposicion deberá
contener las preposiciones "a", "desde", "encima de", "debajo de" y "sobre".
*/

#include <iostream>
#include <cstring> 
#include <string> //nos permite meter frases en arreglos. Será útil para el código. 
#include <ctime>  // tiempo para la semilla
#include <cctype>

using namespace std;

int main()
{
  srand(time(0));  //Semilla

const char *articulo[4] = {"el", "un", "algun","ningun"};			//Arreglo de 4 cositos
const char *sustantivo[5] = {" niño", " señor", " perro", " ciudad", " auto"};     //5 cositos
const char *verbo[5] = {" manejo ", " salto ", " corrio ", " camino ", " paso "};	//5
const char *preposicion[5] = {"a ", "desde ", "encima de ", "debajo de ", "sobre "};//5

for(int i = 0; i<20; i++){

  int r[6] = {rand()%4,rand()%5,rand()%5,rand()%5,rand()%4,rand()%5};

  int tot = strlen(articulo[r[0]]) + strlen(sustantivo[r[1]]) + strlen(verbo[r[2]]) + strlen(preposicion[r[3]]) + strlen(articulo[r[4]]) + strlen( sustantivo[ r[5] ] );

  char total[tot]={};
  strcat( total,articulo[r[0]] );
  strcat( total,sustantivo[r[0]] );
  strcat( total,verbo[r[2]] );
  strcat( total,preposicion[r[3]] );
  strcat( total,articulo[r[4]] );
  strcat( total,sustantivo[r[5]] );
	total[0] = char(toupper(total[0]));
	cout<< total <<"."<<endl;
				}
 
 return 0; 
}
