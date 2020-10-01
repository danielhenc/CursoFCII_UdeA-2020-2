#include <iostream>
#include <string>

#include "solver.h"


double get_input(std::string message);

int main() {
    Solver solver;

    double a = get_input("Ingrese el valor del coeficiente a: ");
    double b = get_input("Ingrese el valor del coeficiente b: ");
    double c = get_input("Ingrese el valor del coeficiente c: ");

    solver.set_coefficients(a, b, c);

    solver.show_equation();
    solver.show_roots();

    return 0;
}

double get_input(std::string message){
    double value;

    std::cout << message;
    std::cin >> value;

    return value;
}
