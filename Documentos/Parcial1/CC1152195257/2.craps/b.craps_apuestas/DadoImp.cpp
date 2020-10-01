#include "Dado.h"
#include <stdlib.h>
#include <iostream>

using namespace std;



Dado::Dado(string aNombre)
{
  nombreDado = aNombre;
  lados = 6;
  tiradas = 0;
}



void Dado::lanzarDado(bool mostrar)
{
  tiradas++;
  cout << "\nPara lanzar el " << nombreDado << " presione l y luego Enter: ";
  char answer;
  do
    {
      cin >> answer;
      if (answer != 'l' and answer != 'L')
	cout << "Debe ingresar l o L. ";
    }
  while (answer != 'l' and answer != 'L');
  ultimoResultado = 1 + rand()%(lados);
  if (mostrar)
    mostrarDado(ultimoResultado);
  cout << "\nSale " << ultimoResultado << " en el " << nombreDado << endl;
}



int Dado::obtenerUltimoResultado()
{
  if (tiradas == 0)
    return 0;
  else
    return ultimoResultado;
}



void Dado::mostrarDado(int aUltimoResultado)
{
  switch (aUltimoResultado)
    {
    case 1:
      cout << "  __________\n"
	   << " /         /|\n"
	   << "/_________/ |\n"
	   << "|         | |\n"
	   << "|         | |\n"
	   << "|    *    | |\n"
	   << "|         | /\n"
	   << "|_________|/\n" << endl;
      break;
    case 2:
      cout << "  __________\n"
	   << " /         /|\n"
	   << "/_________/ |\n"
	   << "|         | |\n"
	   << "|      *  | |\n"
	   << "|         | |\n"
	   << "|  *      | /\n"
	   << "|_________|/\n" << endl;
      break;
    case 3:
      cout << "  __________\n"
	   << " /         /|\n"
	   << "/_________/ |\n"
	   << "|         | |\n"
	   << "|      *  | |\n"
	   << "|    *    | |\n"
	   << "|  *      | /\n"
	   << "|_________|/\n" << endl;
      break;
    case 4:
      cout << "  __________\n"
	   << " /         /|\n"
	   << "/_________/ |\n"
	   << "|         | |\n"
	   << "|  *   *  | |\n"
	   << "|         | |\n"
	   << "|  *   *  | /\n"
	   << "|_________|/\n" << endl;
      break;
    case 5:
      cout << "  __________\n"
	   << " /         /|\n"
	   << "/_________/ |\n"
	   << "|         | |\n"
	   << "|  *   *  | |\n"
	   << "|    *    | |\n"
	   << "|  *   *  | /\n"
	   << "|_________|/\n" << endl;
      break;
    case 6:
      cout << "  __________\n"
	   << " /         /|\n"
	   << "/_________/ |\n"
	   << "|         | |\n"
	   << "|  *   *  | |\n"
	   << "|  *   *  | |\n"
	   << "|  *   *  | /\n"
	   << "|_________|/\n" << endl;
      break;
    default:
      cout << "Este resultado es extrañamente raro,\n"
	   << "el programa no debió llegar hasta aquí." <<endl;
    }
}
