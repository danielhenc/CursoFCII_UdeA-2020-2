#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  //char articulo;
  char *articulo[ 4 ] ={"el ", "un ", "algun ", "ningun "};
  char *sustantivo[ 5 ] ={"ninio ", "senior ", "perro ", "ciudad ", "auto "};
  char *verbo[ 5 ] ={"manejo ", "salto ", "corrio ", "camino " , "paso "};
  char *preposicion[ 5 ] ={"a ", "desde ", "encima de ", "debajo de " , "sobre "};

  srand( time( 0 ) );

  for (int i=1;i<=20;i++)
  {
    char oracion[200]={0};

    int n1,n2,n3,n4,n5,n6;
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

    *oracion = toupper( *oracion );
    cout<<oracion<<"."<<endl;

  }

  return 0;

}
