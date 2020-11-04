/*
Este programa escribe un pequeno texto a partir de 20 oraciones generadas de forma aleatoria bajo la misma estructura

articulo + sustantivo + verbo + preposicion + articulo + sustantivo

Usando un conjunto de conectores que se elegiran de forma aleatoria para conectar las oraciones. 
*/

#include <iostream>
#include <cstring> 
#include <time.h> 
#include <ctype.h>

using namespace std;

// Calcular numeros aleatorios entre 0 y n
int pos(int n)
{
  return rand() % n;
}

// Generacion de aleatoria una oracion
void gen_sen(char sentence[])
{
  const char *articulo[4] = {"el", "un", "algun", "ningun"};
  const char *sustantivo[5] = {"ninio", "senior", "perro", "ciudad", "auto"};
  const char *verbo[5] = {"manejo", "salto", "corrio", "camino", "paso"};
  const char *preposicion[5] = {"a", "desde", "encima de", "debajo de", "sobre"};  

  int orden[6] = {0, 1, 2, 3, 0, 1};
  
  for(int i=0; i<6; i++){
    
    if(orden[i]==0) strcat(sentence, articulo[pos(4)]);

    if(orden[i]==1) strcat(sentence, sustantivo[pos(5)]);

    if(orden[i]==2) strcat(sentence, verbo[pos(5)]);

    if(orden[i]==3) strcat(sentence, preposicion[pos(5)]);

    if(i<5) strcat(sentence, " ");
    
    if(i==5) strcat(sentence, "\0");
    
  }

}

// Funcion para imprimir las oraciones de forma independiente
void imprimir(char sentence[])
{
  sentence[0] = toupper(sentence[0]);
  
  cout << sentence << '.' << endl;
}

int main()
{
  // Para la generacion de numeros aleatorios
  srand (time(NULL));

  // Arreglo de 20 fila de 80 caracteres
  char sentence[20][80] = {};

  
  // Generan las 20 frases
  for(int i=0; i<20; i++)
    {     
      gen_sen(sentence[i]);      
    }

  // Se crean el arreglo de conectores
  const char *conectores[7] = {"entonces", "luego", "quizas", "antes que", "donde", "aunque", "pero"};

  // Se imprimen las oraciones (en minuscula) y se enumeran

  cout << "FRASES GENERADAS \n" << endl;
  
  for(int i=0; i<20; i++)
    {
      cout << i << ". "<< sentence[i] << endl;
    }
  

  // Se inicializa la variable para el ciclo de generacion del texto
  int i=0;
  // Total de oraciones a usar
  int N = 15;
  // Indice de oraciones que se usaron
  int P[N] = {};

  // Guardar el texto
  char story[1000];

  cout << "\nTEXTO GENERADO \n";

  // Generar un numero para escoger la primera frase
  int p = pos(20);
  
  while(i<N)
    {
      
      // Se anade la primera frase del texto y se inicializa el arreglo de indice de la frases
      if(i==0)
	{
	  sentence[p][0] = toupper(sentence[p][0]);
	  strcat(story, sentence[p]);
	  strcat(story, ", ");
	  strcat(story, conectores[pos(7)]);	  
	  P[i]=p;
	  i++;
	}
      
      // Generacion del texto usando el resto de frases
      else
	{
	  // Contador para saber que frases se han usando ya
	  int s = 0;
	  
	  for(int k=0; k<=i; k++)
	    {
	      if(p==P[k]) // Condicion de que ya se uso la frase
		{
		  s=s+1;
		}
	    }

	  // Para no repetir frases s=0 (Siempre se guarda el indice para saber que frases se usaron)
	  if(s==0) 
	    {
	      
	      if(i==N-1) // Condicion para la ultima frase a usar, esto es el ultimo ciclo
		{
		  strcat(story, " ");
		  strcat(story, sentence[p]);
		  P[i]=p;
		  i++;
		}
	      else // Condicion para el resto de frases
		{
		  strcat(story, " ");
		  strcat(story, sentence[p]);
		  strcat(story, ", ");
		  strcat(story, conectores[pos(7)]);
		  P[i]=p;
		  i++;
		}
	      
	    }
	  // Si s es diferente de cero se sortea de nuevo el p, o la frase a usar.
	  else
	    {
	      p=pos(20);
	    }
	}
    }
      
      cout << story << ".\n" << endl;    
      
  cout << "\nORDEN DE FRASES USADAS\n";
  
  for(int i=0; i<N; i++){cout << P[i] << " ";}

  cout << endl;
  
  return 0; 
}
