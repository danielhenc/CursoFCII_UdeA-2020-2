// Programa para generar enunciados

#include <iostream>
#include <ctime>
#include <cstring> 

using namespace std;

void enunciado( void ); // Prototipo función: parte (a)
void historia( void ); // Prototipo función: parte (b)

int main()
{
  int N; 
  
  srand( time( NULL ) ); 
  
  cout << "Digitar 0 para ver 20 frases aleatorias" << endl;
  cout << "Digitar 1 para ver una breve historia" << endl;
  cin >> N;
  
  if( N == 1 )
    { 
      for ( int j = 1; j < 11; j++ )
	{
	  historia();
	}

      cout << endl;
    }

  else if ( N == 0 )
    {
      for( int i = 0; i <= 20; i++)
	{
	  enunciado(); 
	}
    }
  
  return 0;
  
  cout << endl;
}

void enunciado( void )
{
  // Arreglos de apuntadores a char
  const char *articulo   [] = { "el", "un", "algun", "ningun" };
  const char *sustantivo [] = { "ninio", "senior", "perro", "ciudad", "auto" };
  const char *verbo      [] = { "manejo", "salto", "corrio", "camino", "paso" };
  const char *preposicion[] = { "a", "desde", "encima de", "debajo de", "sobre" };
  char enunciado [ 50 ] = "";

  strcat( enunciado, articulo[ rand() % 4 ] );
  strcat( enunciado, " " );
  strcat( enunciado, sustantivo[ rand() % 5 ] );
  strcat( enunciado, " " );
  strcat( enunciado, verbo[ rand() % 5 ] );
  strcat( enunciado, " " );
  strcat( enunciado, preposicion[ rand() % 5 ] );
  strcat( enunciado, " " );
  strcat( enunciado, articulo[ rand() % 4 ] );
  strcat( enunciado, " " );
  strcat( enunciado, sustantivo[ rand() % 5 ] );
  strcat( enunciado, "." );

  cout << static_cast< char >( toupper( enunciado[0] ) )
       << &enunciado[1] << "\n";

  enunciado[0] = '\0';
  
}

void historia( void )
{
  // Arreglos de apuntadores a char
  const char *articulo   [] = { "el", "un", "algun", "ningun" };
  const char *sustantivo [] = { "ninio", "senior", "perro", "ciudad", "auto" };
  const char *verbo      [] = { "manejo", "salto", "corrio", "camino", "paso" };
  const char *preposicion[] = { "a", "desde", "encima de", "debajo de", "sobre" };

  cout << articulo    [rand() % 4] << " "
       << sustantivo  [rand() % 5] << " "
       << verbo       [rand() % 5] << " "
       << preposicion [rand() % 5] << " "
       << articulo    [rand() % 4] << " "
       << sustantivo  [rand() % 5] << ", ";
}
