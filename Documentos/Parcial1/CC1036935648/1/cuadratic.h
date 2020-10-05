/**
 * @author Santiago Duque Escobar
 * @brief  Clases que definen una ecuación cuadrática
 */

#include <complex>

/**
 * Clase con las raices de un polinomio cuadrático
 * (dos números complejos)
 */
class roots
{
public:
    roots();

    /*
    * Sobrecarga del operador [] para poder tratar las
    * raices como un arreglo
    */
    std::complex<float>& operator [](unsigned int);

private:
    std::complex<float> r[2]; //Raices
};

class cuadratic
{
public:

    /**
    * Constructor de un polinomio cuadrático
    * de la forma ax^2 +bx + c
    */
    cuadratic(float a=0, float b=0, float c=0);

    /**
     * Modifica los parámetros del polinomio
     * ax^2 + bx + c
     */
    void setParameters(float a, float b, float c);

    /**
     * Retorna las raices del polinomio
     */
    roots getRoots();

    /**
     * Imprime en pantalla las raices del polinomio
     */
    void printRoots();

private:
    float a,b,c; //Parámetros del polinomio
    roots r; //raices del polinomio
};


