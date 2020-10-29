#include <iostream>
#include <string>

using namespace std;

bool numero_real(string);

namespace Parte_entera_y_decimal
{
  string entrada; // Para compartir el numero completo entre funciones
  int parte_entera; // Para compartir la parte entera
  
  int entero()
  {
    bool invalido = true;
    while (invalido)
      {
	try
	  {
	    getline(cin, entrada); // Recibe la entrada del usuario
	    if (!numero_real(entrada)) // Verifica que sea un numero real
	      {
		throw entrada;
	      }
	  }
	
	catch(string entrada) //En caso de que no sea un numero real la entrada
	  {
	    cout << "\nNo es un numero real. Por favor escriba un numero real: ";
	    continue;
	  }
	
	invalido = false;
      }
    
    parte_entera = atoi(entrada.c_str());
    
    return parte_entera;
  }
  
  double partefracc()
  {
    // La parte decimal es la diferencia entre el numero completo
    // y su parte entera
    double parte_fracc = atof(entrada.c_str()) - parte_entera;
    
    return parte_fracc;
  }
}

// Funcion que verifica si un string se refiere a un numero real
// Es utilizada en el namespace
bool numero_real(string numero)
{
  bool valido = true;
  bool signo = false;
  int inicio = 0;
  
  if (numero.length() == 0) // Comprueba primero si el string tiene algo
    {
      valido = false;
    }
  
  else
    {
      // Revisa si empieza con un signo
      if (numero.at(0) == '-' or numero.at(0) == '+')
	{
	  signo = true;
	  inicio = 1;
	  
	  // Mira si tiene algo ademas del signo
	  if (numero.length() == 1)
	    {
	      valido = false;
	    }
	}
      
      int i = inicio;
      int puntos = 0; // Conteo de puntos decimales
      
      // Para verificar los elementos restantes del string
      while (valido and i<numero.length())
	{
	  
	  if (!isdigit(numero.at(i)) and numero.at(i) != '.') // Comprueba que no sea un digito ni un punto
	    {
	      valido = false;
	    }
	  
	  else if (numero.at(i) == '.') // Si es un punto, que lo cuente
	    {
	      
	      // Que no se ingrese un punto solo
	      if (!signo and numero.length() == 1)
		{
		  valido = false;
		}

	      if (signo and numero.length() == 2)
		{
		  valido = false;
		}
	      
	      puntos++;
	      
	      // Si hay mas de un punto, no es valido el numero
	      if (puntos > 1)
		{
		  valido = false;
		}
	    }
	  
	  i++;
	}
    }
  
  return valido;
}
