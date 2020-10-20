#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

// Funcion para determinar la cantidad de caracteres de archivo
int file_size(ifstream& archivo)
{
  string line_prev;
  string line;
  int c=0;
  
  while( getline (archivo, line))
    {
      c += line.length()+1;       
    }
  return c-1;
}

// Funcion para determinar se abrio correctamente el archivo
void checkOpen(ifstream& archivo)
{
  if (archivo.fail())
    {
      cout << "No se pudo abrir el archivo." << endl;
      exit(1);
    }
  else
    {
      cout << "El archivo se abrio exitosamente!" << endl;
    }
}

// Punto 6-a Se encuentra el caracter en la posicion j y se recorren n posiciones y se imprime en pantalla
void leerBytes_a(ifstream& archivo, long i, int n) 
{
  long N=i+n;
  for(long j=i; j<N; j++)
    {
      archivo.seekg(j, ios::beg); 
      
      char out = archivo.get();
      
      if(j+1==N)
	{
	  cout << out << endl;
	}
      else
	{
	  cout << out;
	}
    } 
}

// Punto 6-b Se encuentra el caracter en la posicion j y se recorren n posiciones y se pasa a una cadena string
void leerBytes_b(ifstream& archivo, long i, int n, string& sal) //
{
  long N=i+n;
  for(long j=i; j<N; j++)
    {
      archivo.seekg(j, ios::beg);
      
      char out = archivo.get();
      
      sal = sal + out;
    }
}


int main()
{
  string name_file; // Cadena con nombre del archivo
  int n;            // Posiciones a recorrer
  long i;           // Posicion inicial
  
  cout << "Ingrese el nombre del archivo: ";
  cin >> name_file;
    
  ifstream archivo_in(name_file.c_str()); // Se abre el archivo

  checkOpen(archivo_in); // Se comprueba que funciono
  
  int c = file_size(archivo_in); // Se calculan la cantidad de caracteres

  cout << "Cantidad de carateres: ";
  cout << c << endl;
  
  archivo_in.close(); // Se cierra y abre de nuevo el archivo

  archivo_in.open(name_file.c_str());
  
  cout << "Ingrese la posicion inicial de lectura (Inicia en 0 hasta " << c-1 << "):\n";
  cin >> i;

  while(i>c-1) // Se comprueba que i no pase la cantidad de caracteres
    {
      cout << "Se sobrepasa la longitud del archivo. Ingrese la posicion inicial de lectura de nuevo!!" << endl;
      cin >> i;
    }
  
  cout << "Ingrese la cantidad de caracteres a leer:\n";
  cin >> n;

  string salida; // Cadena para guardar los caracteres desde i hasta i+n

  while(i+n-1>c) // Se comprueba que recorrido no pase el tamaño de texto
    {
      cout << "Se sobrepasa la longitud del archivo. Introduzca los numeros de nuevos!!" << endl;

      cout << "Ingrese la posicion inicial de lectura:\n";
      cin >> i;
  
      cout << "Ingrese la cantidad de caracteres a leer:\n";
      cin >> n;
    }

  leerBytes_a(archivo_in, i, n);
  leerBytes_b(archivo_in, i, n, salida);
  
  cout << salida << endl; // Se comprueba que se almacenen los caracteres
  
  archivo_in.close(); // Se cierra el archivo
      
  return 0;
}
