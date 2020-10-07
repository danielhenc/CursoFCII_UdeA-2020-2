/**
 * @author Santiago Duque Escobar
 * @brief  Punto 3 del primer parcial de física computacional 2
 */

#include <iostream>
#include "trapezoidalrule.h"


using namespace std;


/**
 * @brief Clase que implementa la función a integrar
 *        La función representa f(x) = 1/x para comparar
 *        con el resultado que se encuentra en el libro
 *        de Branson.
 */
class f_x: public Function
{
public:
   float eval(float x)
   {
       return 1/x;
   }
};


int main()
{
    f_x fx; //Declaración de la
    TrapezoidalRule tr(&fx);

    cout << "El valor exacto de la integral de 1/x desde x=1 hasta x=2 es I=0.693147" << endl;

    cout << "Aproximaciones sucesivas" << endl;
    cout << "k\tI" << endl;

    /* Prueba de iteraciones sucesivas */
    for(int k=2; k<20; k+=2)
    {
        tr.setIterNumb(k);
        cout << k << "\t" << tr.integrate(1, 2) << endl;
    }

    return 0;
}
