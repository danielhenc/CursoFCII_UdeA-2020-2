// Jacobo Parodi Díez - Parcial 1 de Física Computacional II

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int Throw_two_dices()
{
    int dice1 = 1 + rand() % 6;
    int dice2 = 1 + rand() % 6;
    
    return dice1 + dice2;  
}

int main()
{
    srand(time(NULL));
    string keep;
    int triumph_val = 0;
    
    while(true)
    {
        cout << "Keep going? (y/n)  ";
        cin >> keep;
        
        if (keep == "y")
        {
            int val = Throw_two_dices();
            cout << val << endl;
            
            if (triumph_val == 0)
            {
                // Dado que aún no se tiene punto triunfo, se ejecuta esta aprte del código
                // (Todo lo del punto triunfo está explicado detalladamente en el subpunto 2 de este punto)

                if( (val == 7)||(val == 11) )
                {
                    // Se gana directamente con 7 Ú 11
                    cout << "You have win!" << endl;
                    break;
                }
                else if( (val == 2)||(val == 3)||(val == 12))
                {
                    // Se pierde directamente con 2,3 Ó 12
                    cout << "Craps. You have lost :p" << endl;
                    break;
                }
                else
                {
                    // Se establece el punto triunfo
                    triumph_val = val;
                    cout << "Now, your triumph value is " << val << endl;
                }
            }
            else
            {
                if(val == triumph_val)
                {
                    // Se volvió a obtener el punto triunfo. Se gana
                    cout << "You have win!" << endl;
                    break;
                }
                else if(val == 7)
                {
                    // En punto triunfo se obtuvo un 7. Se pierde
                    cout << "Craps. You have lost :p" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Game end" << endl;
            break;
        }
    }

    return 0;
}
