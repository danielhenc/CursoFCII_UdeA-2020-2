/**
 * @author Valentina Roquemen Echeverry
 * @brief Se crea un programa que genera oraciones
 *        de forma aleatoria con la estructura
 *        articulo+sustantivo+verbo+preposicion+articulo+sustantivo.
 *        Se imprimen 20 oraciones generadas de esta manera.
 */

#include <iostream>
#include <time.h>
#include <cctype>
#include <string.h>

using namespace std;

int main()
{
  srand(time(NULL));// Semilla para generar los numeros aleatorios

  /*Se definen los arreglos de apuntadores a char de articulos, sustantivos, verbos y preposiciones*/
  const char *articulos[] = {"el","un","algun","ningun"};
  const char *sustantivos[]= {"ninio","senior","perro","ciudad","auto"};
  const char *verbos[] = {"manejo","salto","corrio","camino","paso"};
  const char *preposiciones[] = {"a","desde","encima de","debajo de","sobre"};

  /*Se define cuantos elementos tienen los arreglos de articulos, sustantivos, verbos y preposiciones*/ 
  int lenA = sizeof(articulos)/sizeof(*articulos);
  int lenS = sizeof(sustantivos)/sizeof(*sustantivos);
  int lenV = sizeof(verbos)/sizeof(*verbos);
  int lenP = sizeof(preposiciones)/sizeof(*articulos);

  char oracion[200]; // Char que va a contener la oracion

  // Ciclo para generar las frases
  for (int i = 0; i < 20; ++i)
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
      strcat (oracion,".");

      *oracion = toupper( *oracion ); // Se hace que la primera letra de la oracion sea mayuscula

      puts (oracion); // Se imprime la oracion
    }  

  return 0;
}

