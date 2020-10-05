#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

using std::cout;
using std::endl;

/* Número de elmentos que contiene un arreglo */
#define len(ptr)    sizeof((ptr)) / sizeof(*(ptr))

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

/**
 * Improme una oración sin el salto de linea
 */
void printSentence();

/*=============================*/
/* definicoón de las funciones */
/*=============================*/

int main()
{
    int nParrafos = random(4)+2; //Imprimir entre 2 y 5 parrafos

    for(int i=0; i < nParrafos; ++i)
    {
        int nOraciones = random(7)+4; //Imprimir entre 4 y 10 oraciones por párrafo

        for(int j=0; j<nOraciones; ++j)
            printSentence();
        cout << endl << endl; //Doble salto de linea para separa los párrafos
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

void printSentence()
{
    char oracion[100]; //arreglo donde se almacenará la oración completa

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
    cout << oracion;
}

