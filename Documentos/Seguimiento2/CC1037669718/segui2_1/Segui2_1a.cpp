#include<iostream>
#include<random>
#include<ctime>
#include<cstring>

using namespace std;

int main(){

  int N = 100; // número máximo de caracteres en un enunciado
  int n = 20; // número de enunciados
  int rindex[6];

  char enunciado[N]="";
  const char *articulo[4] = {"el" , "un" , "algun" , "ningun"};
  const char *sustantivo[5] = {"ninio" , "senior" , "perro" , "ciudad" , "auto"};
  const char *verbo[5] = {"manejo" , "salto" , "corrio" , "camino" , "paso"};
  const char *preposicion[5] = {"a" , "desde" , "encima de" , "debajo de" , "sobre"};

  srand(time(NULL));

  for(int i = 0 ; i < n ; i++){

    // generamos los indices aleatorios
    rindex[0] = rand()%4; rindex[1] = rand()%5; rindex[2] = rand()%5;
    rindex[3] = rand()%5; rindex[4] = rand()%4; rindex[5] = rand()%5;
    
    // añadimos la primera letra en mayuscula
    enunciado[0] = toupper( articulo[ rindex[0] ][0] );

    // terminamos de concatenar el resto de la primera palabra
    for(int j = 1 ; j < sizeof(articulo[ rindex[0] ])/sizeof(char) ; j++ ){
      enunciado[j] = articulo[rindex[0]][j];} 
    strcat(enunciado, " ");
    
  // concatenamos el resto de palabras
    strcat(enunciado, sustantivo[rindex[1]]); strcat(enunciado, " ");
    strcat(enunciado, verbo[rindex[2]]); strcat(enunciado, " ");
    strcat(enunciado, preposicion[rindex[3]]); strcat(enunciado, " ");
    strcat(enunciado, articulo[rindex[4]]); strcat(enunciado, " ");
    strcat(enunciado, sustantivo[rindex[5]]);
    strcat(enunciado, ".\n");
    
    // imprimimos el enunciado
    cout << enunciado;
    
    // vaceamos la variable enunciado
    enunciado[0] = '\0';
  }
  return 0;
}
