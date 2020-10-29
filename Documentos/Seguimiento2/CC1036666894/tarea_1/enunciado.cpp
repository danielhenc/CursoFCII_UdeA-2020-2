#include <iostream>
#include <cstring>   
#include <ctime>  

using namespace std;

int main()
{
  
  srand(time(NULL));  //Numeros aleatorios

  //Apuntadores constantes a chars constantes
  const char *const articulo[4] = {"el", "un", "algun","ningun"};			
  const char *const sustantivo[5] = {" ninio", " senior", " perro", " ciudad", " auto"};     
  const char *const verbo[5] = {" manejo", " salto", " corrio", " camino", " paso"};	
  const char *const preposicion[5] = {" a ", " desde ", " encima de ", " debajo de ", " sobre "};
  char enunciado[1000] = {};  //Donde se almacena el texto
  char coma[3] = {", "};  //agregar comas al texto

for(int i = 1; i<=25; i++)
  {
    //Concatenacion del enunciado
    //Suma un numero aleatorio a la posicion de memoria de cada tipo de palabra
    //y lo desreferencia y concatena con enunciado
    strcat(enunciado, *(articulo + rand()%4));
    strcat(enunciado, *(sustantivo + rand()%5));
    strcat(enunciado, *(verbo + rand()%5));
    strcat(enunciado, *(preposicion + rand()%5));
    strcat(enunciado, *(articulo + rand()%4));
    strcat(enunciado, *(sustantivo + rand()%5));
    strcat(enunciado, coma);
  }
//ultima parte del enunciado, para finalizar con .
 strcat(enunciado, *(articulo + rand()%4));
 strcat(enunciado, *(sustantivo + rand()%5));
 strcat(enunciado, *(verbo + rand()%5));
 strcat(enunciado, *(preposicion + rand()%5));
 strcat(enunciado, *(articulo + rand()%4));
 strcat(enunciado, *(sustantivo + rand()%5));
 enunciado[0] = toupper(enunciado[0]);  //poner mayuscula la primera letra del enunciado
 cout << enunciado << "." <<endl;
 
 return 0;
 
}
