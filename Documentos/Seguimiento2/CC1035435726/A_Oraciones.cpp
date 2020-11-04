#include <iostream>

#include <cstring>

#include <stdlib.h>

#include <time.h>

using namespace std;

int main() {

//numero de oraciones
  const int N = 20;
  
  //declaracion de arreglos de apuntadores a char
  //se declaran constantes porque no requieren modificarse
  
  const char *articulo[4] = {
    "el",
    "un",
    "algun",
    "ningun"
  };
  
  const char *sustantivo[5] = {
    "ninio",
    "senior",
    "perro",
    "ciudad",
    "auto"
  };
  
  const char *verbo[5] = {
    "manejo",
    "salto",
    "corrio",
    "camino",
    "paso"
  };
  
  const char *preposicion[5] = {
    "a",
    "desde",
    "encima de",
    "debajo de",
    "sobre"
  };

  srand(time(NULL));
  cout << N << " oraciones aleatorias:" << endl << endl;

  for (int i = 0; i < N; i++) {
    //indice aleatorio para el primer articulo
    int a_i = rand() % 4;
    //indice aleatorio para el primer sustantivo
    int s_i = rand() % 5;
    //indice aleatorio para el verbo
    int v_i = rand() % 5;
    //indice aleatorio para la preposicion
    int p_i = rand() % 5;
    //indice aleatorio para el segundo articulo
    int a_j = rand() % 4;
    //indice aleatorio para el segundo sustantivo
    int s_j = rand() % 5;
    
    //cadena donde se forma la oracion
    //la longitud es 46, ya que es la maxima longitud posible cuando se combinan todas las palabras de mayor longitud (incluyendo espacios y puntos)    
    char oracion[46]="";
    
    //se concatenan en el orden: articulo sustantivo verbo preposicion articulo sustantivo.
    strcat(strcat(oracion, articulo[a_i]), " ");
    strcat(strcat(oracion, sustantivo[s_i]), " ");
    strcat(strcat(oracion, verbo[v_i]), " "); 
    strcat(strcat(oracion, preposicion[p_i]), " ");
    strcat(strcat(oracion, articulo[a_j]), " ");
    strcat(strcat(oracion, sustantivo[s_j]), ".");
    
    //el primer caracter es mayuscula.
    oracion[0] = toupper(oracion[0]);
    cout << i+1 << ". " << oracion << endl;
    
  }
  return 0;
  
}
