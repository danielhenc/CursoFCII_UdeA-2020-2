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

  const char *sustantivo[11] = {
    "ninio",
    "senior",
    "perro",
    "ciudad",
    "auto",
    "caperucita roja",
    "blancanieves",
    "bosque",
    "cazador",
    "lobo",
    "enano"
  };

  const char *verbo[7] = {
    "manejo",
    "salto",
    "corrio",
    "camino",
    "paso",
    "devoro",
    "saludo"
  };

  const char *preposicion[5] = {
    "a",
    "desde",
    "encima de",
    "debajo de",
    "sobre"
  };

  const char *conector[7] = {
    "pero",
    "sin embargo",
    "luego",
    "entonces",
    "aun asi",
    "despues",
    "por otro lado"
  };

  srand(time(NULL));
  
  cout << "Una breve historia aleatoria de amor (o no): " << endl << endl;

  cout << "Una vez ";

  for (int i = 0; i < N; i++) {
    //indice aleatorio para el primer articulo
    int a_i = rand() % 4;
    //indice aleatorio para el primer sustantivo
    int s_i = rand() % 11;
    //indice aleatorio para el verbo
    int v_i = rand() % 7;
    //indice aleatorio para la preposicion
    int p_i = rand() % 5;
    //indice aleatorio para el segundo articulo
    int a_j = rand() % 4;
    //indice aleatorio para el segundo sustantivo
    int s_j = rand() % 11;

    //cadena donde se forma la oracion
    //la longitud es 46, ya que es la maxima longitud posible cuando se combinan todas las palabras de mayor longitud (incluyendo espacios y puntos)    
    char oracion[60] = "";

    //se concatenan en el orden: articulo sustantivo verbo preposicion articulo sustantivo.
    strcat(strcat(oracion, articulo[a_i]), " ");
    strcat(strcat(oracion, sustantivo[s_i]), " ");
    strcat(strcat(oracion, verbo[v_i]), " ");
    strcat(strcat(oracion, preposicion[p_i]), " ");
    strcat(strcat(oracion, articulo[a_j]), " ");
    strcat(oracion, sustantivo[s_j]);
    
    //concatenamos el conector, solo la ultima oracion no requiere conector, por eso i<N-1
    if (i < N - 1) {
      //indice aleatorio para el conector
      int c_i = rand() % 7;
      //usamos un formato de comas para el conector
      strcat(oracion, ", ");
      strcat(oracion, conector[c_i]);
      strcat(oracion, ", ");
    }

    cout << oracion;
  }
  cout << " y todos vivieron felices para siempre.";
  return 0;
}
