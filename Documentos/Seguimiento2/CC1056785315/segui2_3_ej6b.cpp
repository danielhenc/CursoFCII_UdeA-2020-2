#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leeryguardarBytes(fstream&, long, int, string*);

bool imp_arreglo = false; // Para comunicarle al main si los caracteres fueron validos

int main()
{
  string nombre_archivo = "prueba.txt";
  long caracter0 = 6; // Posicion caracter requerido inicial
  int N = 20; // Numero de caracteres pedidos
  string arreglo_carac[N]; // Arreglo para guardar los caracteres
  
  fstream archivo_entrada(nombre_archivo.c_str(), ios::in);

  if (archivo_entrada.fail())
    {
      cout << "\nEl archivo no se pudo abrir. Verifique si existe." << endl;
      exit(1);
    }
  
  leeryguardarBytes(archivo_entrada, caracter0, N, arreglo_carac); // Lee y guarda en un arreglo los caracteres pedidos (si sus posiciones son validas)

  // Se imprimen los caracteres guardados en el arreglo

  if (imp_arreglo)
    {
      cout << "Los caracteres del arreglo son:\n" << endl;
      for(int i = 0; i<N; i++)
	{
	  cout << arreglo_carac[i];
	}
    }
  
  cout << endl;
  return 0;
}

// Funcion que lee y guarda en un arreglo los caracteres pedidos (segun sus ubicaciones) del archivo que se le pase

void leeryguardarBytes(fstream& archivo, long caracter_inic, int n_caract, string* dir)
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
      imp_arreglo = true;
      
      for (int i=0; i<n_caract; i++)
	{
	  archivo.seekg(caracter_inic + i, ios::beg); // Se lee cada caracter
	  caract = archivo.get();
	  *(dir + i) = caract; // Se guarda cada caracter a partir de la direccion pasada a la funcion
	}
    }  
}
