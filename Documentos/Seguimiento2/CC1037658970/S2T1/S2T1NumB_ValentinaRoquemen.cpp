/**
 * @author Valentina Roquemen Echeverry
 * @brief Se crea un programa que genera historias
 *        de forma aleatoria con la estructura
 *        articulo+sustantivo+verbo+preposicion+articulo+sustantivo.
 *        Se imprime una historia con n parrafos y cada uno con m
 *        frases que pueden ser impuestas por el usuario.
 */

#include <iostream>
#include <time.h>
#include <cctype>
#include <string.h>

using namespace std;

int main()
{
  srand(time(NULL)); // Semilla para generar los numeros aleatorios

  /*Se definen los arreglos de apuntadores a char de articulos, sustantivos, verbos y preposiciones*/
  const char *articulos[] = {"el","un","algun","ningun","la","los","un"};
  const char *sustantivos[]= {"ninio","senior","perro","ciudadano","auto","Hitler","conceptualizacion","gato","morado","amigo"};
  const char *verbos[] = {"manejo","salto","corrio","camino","paso","mato","configuro","volo","creyo"};
  const char *preposiciones[] = {"a","desde","encima de","debajo de","sobre","en","ante","de"};

  /*Se define cuantos elementos tienen los arreglos de articulos, sustantivos, verbos y preposiciones*/ 
  int lenA = sizeof(articulos)/sizeof(*articulos);
  int lenS = sizeof(sustantivos)/sizeof(*sustantivos);
  int lenV = sizeof(verbos)/sizeof(*verbos);
  int lenP = sizeof(preposiciones)/sizeof(*preposiciones);

  char oracion[200]; // Char que va a contener la oracion

  int parrafos[] = {10,13,7}; // Arreglo de entero, cada entrada indica cuantas oraciones tendra cada parrafo

  // Ciclo para generar cada parrafo
  for (int p = 0; p < sizeof(parrafos)/sizeof(*parrafos); ++p)
  {
    
    // Ciclo para generar las frases de cada parrafo 
    for (int f = 0; f <parrafos[p] ; ++f)
      {
        /*Se concatenan los elementos de la oracion, en cada caso se genera de forma aleatoria la posicion del arreglo a la cual se va a acceder*/
        strcpy (oracion, *(articulos+rand()%lenA));
        strcat (oracion," ");
        strcat (oracion,*(sustantivos+rand()%lenS));
        strcat (oracion," ");
        strcat (oracion,*(verbos+rand()%lenV));
        strcat (oracion," ");
        strcat (oracion,*(preposiciones+rand()%lenP));
        strcat (oracion," ");
        strcat (oracion,*(articulos+rand()%lenA));
        strcat (oracion," ");
        strcat (oracion,*(sustantivos+rand()%lenS));
        strcat (oracion,". ");

        *oracion = toupper( *oracion ); // Se hace que la primera letra de la oracion sea mayuscula

        cout<<oracion; // Se imprime la oracion
      }  
      cout<<"\n"<<endl;
  }


  return 0;
}
