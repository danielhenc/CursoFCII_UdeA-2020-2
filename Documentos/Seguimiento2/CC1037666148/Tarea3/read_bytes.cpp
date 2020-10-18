#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void leerBytes_a(ifstream &, long,int); //función para realizar el punto 8.6a
void leerBytes_b(ifstream &, long,int,char *); //función para realizar el punto 8.6b

int main()
{
  long d;
  int N;
  char ch[100];
  string texto = "text.txt";
  ifstream archivo_entr(texto.c_str());
  if (archivo_entr.fail())
    {
      cout << "El archivo no se abrió :/"<< endl;
      exit(1);
    }
  cout << "Ingrese la posición desde donde desea ver los caracteres" <<endl;
  cin >> d;
  cout << "Ingrese el número de caracteres que desea ver" <<endl;
  cin >> N;
  leerBytes_a(archivo_entr,d,N);
  leerBytes_b(archivo_entr,d,N,ch);
}




//Función para realizar la parte a del ejercicio
void leerBytes_a(ifstream & archivo_name, long d,int N)
{
  char ch;
  for (int offset = d; offset< d+N;offset++) //se leen los archivos desde una posicion d hasta d+N
    {
      archivo_name.seekg(offset,ios::beg);//el modo de lectura se realiza desde el inicio del archivo. 
      ch = archivo_name.get(); //se obtiene lo que se lee
      cout << ch << ", "; //la lectura se imprime con comas 
    }
  cout << "\n";
  
}

//Función para realizar la parte b del ejercicio
void leerBytes_b(ifstream & archivo_name, long d,int N,char *ch)
{
  
  int i =0;
  for (int offset = d; offset< d+N;offset++)
    {
      archivo_name.seekg(offset,ios::beg);
      ch[i] = archivo_name.get(); //se agrega la salida a un arreglo de chars 
      i++;
    }
  cout << ch <<endl;
  
}
