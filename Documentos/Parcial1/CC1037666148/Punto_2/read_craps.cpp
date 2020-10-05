#include <iostream>
#include "c_craps.h"

using namespace std;


int main()
{
  char t_apos;
  int apuesta;
  int r_apuest;
  cout << "Este es el juego de Craps. ¿Desea jugar en modo apuesta?(y o n)" <<endl;
  cin >> t_apos; 
  
  if (t_apos == 'n')
    {
      Craps_Game playing_craps(0);
      playing_craps.craps();
    }
  else if (t_apos =='y')
    {
      cout << "Ingrese la cantidad de su apuesta" << endl;
      cin >> apuesta;
      Craps_Game playing_craps(apuesta);
      r_apuest = playing_craps.saldo();
      
      while (r_apuest < 0)
	{
	  cout << "El valor de la apuesta supera el saldo en banco, ingrese de nuevo el valor de su apuesta en pesos Colombianos." << endl;
	  cin >> apuesta;
	  Craps_Game playing_craps(apuesta);
	  r_apuest = playing_craps.saldo();
	}
      playing_craps.craps();
   
    }
  return 0;
}

