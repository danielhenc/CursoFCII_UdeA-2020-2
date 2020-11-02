#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  char *articulo[ 4 ] ={"el ", "un ", "algun ", "ningun "};
  char *sustantivo[ 5 ] ={"ninio ", "senior ", "perro ", "ciudad ", "auto "};
  char *verbo[ 5 ] ={"manejo ", "salto ", "corrio ", "camino " , "paso "};
  char *preposicion[ 5 ] ={"a ", "desde ", "encima de ", "debajo de " , "sobre "};
  char *conectores[ 6 ] ={"entonces ", "luego ", "despues ", "aunque " , "pero ", "mientras que "};
  char *coma[1]={","};

  srand( time( 0 ) );

  char oracion[2000]={0};

  for (int i=1;i<=20;i++)
  {
    int n1,n2,n3,n4,n5,n6,n7;
    n1 = rand() % 4;
    strcat(oracion, *(articulo+n1));
    n2 = rand() % 5;
    strcat(oracion, *(sustantivo+n2));
    n3 = rand() % 5;
    strcat(oracion, *(verbo+n3));
    n4 = rand() % 5;
    strcat(oracion, *(preposicion+n4));
    n5 = rand() % 5;
    strcat(oracion, *(articulo+n5));
    n6 = rand() % 5;
    strcat(oracion, *(sustantivo+n6));
    n7 = rand() % 6;
    strcat(oracion, *coma);
    strcat(oracion, *(conectores+n7));
    strcat(oracion, *coma);
  }

  int n1,n2,n3,n4,n5,n6,n7;
  n1 = rand() % 4;
  strcat(oracion, *(articulo+n1));
  n2 = rand() % 5;
  strcat(oracion, *(sustantivo+n2));
  n3 = rand() % 5;
  strcat(oracion, *(verbo+n3));
  n4 = rand() % 5;
  strcat(oracion, *(preposicion+n4));
  n5 = rand() % 5;
  strcat(oracion, *(articulo+n5));
  n6 = rand() % 5;
  strcat(oracion, *(sustantivo+n6));
  n7 = rand() % 6;

  *oracion = toupper( *oracion );
  cout<<oracion<<"."<<endl;

  return 0;

}
