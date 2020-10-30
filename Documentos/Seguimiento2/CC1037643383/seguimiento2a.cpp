#include <iostream>
#include <cstring> 
#include <string>  
#include <ctime>  
#include <cctype>

using namespace std;

int main()
{
   srand(time(NULL)); 

   const char *articulo[4] = {"el", "un", "algun","ningun"}; //Creamos los punteros		   
   const char *sustantivo[5] = {" niño", " señor", " perro", " ciudad", " auto"};      
   const char *verbo[5] = {" manejo", " salto", " corrio", " camino", " paso"};	
   const char *preposicion[5] = {" a ", " desde ", " encima de ", " debajo de ", " sobre "};
   char enunciado[150] = {NULL};
   for(int i=0; i<20; i++)
     {
   //Dado que sabemos las posiciones que vamos a imprimir, podemos ubicar los espacios en cada artículo, sustantivo, verbo, preposición.
   //De manera que quede bien cuando imprimamos el enunciado.
       strcat(enunciado, *(articulo + rand()%4));
       strcat(enunciado, *(sustantivo + rand()%5)); //Concatenamos para formar el enunciado
       strcat(enunciado, *(verbo + rand()%5));
       strcat(enunciado, *(preposicion + rand()%5));
       strcat(enunciado, *(articulo + rand()%4));
       strcat(enunciado, *(sustantivo + rand()%5));
       *enunciado = toupper(*enunciado); //Agrega el primer término en mayúscula 

       cout << enunciado << "." << endl;
       enunciado[0] = 0;

	
     }

   return 0;

}
