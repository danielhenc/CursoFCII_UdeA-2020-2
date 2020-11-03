#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

using std::cout;
using std::endl;


#define len(ptr)    sizeof((ptr)) / sizeof(*(ptr)) //Número de elmentos que contiene un arreglo

/* Definición de los arreglos de punteros */
 const char *articulo[] = {"el", "un", "algun", "ningun"};
 const char *sustantivo[] = {"ninio", "senior", "perro", "ciudad", "auto"};
 const char *verbo[] = {"manejo", "salto", "corrio", "camino", "paso"};
 const char *preposicion[] = {"a", "desde", "encima de", "debajo de", "sobre"};



/*========================*/
/* Prototípo de funciones */
/*========================*/

/**
 * Calula un numero aleatorio entre 0 y max-1
 */
int random(int max);

/*=============================*/
/* definicoón de las funciones */
/*=============================*/

int main()
{
    char oracion[100]; //arreglo donde se almacenará la oración completa

    for(int i=0; i < 20; ++i)
    {
        /* formar la oración */
        sprintf(oracion, "%s %s %s %s %s %s.",articulo[random(len(articulo))],
                                        sustantivo[random(len(sustantivo))],
                                        verbo[random(len(verbo))],
                                        preposicion[random(len(preposicion))],
                                        articulo[random(len(articulo))],
                                        sustantivo[random(len(sustantivo))]);

        /* primera letra en mayuscula */
        oracion[0] = toupper(oracion[0]);

        /* Imprimir la oración completa */
        cout << oracion << endl;
    }

    return 0;
}

int random(int max)
{
    static bool isInitialized = false; //indica si la semilla se ha inicializado

    if(!isInitialized)
    {
        isInitialized = true;
        srand(time(NULL)); //Inicializar la semilla
    }

    return rand()%max; //Número entre 0 y max-1
}

