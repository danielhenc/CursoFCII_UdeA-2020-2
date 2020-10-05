/**
 * @author Santiago Duque Escobar
 * @brief  Punto 1 del primer parcial de física computacional 2
 */

#include <iostream>
#include <iomanip>
#include "cuadratic.h"

using std::cout;
using std::endl;



int main()
{
    cuadratic c;

    cout << "========================" << endl;
    cout << "      x^2 - 1 = 0" << endl;
    cout << "========================" << endl;
    c.setParameters(1,0,-1);
    c.printRoots();

    cout << endl;
    cout << "========================" << endl;
    cout << "      x^2 + 1 = 0" << endl;
    cout << "========================" << endl;
    c.setParameters(1,0,1);
    c.printRoots();

    cout << endl;
    cout << "========================" << endl;
    cout << "      x^2 + 2 + 1 = 0" << endl;
    cout << "========================" << endl;
    c.setParameters(1,2,1);
    c.printRoots();

    return 0;
}

