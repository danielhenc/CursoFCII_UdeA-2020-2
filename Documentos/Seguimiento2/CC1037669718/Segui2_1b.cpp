#include<iostream>
#include<random>
#include<ctime>
#include<cstring>

using namespace std;

int main(){

  int N = 1500; // número máximo de caracteres en el texto
  int n = 4; // número de enunciados
  int rindex[6]; // indices aleatorios

  char texto[N]="";
  const char *articulo[3] = {"el" , "un", "algun"};
  const char *sustantivo[6] = {"Brayan", "profesor", "coronavirus" , "perro" , "techo" , "carro"};
  const char *verbo[8] = {"se encontro", "golpeo", "manejo" , "salto" , "corrio" , "camino" , "atraco", "cayo"};
  const char *preposicion[6] = {"a" , "desde" , "encima de" , "debajo de" , "sobre", "hacia"};
  const char *conexion[5] = {"luego", "entonces", "hasta que", "y", "por lo que"};

  srand(time(NULL));

  for(int i = 0 ; i < n ; i++){

    // generamos los indices aleatorios
    rindex[0] = rand()%3; rindex[1] = rand()%6; rindex[2] = rand()%8;
    rindex[3] = rand()%6; rindex[4] = rand()%3; rindex[5] = rand()%6;
    rindex[6] = rand()%5;
    
    // añadimos la primera palabra
    if( i == 0 ){
      texto[0] = toupper( articulo[ rindex[0] ][0] );
      
      for(int j = 1 ; j < sizeof(articulo[ rindex[0] ])/sizeof(char) ; j++ ){
	texto[j] = articulo[ rindex[0] ][j];} 
      
    }else{strcat(texto, articulo[ rindex[0] ]);}

    // concatenamos el resto de palabras
    
    strcat(texto, " ");
    strcat(texto , sustantivo[ rindex[1] ]); strcat(texto, " ");
    strcat(texto , verbo[ rindex[2] ]); strcat(texto, " ");
    strcat(texto , preposicion[ rindex[3] ]); strcat(texto, " ");
    strcat(texto , articulo[ rindex[4] ]); strcat(texto, " ");
    strcat(texto , sustantivo[ rindex[5] ]); 
    if( i < n-1 ){
      strcat(texto , ", ");
      strcat(texto , conexion[ rindex[6] ] ); strcat(texto , " ");
    }

  }

  strcat(texto , ".\n");
  // imprimimos el texto
  cout << texto;
  
  return 0;
}
