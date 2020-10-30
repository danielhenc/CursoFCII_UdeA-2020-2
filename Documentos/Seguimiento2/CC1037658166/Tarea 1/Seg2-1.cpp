#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    srand(time(NULL));
    
    const char *articulo[4] = {"el","un","algun","ningun"};
    const char *sustantivo[5] = {"niño","señor","perro","ciudad","auto"};
    const char *verbo[5] = {"manejo","salto","corrio","camino","paso"};
    const char *preposicion[5] = {"a","desde","encima de","debajo de","sobre"};
    
    
    // Genera 20 frases aleatorias con estructura: ASVPAS
    
    for (int i = 0; i < 20; i++)
    {
        // 100 ~ Tamaño maximo de la frase
        char frase[100] = ""; 
    
        strcat(frase, articulo[rand() % 4] );
        // Vuelve mayuscula la primera letra
        frase[0] = toupper(frase[0]);
        
        strcat(frase, " ");
        strcat(frase, sustantivo[rand() % 5] );
        strcat(frase, " ");
        strcat(frase, verbo[rand() % 5] );
        strcat(frase, " ");
        strcat(frase, preposicion[rand() % 5] );
        strcat(frase, " ");
        strcat(frase, articulo[rand() % 4] );
        strcat(frase, " ");
        strcat(frase, sustantivo[rand() % 5] );
        strcat(frase,".");
    
        cout << "Frase " << i+1 << ": " << frase << endl;
        
    }
    
    return 0;
}
