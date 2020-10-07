#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // Importar <windows.h> en Windows

using namespace std;

int estado; // Variable global para saber si el jugador gano o perdio

void craps();

int main()
{
  int juego = 1;
  cout << "\nEsto es CRAPS! El saldo inicial es de 1 millon de pesos. Quiere jugar? (si = 1, no = 0): ";
  cin >> juego;
  
  float SaldoenBanco = 1000000;
  float apuesta;
  int mensaje;

  while (juego == 1) // Mientras el jugador quiere jugar
    {
      cout << fixed << setprecision(0) << "\nIngrese una apuesta: ";
      cin >> apuesta;
      
      while (apuesta > SaldoenBanco or apuesta <= 0) // Ciclo para que el jugador ingrese una apuesta valida
	{
	  cout << "\nApuesta invalida. Recuerde que su saldo es " << SaldoenBanco << " pesos" << endl;
	  cout << "\nIngrese una cantidad entre 0 y su saldo: ";
	  cin >> apuesta;
	}

      cin.ignore();
      cout << "\nPerfecto!";
      
      craps(); // Se ejecuta un juego entero de craps

      if (estado == 1) // Verifica si el jugador gano
	{
	  SaldoenBanco += apuesta; // Suma la apuesta ganada al saldo
	  usleep(500000);
	  cout << "\nSu nuevo saldo es de " << SaldoenBanco << " pesos" << endl;

	  if (SaldoenBanco > 1000000) // Para imprimir unos mensajes charla
	    {
	      usleep(500000);
	      mensaje = 1 + rand()%2;

	      // Mensajes aleatorios
	      switch(mensaje)
		{
		case 1:
		  cout << "\nCon esa suerte nos va a quebrar!" << endl;
		  break;
		case 2:
		  cout << "\nDejenos ganarle una!" << endl;
		  break;
		default:
		  break;
		}
	    }

	  else // Otro mensaje charla
	    {
	      usleep(500000);
	      cout << "\nYa esta remontando. Unas tiradas mas y se va victorioso." << endl;
	    }

	}

      else // Verifica si el jugador perdio
	{
	  SaldoenBanco -= apuesta; // Resta la apuesta perdida
	  usleep(500000);
	  cout << "\nSu actual saldo es de " << SaldoenBanco << " pesos" << endl;
	  
	  if (SaldoenBanco == 0) // Cuando no queda mas saldo
	    {
	      usleep(500000);
	      cout << "Lo siento, se quedo sin fondos!" << endl;
	      break;
	    }

	  else if (SaldoenBanco >= 1000000) // Mensaje charla
	    {
	      usleep(500000);
	      cout << "\nTodavia le queda mucha plata hermano, relajese y siga!" << endl;
	    }

	  else if (0 < SaldoenBanco < 1000000) // Un mensaje charla mas
	    {
	      usleep(500000);
	      mensaje = 1 + rand()%2;

	      // Mensajes aleatorios
	      switch(mensaje)
		{
		case 1:
		  cout << "\nEn serio esta considerando irse perdiendo?? ARRIESGUESE!" << endl;
		  break;
		case 2:
		  cout << "\nNo pierda mas tiempo y dinero, deje asi!" << endl;
		  break;
		default:
		  cout << "\nDeje asi!" << endl;
		  break;
		}
	    }
	}

      cout << "Quiere seguir apostando? (si = 1, no = 0): ";
      cin >> juego;	
    }
  
  if (juego != 1) // En caso de que el jugador no quiera jugar mas
    {
      cout << "\nComo quiera!" << endl;
    }
  
  return 0;
}

// Funcion para ejecutar un juego de Craps
// Los comentarios de su contenido estan en el anterior script
void craps()
{  
  srand(time(NULL));

  cout << "\nTire los dados pulsando ENTER" << endl;
  cin.ignore();
      
  int dado1 = 1 + rand()%6;
  int dado2 = 1 + rand()%6;
  int sumadados = dado1 + dado2;
  
  cout << "Ha obtenido: " << endl;
  usleep(1000000);
      
  if (sumadados == 7 or sumadados == 11)
    {
      cout << sumadados << endl;
      usleep(500000);
      cout << "\nQue suerte, HA GANADO DE UN TIRO!" << endl;
      estado = 1;
    }

  else if (sumadados == 2 or sumadados == 12)
    {
      cout << sumadados << endl;
      usleep(500000);
      cout << "\nCRAPS! Perdio de primerazo, pero no volvera a ocurrir" << endl;
      estado = 0;
    }

  else if (4 <= sumadados <= 6 or 8 <= sumadados <= 10)
    {
      cout << sumadados << endl;
      usleep(500000);
	  
      int punto = sumadados;
      cout << "\nSu Punto es " << punto << endl;
      cout << "Gana cuando saque de nuevo " << punto << endl;
      cout << "Pierde si saca 7" << endl;
      cout << "Vuelva a tirar con ENTER";
      cin.ignore();

      dado1 = 1 + rand()%6;
      dado2 = 1 + rand()%6;
      sumadados = dado1 + dado2;
      
      cout << "\nHa sacado: " << endl;
      usleep(1000000);
      cout << sumadados << endl;

      while (sumadados != 7 and sumadados != punto)
	{
	  usleep(500000);
	  cout << "\nEse no es su Punto, vuelva a lanzar con ENTER";
	  cin.ignore();
	  
	  dado1 = 1 + rand()%6;
	  dado2 = 1 + rand()%6;
	  sumadados = dado1 + dado2;

	  cout << "\nHa tirado: " << endl;
	  usleep(1000000);
	  cout << sumadados << endl;
	}

      if (sumadados == 7)
	{
	  usleep(500000);
	  cout << "\nPerdio, LA CASA SIEMPRE GANA!" << endl;
	  estado = 0;
	}

      else if (sumadados == punto)
	{
	  usleep(500000);
	  cout << "\nHA GANADO!" << endl;
	  estado = 1;
	}
    }
}
