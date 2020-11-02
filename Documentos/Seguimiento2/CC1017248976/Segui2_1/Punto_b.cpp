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
  srand( time( NULL ) ); //Se inicializa la semilla 
  char sentence[1000] = {0}; //Arreglo que va a guardar la historia completa

   //Ciclo para generar las 20 frase
  for(int i=0; i<20; i++){
 
  char articulo[4][8] = { " el", " un", " algun", " ningun" };  //Definición del arreglo  para los artículos
  strcat(sentence, *( articulo + randnum (4) )); //Se añade la palabra al arreglo que almacena la historia

  char CapitalLetter = sentence[1]; // primera letra de la historia
  sentence[1] = toupper(CapitalLetter); //Hace mayúscula la primera letra de la oración

  char sustantivo[5][8] = { " ninio", " senior", " perro", " ciudad", " auto" }; //Definición del arreglo para los sustantivos
  strcat(sentence, *(sustantivo + randnum(5))); //Concatenar

 char verbo[5][8] = { " manejo", " salto", " corrio", " camino", " paso" }; //Definición del arreglo para los verbos
 strcat(sentence, *( verbo + randnum(5)  ));  //Concatenar

 char preposicion[5][11] = { " a", " desde", " encima de", " debajo de", " sobre" };  //Definición del arreglo para las preposiciones
 
 strcat(sentence, *( preposicion + randnum(5) )); //Concatenar
 strcat(sentence, *(articulo + randnum(4)));  //Concatenar
 strcat(sentence, *( sustantivo + randnum(5))); //Concatenar

 char signos[4][3] = { ".", ",","",";" };  //Definición del arreglo para agregar signos de puntuacion
 strcat(sentence, *( signos + randnum(4) )); //Se añade puntuacion a la frase


 char conectores[11][18] = { ""," ademas"," incluso",""," tampoco", " aunque tambien"," no solo","", " por el contrario", " sin embargo", " entonces" };  //Definición del arreglo a punteros tipo char para los conectores
 strcat(sentence, *( conectores + randnum(11) )); //Se termina la frase, para ir formando el parrafo


}
  cout << sentence <<" nada tiene que tener sentido para acabar. fin"<< "." << endl;
  cout<< "                                                              "  <<endl;
  cout<<"finalmente, pedimos perdón a cualquier escritor,escritora o inteligencia artificial que vea semejante insulto a la creación literaria"<<endl;
  return 0; 
}
