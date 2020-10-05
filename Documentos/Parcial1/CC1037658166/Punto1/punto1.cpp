#include <iostream>
#include <cmath>
#include <iomanip>
#include "punto1.h"
#include <tuple>

using namespace std;

second_order_equation_solver::second_order_equation_solver(float a,float b,float c)
{    
    // Redirigue al método set_coefficientes
    set_coefficients(a,b,c);
}

void second_order_equation_solver::set_coefficients(float a,float b,float c)
{
    // Establece los coeficientes como atributos de la clase
    A = a;
    B = b;
    C = c;
}

void second_order_equation_solver::calculate_roots()
{
    float Delta = pow(B,2) - 4*A*C; // Discriminante
        
    // Se usan tuplas para guardar por a parte los valores real e imaginarios de las raices
    
    // Establece los valores para R1 y R2 que son atributos de la calse y corresponden a las raices del polinomio

        if (Delta >= 0)
        {
            R1 = make_tuple(( -B + sqrt(Delta) )/(2.*A) , 0.);
            R2 = make_tuple(( -B - sqrt(Delta) )/(2.*A) , 0.);
        }
        else
        {
            R1 = make_tuple(( -B/(2.*A)),+ sqrt(-Delta)/(2.*A));
            R2 = make_tuple(( -B/(2.*A)),- sqrt(-Delta)/(2.*A));
        }
}

void second_order_equation_solver::display_roots()
{
    // Muestra un mensaje con los valores de las raíces. Debe haberse usado previamente calculate_roots() para que esto tenga sentido.
    
    cout << "Las raices de la ecuacion " << setprecision(3) << A << "x^2 + " << setprecision(3) << B << "x + " << setprecision(3) << C << " = 0 son:" << endl;
    
    cout << "Primera raíz: " << setprecision(3) << get<0>(R1) << " + " << setprecision(3) << get<1>(R1) << "i" << endl;
    
    cout << "Segunda raíz: " << setprecision(3) << get<0>(R2) << " + " << setprecision(3) << get<1>(R2) << "i" << endl;
}











