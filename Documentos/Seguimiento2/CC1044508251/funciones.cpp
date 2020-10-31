#include<iostream>
#include<math.h>
#include<string>

using namespace std;

//=======================================================
//PUNTO 5 - Parte A Y B

/*
// Funcion que devuelve el valor entero asociado
int enteros(double n)
  {
    int N = n;
    return N;
  }

// Se usa la funcion para probarla
int main()
{
  double i;
  cout << "Ingrese un numero:\n";
  cin >> i;
  cout << "\nParte entera: " << enteros(i) << endl;
}
//*/

//=======================================================
//PUNTO 6 - Parte A y B
//*
// Funcion que devuelve la parte entera del numero
int enteros(double n)
  {
    int N = n; // Lo convierte a entero
    return N;
  }

// Funcion que devuelve la parte decimal
double partefracc(double n)
  {
    return n - enteros(n);
  }

// Se prueban ambas funciones
int main()
{
  double i;
  
  cout << "Ingrese un numero:\n";
  cin >> i;
  
  cout << "\nParte entera: " << enteros(i) << "\nParte decimal: " << partefracc(i) << endl;
}
//*/
