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
  const char *sustantivo[6] = {"joven", "anciano", "perro", "apartamento", "COVID","cuarentena"};
  const char *verbo[6] = {"manejo","fue",  "contagio", "hopitalizo", "enfermo", "encerro"}; 
  const char *preposicion[5] = {"a", "desde", "durante", "desde", "tras"};
  
  int pos_ar1; 
  bool dat;
  char parrafo[1000]="";
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
      strcat(frase,sustantivo[random_pos(6)]);
      strcat(frase," ");
      strcat(frase,verbo[random_pos(6)]);
      strcat(frase," ");
      strcat(frase,preposicion[random_pos(5)]);
      strcat(frase," ");
      strcat(frase,articulo[random_pos(4)]);
      strcat(frase," ");
      strcat(frase,sustantivo[random_pos(5)]);
      strcat(frase,". ");
  
      strcat( parrafo,frase );
      
      //cout << parrafo <<endl;
    }
  cout << parrafo << endl;
  return 0;
 
}

//funcion que crea números random segun la longitud del array 
int random_pos(int n)
{
  int pos = rand()%n;
  return pos;
}
