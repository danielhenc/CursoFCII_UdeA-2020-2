#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leerBytes(fstream&, long, int);

int main()
{
  string nombre_archivo = "prueba.txt";
  long caracter0 = 13; // Caracter requerido inicial
  int N = 45; // Numero de caracteres pedidos
  
  fstream archivo_entrada(nombre_archivo.c_str(), ios::in);

  if (archivo_entrada.fail())
    {
      cout << "\nEl archivo no se pudo abrir. Verifique si existe." << endl;
      exit(1);
    }
  
  leerBytes(archivo_entrada, caracter0, N); // Lee y despliega los caracteres pedidos (si sus posiciones son validas)
  
  cout << endl;
  return 0;
}

// Funcion que lee e imprime los caracteres pedidos (segun sus ubicaciones) del archivo que se le pase
void leerBytes(fstream& archivo, long caracter_inic, int n_caract)
{
  archivo.seekg(0L, ios::end); // Se mueve al final del archivo
  long ultimo = archivo.tellg(); // Posicion del ultimo caracter

  // Se verifica que las posiciones de los caracteres solicitados sean validas
  if ((caracter_inic + n_caract) > ultimo)
    {
      cout << "Las posiciones de los caracteres requeridos se salen del archivo. Solicite posiciones dentro del archivo." << endl;
    }

  else
    {
      char caract;
      cout << "Los " << n_caract << " caracteres consecutivos desde la posicion " << caracter_inic << " de su archivo son:\n" << endl;
  
      for (int i=0; i<n_caract; i++)
	{
	  archivo.seekg(caracter_inic + i, ios::beg); // Se lee cada caracter
	  caract = archivo.get();
	  cout << caract << " | "; // Se imprimen
	}
    }  
}
