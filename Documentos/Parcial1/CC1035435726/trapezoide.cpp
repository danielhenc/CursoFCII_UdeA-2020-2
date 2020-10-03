#include <iostream>
#include <cmath>
using namespace std;

//prototipo de la funcion a integrar
double f(double);
//prototipo de la regla trapezoidal
double trap(double, double, unsigned int);

int main()
{
    //a = valor inicial o limite inferior, y b = valor final o limite superior
    double a, b;
    //numero de terminos que se usaran en el calculo de la integral
    unsigned int N;
    
    cout << "Ingrese el limite inferior a: ";
    cin >> a;
    cout << "Ingrese el limite superior b: ";
    cin >> b;
    cout << "Ingrese el numero de terminos para calcular la integral: ";
    cin >> N;
    
    //se llama a la funcion
    double I = trap(a, b, N);
    cout << "El resultado de la integral es I = " << I << endl;
    return 0;
}

//Funcion escogida: (1 + x**2)**(3/2), en el ejemplo del libro se toma a = 0, b = 1.
double f(double x)
{
    double y = pow((1 + pow(x, 2)), 3. / 2.);
    return y;
}

//Regla trapezoidal
double trap(double a, double b, unsigned int N)
{
    //T_k = k-esimo termino, inicialmente T0.
    double T_k = 0.5 * (f(a) + f(b) * (b - a));
    //Se obtienen los terminos de orden superior.
   
    for (int k = 1; k < N; k++) {
    	//ancho del "panel"
        double dx_k = (b - a) * pow(0.5, k);
        //2^k
        int n = pow(2, k);
        
        //termino que se le sumara al Tk
        double sum = 0;
        
        for (int i = 1; i <= n - 1; i++) {
            //solo se suma sobre los impares
            if (i % 2 == 1) {
                sum += f(a + i * dx_k);
            }
        }
        //nuevo termino t_k
        T_k = 0.5 * T_k + dx_k * sum;
    }
    //se envia el ultimo termino calculado
    return T_k;
}
