#include <stdlib.h> //Aquí se encuentran las funciones srand() y rand()
#include <time.h>
#include <iostream>
#include <iomanip>
#include "Dado.h"

using namespace std;

/////////////////////////////
// Prototipos de funciones //
/////////////////////////////

bool JugarCraps(int&, int&);
//Despliega el juego craps. Si el jugador quiere terminar el juego, esta función
//retorna false, y retorna true si el jugador desea seguir jugando.

void haGanado(int&, int&);
//Imprime un mensaje diciendo al jugador que ha ganado y modifica el saldo en
//banco y apuesta.

void haPerdido(int&, int&);
//Imprime un mensaje diciendo al jugador que ha perdido y modifica el saldo en
//banco y apuesta.

void craps(int&, int&);
//Imprime un mensaje diciendo al jugador que ha perdodo por craps y modifica el
//saldo en banco y apuesta.

bool deseaSeguirJugando();
//Pregunta al jugador si quiere seguir jugando; devuelve true si sí y false si no

//////////////////
// Función main //
//////////////////

int main()
{
  srand(time(NULL));
  int SaldoenBanco = 1000000;
  int apuesta;
  bool seguir = true;
  while (seguir)
    {
      cout << "\nSu saldo en banco es: $" << SaldoenBanco << endl;
      cout << "Haga una apuesta menor o igual a $" << SaldoenBanco << endl;
      cout << "¿Cuál es su apuesta? $";
      cin >> apuesta;
      while (apuesta > SaldoenBanco or apuesta < 0)
	{
	  cout << "Recuerde que el valor de su apuesta debe ser menor o igual a "
	       << "su saldo en banco y mayor o igual a $1." << endl;
	  cout << "¿Cuál es su apuesta? $";
	  cin >> apuesta;
	}
      seguir = JugarCraps(SaldoenBanco, apuesta);
      cout << "Su saldo en banco ahora es: $" << SaldoenBanco << '\n' << endl;
      if (SaldoenBanco == 0)
	{
	  cout
	    << "Lo siento ¡se quedó sin fondos! No puede seguir juagando"
	    << endl;
	  break;
	}
      else if (SaldoenBanco > 0 and SaldoenBanco < 500000)
	cout << "Usted se está quebrando ¿no le parece?" << endl;
      else if (SaldoenBanco >= 500000 and SaldoenBanco < 1000000)
	cout << "Hágale, no pasa nada ¡arriésguese!" << endl;
      else if (SaldoenBanco > 1000000)
	{
	  cout << "La sacaste del estadio. Ahora es tiempo de cambiar sus fichas"
	       << " por plata" << endl;
	}
    }
}

/////////////////////////////////
// Implementación de funciones //
/////////////////////////////////

bool JugarCraps(int& aSaldoenBanco, int& aApuesta)
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
      
  char answer;
  cin >> answer;
  cout << "\n\n    Ronda 1\n" << endl;
  bool mostrar;
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

  if (suma == 7 or suma == 11)
    {
      haGanado(aSaldoenBanco, aApuesta);
      return deseaSeguirJugando();
    }
  else if (suma == 2 or suma == 3 or suma == 12)
    {
      craps(aSaldoenBanco, aApuesta);
      return deseaSeguirJugando();
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

	  cout << "\nResultado: " << suma << ". ";
	  cout << "Su punto es " << punto << ". ";
	  if ( suma != 7 and suma != punto )
	    cout << " Sigue en juego.\n" << endl;
	  else
	    cout << '\n' << endl;
	  
	  ronda++;
	}
      while ( suma != 7 and suma != punto );
      
      if (suma == 7)
	{
	  haPerdido(aSaldoenBanco, aApuesta);
	  return deseaSeguirJugando();
	}
      else
	{
	  haGanado(aSaldoenBanco, aApuesta);
	  return deseaSeguirJugando();
	}
    }
}

void haGanado(int& aSaldoenBanco, int& aApuesta)
{
  aSaldoenBanco += aApuesta;
  cout << '\n';
  cout << "*********************" << endl;
  cout << "**** ¡HA GANADO! ****" << endl;
  cout << "*********************" << endl;
  cout << '\n';
}

void haPerdido(int& aSaldoenBanco, int& aApuesta)
{
  aSaldoenBanco -= aApuesta;
  cout << "\nHa perdido :(\n" << endl;
}

void craps(int& aSaldoenBanco, int& aApuesta)
{
  aSaldoenBanco -= aApuesta;
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
