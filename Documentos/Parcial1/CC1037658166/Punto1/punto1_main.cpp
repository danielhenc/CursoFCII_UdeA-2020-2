// Jacobo Parodi Díez - Parcial 1 de Física Computacional II

#include <iostream>
#include <cmath>
#include <tuple>
#include "punto1.h"
using namespace std;

int main()
  {
    
    // Equation coefficients
    float a;
    float b; 
    float c;
    
    cout << "Este programa determina las raices de un ecuación cuadrática con 2 grados de presición" << endl;
    cout << "Por favor ingrese los coeficientes de su ecuación según ax^2 + bx + c = 0" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    second_order_equation_solver Solver(a,b,c);
    Solver.calculate_roots();
    Solver.display_roots();

    return 0;
  }

