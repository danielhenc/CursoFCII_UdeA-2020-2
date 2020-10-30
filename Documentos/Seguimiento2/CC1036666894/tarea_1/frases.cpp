#include <iostream>
#include <cstring>   
#include <ctime>  

using namespace std;

int main()
{
  srand(time(NULL));  //Numeros aleatorios

  //punteros constantes a chars constantes
  const char *const articulo[4] = {"el", "un", "algun","ningun"};		   
  const char *const sustantivo[5] = {" ninio", " senior", " perro", " ciudad", " auto"};      
  const char *const verbo[5] = {" manejo", " salto", " corrio", " camino", " paso"};	
  const char *const preposicion[5] = {" a ", " desde ", " encima de ", " debajo de ", " sobre "};
  char enunciado[200]= {}; //Donde se almacenaran las frases
  for(int i=1; i<=20; i++)  //Para 20 oraciones
    {
      //concatenacion de frases con las palabras aleatorias en el orden indicado
      //Se suma un numero aleatorio a la primera posicion de memoria
      //y luego se desreferencia y concatena con enunciado
      strcat(enunciado, *(articulo + rand()%4));
      strcat(enunciado, *(sustantivo + rand()%5));
      strcat(enunciado, *(verbo + rand()%5));
      strcat(enunciado, *(preposicion + rand()%5));
      strcat(enunciado, *(articulo + rand()%4));
      strcat(enunciado, *(sustantivo + rand()%5));
      enunciado[0] = toupper(enunciado[0]); //pone la primera letra de cada frase en mayuscula
      
      cout << enunciado << "." << endl;
      
      memset(enunciado, 0, sizeof enunciado);  //para limpar enunciado en cada ciclo

    }
  
  return 0;
}
