/*
Este programa construye 20 oraciones con la siguiente construccion

articulo + sustantivo + verbo + preposicion + articulo + sustantivo

donde cada palabra se selecciona aleatoriamente de un arreglo.
*/

#include <iostream>
#include <cstring> 
#include <time.h> 
#include <ctype.h>

using namespace std;

// Generacion de numeros aleatorios
int pos(int n)
{
  return rand() % n;
}

// Generacion de una frase de forma aleatoria
void gen(char sentence[])
{
  // Arreglo de palabras
  const char *articulo[4] = {"el", "un", "algun", "ningun"};
  const char *sustantivo[5] = {"ninio", "senior", "perro", "ciudad", "auto"};
  const char *verbo[5] = {"manejo", "salto", "corrio", "camino", "paso"};
  const char *preposicion[5] = {"a", "desde", "encima de", "debajo de", "sobre"};  

  // Arreglo para construir la frase
  int orden[6] = {0, 1, 2, 3, 0, 1};

  // Se asocian 0-articulo, 1-sustantivo, 2-verbo, 3-preposiciones
  for(int i=0; i<=6; i++){

    // Se unen las palabras y espacios al arreglo final    
    if(orden[i]==0) strcat(sentence, articulo[pos(4)]); 

    if(orden[i]==1) strcat(sentence, sustantivo[pos(5)]);

    if(orden[i]==2) strcat(sentence, verbo[pos(5)]);

    if(orden[i]==3) strcat(sentence, preposicion[pos(5)]);

    if(i<5) strcat(sentence, " "); 
    //Se termina la oracion
    if(i==5) strcat(sentence, "\0");
    
  }

}

// Funcion para imprimir la oracion
void imprimir(char sentence[])
{
  sentence[0] = toupper(sentence[0]); // Mayuscula inicial en la oracion
  
  cout << sentence << '.' << endl;
}

int main()
{
  // Para iniciar los numeros aleatorios
  srand (time(NULL));

  // Ciclo para imprimir las 20 oraciones
  for(int i=0; i<20; i++)
    {
      char sentence[80] = {}; // Arreglo donde se guarda la oracion

      gen(sentence); // Se genera la oracion
  
      cout << i+1 << ". "; // Se enumera la oracion

      imprimir(sentence); // Se imprime la oracion correspondiente
    }
  
 return 0; 
}
