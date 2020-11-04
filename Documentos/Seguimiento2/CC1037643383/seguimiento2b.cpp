#include <iostream>
#include <cstring> 
#include <string>  
#include <ctime>  
#include <cctype>

using namespace std;

int main()
{
  srand(time(NULL));  

  const char *articulo[4] = {"el", "un", "algun","ningun"};			
  const char *sustantivo[5] = {" niño", " señor", " perro", " ciudad", " auto"};     
  const char *verbo[5] = {" manejo", " salto", " corrio", " camino", " paso"};	
  const char *preposicion[5] = {" a ", " desde ", " encima de ", " debajo de ", " sobre "};
  char espacio[2] = {" "};
  char enunciado[500] = {};
  char coma[2] = {","};

for(int i = 0; i<10; i++)
  {

    strcat(enunciado,*(articulo + rand()%4));
    strcat(enunciado,*(sustantivo + rand()%5));
    strcat(enunciado,*(verbo + rand()%5));
    strcat(enunciado,*(preposicion + rand()%5));
    strcat(enunciado,*(articulo + rand()%4));
    strcat(enunciado,*(sustantivo + rand()%5));
    strcat(enunciado, coma);
    strcat(enunciado, espacio);

    if(i==9)
      {
	strcat(enunciado,*(articulo + rand()%4));
	strcat(enunciado,*(sustantivo + rand()%5));
	strcat(enunciado,*(verbo + rand()%5));
	strcat(enunciado,*(preposicion + rand()%5));
	strcat(enunciado,*(articulo + rand()%4));
	strcat(enunciado,*(sustantivo + rand()%5));
      }
  }
				
   
	enunciado[0] = toupper(enunciado[0]);
	cout<<enunciado<< "." <<endl;
 
 return 0; 
}
