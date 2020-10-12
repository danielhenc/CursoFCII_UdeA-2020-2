#include<iostream>
#include<math.h>
#include<string>

using namespace std;

//=======================================================
//PUNTO 5 - Parte A Y B

/*
// Funcion que recibe un numero tipo string y devuelve el valor entero asociado
int enteros(string n)
  {
    int N = stof(n);
    return N;
  }

// Se usa la funcion para probarla
int main()
{
  string i;
  cout << "Ingrese un numero:\n";
  cin >> i;
  cout << "\nValor ingresado: "<< i << " \nParte entera: " << enteros(i) << endl;
}
*/

//=======================================================
//PUNTO 6 - Parte A y B
//*
// Funcion que devuelve la parte entera del numero
int enteros(string n)
  {
    int N = stof(n); // Lo convierte a entero
    return N;
  }

// Funcion que devuelve la parte decimal
float partefracc(string n)
  {
    int pos = n.find('.'); // Encuentra el punto del string
    string dec = "0";
    
    for(int i=pos; i<n.size(); i++) // Agrega los valores despues del punto
      {
	dec = dec+n[i];
      }
    
    float res = stof(dec); // Lo convierte a float
    return res;
  }

// Se prueban ambas funciones
int main()
{
  string i;
  
  cout << "Ingrese un numero:\n";
  cin >> i;
  
  cout << "\nValor ingresado: " << i << "\nParte entera: " << enteros(i) << "\nParte decimal: " << partefracc(i) << endl;
}
//*/
