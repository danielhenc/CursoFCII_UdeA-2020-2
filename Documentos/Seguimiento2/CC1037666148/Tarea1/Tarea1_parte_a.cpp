#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_pos(int); 

int main()
{
  srand(time(NULL));

  //Se definen arreglos multidimensionales de caracteres
  const char *articulo[4] = {"el", "un", "algun", "ningun"};
  const char *sustantivo[5] = {"ninio", "senior", "perro", "ciudad", "auto"};
  const char *verbo[5] = {"manejo", "salto", "corrio", "camino", "paso"};
  const char *preposicion[5] = {"a", "desde", "encima de", "debajo de", "sobre"};
  
  int pos_ar1; 
  bool dat;
  for (int j; j<20; j++)
    {
      char frase[100]="";
      pos_ar1 = random_pos(4);
 
      frase[0] = toupper(articulo[pos_ar1][0]); //Agrega mayusculas al inicio de la frase
      dat = true;
      int i = 1;
      //Permite agregar el primer articulo de la frase
      while (dat)
	{
	  frase[i]=articulo[pos_ar1][i];
	  if ((articulo[pos_ar1][i]==0)==1)
	    {
	      dat = false;
	      break;
	    }
	  i++;
	}
      //Se llena la frase
      strcat(frase," ");
      strcat(frase,sustantivo[random_pos(5)]);
      strcat(frase," ");
      strcat(frase,verbo[random_pos(5)]);
      strcat(frase," ");
      strcat(frase,preposicion[random_pos(5)]);
      strcat(frase," ");
      strcat(frase,articulo[random_pos(4)]);
      strcat(frase," ");
      strcat(frase,sustantivo[random_pos(5)]);
      strcat(frase,".");
  
      cout<< frase << endl;
    }
 
 
  return 0;
 
}

//funcion que crea números random segun la longitud del array 
int random_pos(int n)
{
  int pos = rand()%n;
  return pos;
}
