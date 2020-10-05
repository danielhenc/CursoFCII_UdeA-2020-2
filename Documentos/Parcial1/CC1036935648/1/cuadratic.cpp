#include "cuadratic.h"
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <exception>

using std::cout;
using std::endl;


roots::roots()
{
  /* Inilializar las raices como x = 0 + 0i */
  r[0] = std::complex<float>();
  r[1] = std::complex<float>();
}

std::complex<float>& roots::operator[](unsigned int i)
{
    if(i>=2) // El índice está fuera de rango?
        throw std::out_of_range("Indice fuera de rango!"); //lanzar excepción
    return r[i];
}


cuadratic::cuadratic(float a, float b, float c)
{
    setParameters(a, b, c);
}

roots cuadratic::getRoots()
{
    float dis = pow(b,2) - 4*a*c; //Discriminante
    bool isComplex = (dis < 0)? true : false; //Las raices son complejas?

    /*
     * x = c1 +- c2
     * ó
     * x = c1 +- ic2
     */
    float c1 = -b/(2*a);
    float c2 = isComplex? sqrt(-dis)/(2*a) : sqrt(dis)/(2*a);

    if(isComplex)
    {
        r[0] = std::complex<float>(c1,c2);
        r[1] = std::complex<float>(c1,-c2);
    }
    else
    {
        r[0] = std::complex<float>(c1+c2);
        r[1] = std::complex<float>(c1-c2);
    }

    return r;
}

void cuadratic::printRoots()
{
    getRoots();

    /*primera raiz*/
    cout << "x_1 = " << std::setprecision(2) << r[0].real(); //Parte real
    cout << (r[0].imag() < 0? " " : " +") << std::setprecision(2) << r[0].imag() << "i"<< endl; //Parte imaginaria

    /*segunda raiz*/
    cout << "x_2 = " << std::setprecision(2) << r[1].real(); //Parte real
    cout << (r[1].imag() < 0? " " : " +") << std::setprecision(2) << r[1].imag() << "i"<< endl; //Parte imaginaria
}

void cuadratic::setParameters(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}



