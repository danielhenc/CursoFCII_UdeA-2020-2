#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#include "Cuadratica.h"

//Constructor, donde se establecen los coeficientes iniciales.
Cuadratica::Cuadratica(double a_, double b_, double c_)
{
    seta(a_);
    setb(b_);
    setc(c_);
}

void Cuadratica::seta(double a_)
{
    a = a_;
}

void Cuadratica::setb(double b_)
{
    b = b_;
}

void Cuadratica::setc(double c_)
{
    c = c_;
}

double Cuadratica::geta()
{
    return a;
}

double Cuadratica::getb()
{
    return b;
}

double Cuadratica::getc()
{
    return c;
}

//Funcion para obtener las raices
void Cuadratica::getRoots()
{
    //discriminante
    double delta = b * b - 4 * a * c;

    cout << "Las raices son: " << endl;
    //se valida si las raices son reales
    if (delta > 0) {
    	//fijar precision
        cout << fixed;
        //imprime ambas raices con 2 puntos decimales. 
        cout << "x_1 = " << setprecision(2) << 0.5 * (-b + pow(delta, 0.5)) / a << endl;
        cout << "x_2 = " << setprecision(2) << 0.5 * (-b - pow(delta, 0.5)) / a << endl;
    }
    else {
    	//cuando se trata de una raiz
        cout << fixed;
        //imprime primero la parte real de cada raiz y se le anida la parte imaginaria, donde se usa -delta en caso de que delta < 0 para el calculo de la raiz sin errores.
        cout << "x_1 = " << setprecision(2) << -0.5 * b / a << " + " << setprecision(2) << 0.5 * pow(-delta, 0.5) / a << "i" << endl;
        cout << "x_2 = " << setprecision(2) << -0.5 * b / a << " - " << setprecision(2) << 0.5 * pow(-delta, 0.5) / a << "i" << endl;
    }
}
