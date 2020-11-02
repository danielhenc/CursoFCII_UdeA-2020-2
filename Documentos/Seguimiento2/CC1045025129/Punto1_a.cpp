//Librerías a utilizar
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std; 


int main() 
{
  srand( time( NULL ) ); //Se inicializa la semilla del generador aleatorio
  for(int i=0; i<20; i++){ //Ciclo para generar las 20 frases

    //Números aleatorios para poder tomar al azar las palabras  
  int num_art = rand() % 4;
  int num_sus = rand() % 5;
  int num_ver = rand() % 5;
  int num_pre = rand() % 5;
  int num_art2 = rand() % 4;
  int num_sus2 = rand() % 5;

  char part1[200] = {0}; //Arreglo que va a guardar la oraciòn completa
 
  char articulo[4][8] = { "el ", "un ", "algun ", "ningun " };  //Definición del arreglo a punteros tipo char para los artículos
  strcat(part1, *( articulo + num_art )); //Se empieza a añadir la palabra al arreglo que almacena la frase

  char M = part1[0]; //Toma la primera letra de la oraciòn
  part1[0] = toupper(M); //Hace mayúscula la primera letra de la oración

  char sustantivo[5][8] = { "ninio ", "senior ", "perro ", "ciudad ", "auto " }; //Definición del arreglo a punteros tipo char para los sustantivos
  strcat(part1, *(sustantivo + num_sus)); //Concatenar

 char verbo[5][8] = { "manejo ", "salto ", "corrio ", "camino ", "paso " }; //Definición del arreglo a punteros tipo char para los verbos
 strcat(part1, *( verbo + num_ver ));  //Concatenar

 char preposicion[5][11] = { "a ", "desde ", "encima de ", "debajo de ", "sobre " };  //Definición del arreglo a punteros tipo char para las preposiciones
 strcat(part1, *( preposicion + num_pre )); //Concatenar

 strcat(part1, *(articulo + num_art2));  //Concatenar de nuevo con un articulo

 strcat(part1, *( sustantivo + num_sus2 )); //Concatenar con la ultima palabra


  
 cout << part1 << "." << endl;
}
  return 0; 
}


