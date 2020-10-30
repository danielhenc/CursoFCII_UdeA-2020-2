#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int length(ifstream &); //Para encontrar la longitud del arreglo
void leerBytes_a(ifstream &, long,int); //función para realizar el punto 8.6a
void leerBytes_b(ifstream &, long,int,char *); //función para realizar el punto 8.6b
int main()
{
  long d; //Posición en el arreglo
  
  int N; //Número de caracteres

  string texto = "text.txt"; //Nombre del texto

  ifstream archivo_entr(texto.c_str());

  if (archivo_entr.fail()) //Comprueba que el archivo fue leído
    {
      cout << "El archivo no se abrió :/"<< endl;
      exit(1);
    }

  int size = length(archivo_entr);
  bool is_incorrect = true;

  cout << "El número de caracteres en el archivo es de: " << size << endl;

  while (is_incorrect) //Se prueba que el usuario ingrese los valores correctos para d
    {
      cout << "Ingrese la posición desde donde desea ver los caracteres:" <<endl;
      cin >> d;
      if (d >size)
	{
	  cout << "Esta posición excede el tamaño del archivo. Por favor ingresar una nueva." << endl;
	}
      else
	is_incorrect = false;
    }

  
  is_incorrect = true;

  while (is_incorrect)  //Se prueba que el usuario ingrese los valores correctos para N
    {
      cout << "Ingrese el número de caracteres que desea ver" <<endl;
      cin >> N;
      if (d+N >size)
	{
	  cout << "El número de caracteres que desea ver excede el número de carecteres que hay en el texto  desde la posición "<< d <<
	       ". \n" << "Ingrese de nuevo el valor:" << endl;
	}
      else
	is_incorrect = false;
    }
  
  char ch[N+1]; 
  leerBytes_a(archivo_entr,d,N);
  leerBytes_b(archivo_entr,d,N,ch);
 }



int length(ifstream & archivo_entr)
{
  string tx;
  getline(archivo_entr,tx);
  return  tx.length();
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
  ch[i] = '\0'; //Se agrega el caracter nulo
  cout << ch <<endl;
  
}
