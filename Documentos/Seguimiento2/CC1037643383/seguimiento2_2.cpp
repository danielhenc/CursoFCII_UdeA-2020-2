#include <iostream>

namespace Parte
{
	
  int entera(double num) //Recibe un número y retorna su parte entera.
	{
		return num;
	}

  double fraccional(double num) //Calcula la parte fraccional haciendo la diferencia del número con su parte entera
	{
		return num - entera(num);
	}
}
