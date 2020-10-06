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
  
  cout << "Digitar 0 para crear 20 frases" << endl;
  cout << "Digitar 1 para crear una breve historia" << endl;
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
      for( int i = 1; i <= 20; i++)
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

  char historia[ 50 ] = "";

  strcat( historia, articulo[ rand() % 4 ] );
  strcat( historia, " " );
  strcat( historia, sustantivo[ rand() % 5 ] );
  strcat( historia, " " );
  strcat( historia, verbo[ rand() % 5 ] );
  strcat( historia, " " );
  strcat( historia, preposicion[ rand() % 5 ] );
  strcat( historia, " " );
  strcat( historia, articulo[ rand() % 4 ] );
  strcat( historia, " " );
  strcat( historia, sustantivo[ rand() % 5 ] );
  strcat( historia, ". " );

  cout << static_cast< char >( toupper( historia[0] ) )
       << &historia[1];

  historia[0] = '\0';
  
}
