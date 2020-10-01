#include <stdlib.h> //Aquí se encuentran las funciones srand() y rand()
#include <time.h>
#include <iostream>
#include <iomanip>
#include "Dado.h"

using namespace std;

void haGanado(); //Imprime un mensaje diciendo al jugador que ha ganado
void haPerdido(); //Imprime un mensaje diciendo al jugador que ha perdido
void craps(); //Imprime un mensaje diciendo al jugador que ha perdodo por craps
bool deseaSeguirJugando(); //Pregunta al jugador si quiere seguir jugando y
                           //devulve true si sí y false si no.

int main()
{
  srand(time(NULL));

  while ( true )
    {
      cout
	<< '\n'
	<< "         *******************************\n"
	<< "         ***** ¡COMIENZA EL JUEGO! *****\n"
	<< "         *******************************\n"
	<< "\n\n"
	<< "Usted tiene dos dados, los cuales va a lanzar a continuación.\n"
	<< "Si en el primer lanzamiento sus dados suman 7 u 11, usted gana,\n"
	<< "pero si usted obtiene como suma 2, 3 o 12, entonces usted pierde.\n"
	<< "Perder en el primer lanzamiento se conoce como Craps.\n\n"
	<< "Antes de empezar. ¿Quiere que se muestren los dados graficamente? "
	<< " [s/n] ";
      bool mostrar;
      char answer;
      cin >> answer;
      if (answer == 's' or answer == 'S')
	mostrar = true;
      else if (answer == 'n' or answer == 'N')
	mostrar = false;
      else
	mostrar = true;

      //Se instancian dos objetos de la clase Dado
      Dado dado1("Dado 1");
      Dado dado2("Dado 2");
      
      dado1.lanzarDado(mostrar);
      dado2.lanzarDado(mostrar);

      int r1 = dado1.obtenerUltimoResultado();
      int r2 = dado2.obtenerUltimoResultado();
      int suma = r1 + r2;

      cout << "\nLa suma de los resultados es: " << suma << "\n" << endl;

      if ( suma == 7 or suma == 11 )
	{
	  haGanado();
	  if ( deseaSeguirJugando() )
	    continue;
	  else
	    break;
	}
      else if ( suma == 2 or suma == 3 or suma == 12 )
	{
	  craps();
	  if ( deseaSeguirJugando() )
	    continue;
	  else
	    break;
	}
      else//Segunda etapa del juego
	{
	  int punto = suma;
      
	  cout
	    << "               ¡SEGUNDA ETAPA!\n\n"
	    << "Aún sigue en juego. Su punto es " << punto << ".\n"
	    << "Para ganar debe volver a lanzar los dados hasta que obtenga\n"
	    << "nuevamente el valor de su punto. Pero si antes saca un 7\n"
	    << "usted pierde.\n"
	    << endl;

	  int ronda = 2;
	  
	  do
	    {
	      cout << "\n    Ronda " << ronda << "\n" << endl;
	  
	      dado1.lanzarDado(mostrar);
	      dado2.lanzarDado(mostrar);

	      r1 = dado1.obtenerUltimoResultado();
	      r2 = dado2.obtenerUltimoResultado();
	      suma = r1 + r2;

	      cout << "\nResultado: " << suma << ".";
	      if ( suma != 7 and suma != punto )
		cout << " Sigue en juego.\n" << endl;
	      else
		cout << '\n' << endl;
	  
	      ronda++;
	    }
	  while ( suma != 7 and suma != punto );
      
	  if ( suma == 7 )
	    {
	      haPerdido();
	      if ( deseaSeguirJugando() )
		continue;
	      else
		break;
	    }
	  else
	    {
	      haGanado();
	      if ( deseaSeguirJugando() )
		continue;
	      else
		break;
	    }
	}
    }
  return 0;
}

/////////////////////////////////
// Implementación de funciones //
/////////////////////////////////

void haGanado()
{
  cout << '\n';
  cout << "*********************" << endl;
  cout << "**** ¡HA GANADO! ****" << endl;
  cout << "*********************" << endl;
  cout << '\n';
}

void haPerdido()
{
  cout << "\nHa perdido :(\n" << endl;
}

void craps()
{
  cout << "\n¡CRAPS! Ha perdido :(\n" << endl;
}

bool deseaSeguirJugando()
{
  cout << "\n¿Desea volver a jugar? [S/N] ";
  char answer;
  while ( true )
    {
      cin >> answer;
      if ( answer != 's' and answer != 'S' and answer != 'n' and answer != 'N' )
	cout << "\nDebe ingresar S o N (también puede ser en minúscula) ";
      else
	break;
    }
  
  if ( answer == 'n' or answer == 'N' )
    {
      cout << "\nEstá bien, hasta luego :D.\n" << endl;
      return false;
    }
  else if ( answer == 's' or answer == 'S' )
    return true;
}
