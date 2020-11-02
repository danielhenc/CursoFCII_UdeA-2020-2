#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
  // Arreglos de apuntadores con las palabras a usar
  const char *articulo[] = {"el ", "un ", "algun ", "ningun "};
  const char *sustantivo[] = {"ninio", "senior", "perro", "ciudad", "auto"};
  const char *verbo[] = {"manejo ", "salto ", "corrio ", "camino ", "paso "};
  const char *preposicion[] = {"a ", "desde ", "encima de ", "debajo de ", "sobre "};

  srand(time(NULL));

  cout << "Sus 20 enunciados aleatorios:\n" << endl;
  
  for (int i=1; i<=20; i++)
    {
      char enunciado[50] = ""; // Arreglo para guardar cada enunciado
      
      strcat(enunciado, articulo[rand()%4]);
      strcat(enunciado, sustantivo[rand()%5]);
      strcat(enunciado, " ");
      strcat(enunciado, verbo[rand()%5]); //Asi se aniade cada palabra aleatoria
                                          //al enunciado
      strcat(enunciado, preposicion[rand()%5]);
      strcat(enunciado, articulo[rand()%4]);
      strcat(enunciado, sustantivo[rand()%5]);
      strcat(enunciado, ".");

      //Mayuscula inicial
      enunciado[0] = static_cast<char>(toupper(enunciado[0]));
      
      cout << enunciado << endl;
    }

  return 0;
}
