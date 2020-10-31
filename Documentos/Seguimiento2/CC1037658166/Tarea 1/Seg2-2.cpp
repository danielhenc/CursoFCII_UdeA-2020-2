#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int main()
{
    srand(time(NULL));
    
    // Longitud de los array de char
    int la = 1;
    int ls = 20;
    int lv = 22;
    int lp = 7;
    int lc = 7;
    int lr = 6; 
    
    const char *articulo[la] = {"el"};
    const char *sustantivo[ls] = {"niño","señor","perro","pueblo","auto","vaso de agua","lapicero","universo","lagrangiano","epitafio","vestigio","rey","gato","pie","programa de c++","colectivo de buses","estado","apocalipsis","principio de todas las cosas","intersecto"};
    const char *verbo[lv] = {"penso en ", "se tomo","desperto en","leyo","manejo a ","calculo","corrio","discerto con", "describio","deformo","nacio en","elevo a","anticipo a","arruino a","miro hacia","borro","disimulo","evito","guardo","temio a","inicio","destino a"};
    const char *conector[lc] = {"ademas","a causa de que","pues","así que","apenas","cuando","de modo que"};
    const char *adverbio[lr] = {"rapidamente","de forma silenciosa","con presteza","con amor","al reves","inmediatamente"};
    
    /*
    Para enriquecer el programa, decidi añadir 2 categorias extra como lo son los conectores y los adverbios. Para no sobrecargar las oraciones de adverbios, considere un numero aleatorio del 1 al 10, y si este era mayor que 7, añadia un adverbio al final. Por otro lado, tambien añadi una posibilidad de añadir posesion a los sustantivos con un "del" + otro sustantivo. Al final, las historias generadas pueden ser tan extrañas como se quiera, agregando mas y mas palabras, enriqueciendo la generacion. Sin embargo, añadir muchos verbos y sustantivos añade ilogica, dado que muchos verbos son unicamente compatibles con ciertos sustantivos, y asi. 
    */
    
    char frase[4000] = "";
    int number_of_sentences = 10;
    
    for (int i = 0; i < number_of_sentences; i++)
    {
        strcat(frase, articulo[rand() % la] );
        if (i == 0)
        {
            frase[0] = toupper(frase[0]);
        }
        strcat(frase, " ");
        strcat(frase, sustantivo[rand() % ls] );
        strcat(frase, " ");
        
        if ((rand() % 10) > 7)
        {
            strcat(frase, "del ");
            strcat(frase, sustantivo[rand() % ls] );
            strcat(frase, " ");
        }
        if ((rand() % 10) > 7)
        {
            strcat(frase, "no");
            strcat(frase," ");
        }
        
        strcat(frase, verbo[rand() % lv] );
        strcat(frase, " ");
        strcat(frase, articulo[rand() % la] );
        strcat(frase, " ");
        strcat(frase, sustantivo[rand() % ls] );
        strcat(frase, " ");
        
        if ((rand() % 10) > 7)
        {
            strcat(frase, "del ");
            strcat(frase, sustantivo[rand() % ls] );
            strcat(frase, " ");
        }
        

        if( i != number_of_sentences - 1)
        {
            if ((rand() % 10 ) > 6)
            {
                strcat(frase,adverbio[rand() % lr]);
                strcat(frase, " ");    
            }
        
            strcat(frase,conector[rand() % lc]);
            strcat(frase, " ");
        }
        else
        {
            strcat(frase,".");
        }
    }
    
    cout <<  frase << endl;
    
    return 0;
}
