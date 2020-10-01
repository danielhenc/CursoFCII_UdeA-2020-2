#include "Cuadratica.h"

//interfaz de usuario 
int main()
{
    //coeficientes
    double a_, b_, c_;

    cout << "Bienvenido al programa para calcular las raices de un polinomio a*x^2 + b*x + c: \nIngrese el valor de a: ";
    cin >> a_;

    cout << "Ingrese el valor de b: ";
    cin >> b_;

    cout << "Ingrese el valor de c: ";
    cin >> c_;

    //instancia de la clase
    Cuadratica myCuadra(a_, b_, c_);
    //se llama al metodo que imprime y calcula las raices
    myCuadra.getRoots();

    return 0;
}

