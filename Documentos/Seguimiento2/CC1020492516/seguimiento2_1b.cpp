/*b) Una vez que escriba el programa anterior, modifíquelo para producir una historia breve que consista de varias de estas
oraciones (¿qué le parecería un escritor de tesis al azar?). */


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
const char *verbo[5] = {" manejo", " salto", " corrio", " camino", " paso"};	//5
const char *preposicion[5] = {" a ", " desde ", " encima de ", " debajo de ", " sobre "};//5
const char *conector[5] = {" después "," imediatamente ", " allí ", " y por su puesto "," entonces "};
const char *fin[5] = {"murió.","vivió feliz.","disparó.","durmió.","explotó."};


char total[1000]={};

for(int i = 0; i<4; i++){

  int r[7] = {rand()%4,rand()%5,rand()%5,rand()%5,rand()%4,rand()%5,rand()%5};

  //int tot = strlen(articulo[r[0]]) + strlen(sustantivo[r[1]]) + strlen(verbo[r[2]]) + strlen(preposicion[r[3]]) + strlen(articulo[r[4]]) + strlen( sustantivo[ r[5] ] );

  strcat( total,articulo[r[0]] );
  strcat( total,sustantivo[r[0]] );
  strcat( total,verbo[r[2]] );
  strcat( total,preposicion[r[3]] );
  strcat( total,articulo[r[4]] );
  strcat( total,sustantivo[r[5]] );
  strcat( total, conector[r[6]] );
				}
	int rf = rand()%5;
	total[0] = char(toupper(total[0]));
	cout<<total<<fin[rf]<<endl;
 
 return 0; 
}
