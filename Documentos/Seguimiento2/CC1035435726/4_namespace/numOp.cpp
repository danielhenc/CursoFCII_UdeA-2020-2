#include <iostream>
#include <iomanip>

using namespace std;

//espacio de nombre para operaciones numericas
//punto 5c y 6c
namespace numOp {

//punto 5, a
int entero(int N)
{
    return N;
}

//punto 6, a
double partefracc(double num)
{
    return num - entero(num);
}

} // fin del namespace numOp
