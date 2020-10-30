//Librerias
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std; 


//función para la generación aleatoria de núemros
  int randnum (int i){
      int randnum = rand() % i; //Creación de números aleatorios hasta el i
      return randnum;
      }

int main() 
{
    
  srand( time( NULL ) ); //inicializacion de la semilla 
  
  //Ciclo para generar las 20 frases
  for(int i=0; i<20; i++){ 
  
  char sentence[40] = {0}; //Arreglo contenedor de la oración
 
 //Definición del arreglo a punteros para los artículos
  char articulo[4][8] = { " el", " un", " algun", " ningun" };  
  strcat(sentence, *( articulo + randnum (4) )); //Se empieza a añadir la palabra al arreglo que almacena la frase

  char CapitalLetter = sentence[1]; //Toma la primera letra del articulo
  sentence[1] = toupper(CapitalLetter); //Hace mayúscula la primera letra de la oración
  
  
 //Definición del arreglo para los sustantivos
  char sustantivo[5][8] = { " ninio", " senior", " perro", " ciudad", " auto" }; 
  strcat(sentence, *(sustantivo + randnum(5))); //Concatenar con el articulo
  
 //Definición del arreglo para los verbos
 char verbo[5][8] = { " manejo", " salto", " corrio", " camino", " paso" };
 strcat(sentence, *( verbo + randnum(5) ));  //Concatena con articulo y sustantivo

  //Definición del arreglo para las preposiciones
 char preposicion[5][11] = { " a", " desde", " encima de", " debajo de", " sobre" };
 strcat(sentence, *( preposicion + randnum(5) )); //Concatena con articulo sustantivo y verbo
 strcat(sentence, *(articulo + randnum(4)));  //Concatena con articulo sustantivo verbo y preposicion 
 strcat(sentence, *( sustantivo + randnum(5))); //Concatena el sustantivo con articulo sustantivo verbo y preposicion y articulo

 cout << sentence << "." << endl;
}
  return 0; 
}
