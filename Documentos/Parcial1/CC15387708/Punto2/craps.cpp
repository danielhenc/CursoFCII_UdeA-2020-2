// Aplicación para jugar a "craps"

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <unistd.h>

using namespace std;

void iniciar();
int lanzamiento();

int main()
{
  int inicio;

  do
    {
      cout << "\n------------------------------------------------" << endl
	   << "\nPrueba tu suerte en el juego Craps!" << endl
	   << "Al lanzar 7 ó 11, GANAS; y con 2, 3 ó 12, PIERDES." << endl
	   << "\nPor favor pulsa una de las siguientes opciones:" << endl
	   << "1 -> para iniciar o continuar el juego" << endl
	   << "2 -> para salir del juego" << endl;
      usleep(2000000);

      cin >> inicio;

      if ( inicio == 1 )
	iniciar();
    }

  while ( inicio != 2 );

  return 0;
	
}

void iniciar()
{
  int resultado;
  int punto;

  srand(time(NULL));
  resultado = lanzamiento();

  switch( resultado )
    {
    case 7:
    case 11:
      cout << "\nGANASTE en el primer lanzamiento. Genial!" << endl;
      break;
    case 2:
    case 3:
    case 12:
      cout << "\nFallaste! Este primer intento se PERDIÓ." << endl;
      break;
    default:
      break;
    }

  if ( resultado == 4 || resultado == 5 || resultado == 6
	      || resultado == 8 || resultado == 9 || resultado == 10 )
    {
      punto = resultado;
      cout << "\nEl juego continúa y ahora las condiciones son:" << endl;
      cout << "-> Lanzar otra vez un " << punto << " para GANAR!" << endl;
      cout << "-> Si te sale un 7 la CASA gana. Buena suerte!" << endl;
      cout << "\nPor favor lanza de nuevo pulsando la tecla ENTER\n";
      cin.ignore();
      cin.get();
      
      resultado = lanzamiento();
      
      while ( resultado != punto and resultado !=  7 )
    	{
	  resultado = lanzamiento();	        
        }
        
      if ( resultado == punto )
        {
	  cout << "\nMuy bien. GANASTE!" << endl;
	  usleep(1000000);
        }

      else if ( resultado == 7 )
        {
	  cout << "\nLo siento! PERDISTE tu oportunidad." << endl;
	  usleep(1000000);
        }
      
    } 
}

int lanzamiento()
{
   // Lanzamiento aleatorio de dos dados
   int c1 = 1 + rand() % 6;
   int c2 = 1 + rand() % 6;
   int suma = c1 + c2;
   
   // Imprime el resultado de las caras c1, c2 y su suma
   usleep(1000000);
   cout << "\nEl lanzamiento es: " << suma << endl;
        
   return suma;
}
