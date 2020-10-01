#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip> 

#include "solver.h"

double Solver::round_to_n_decimals(double value, int n){
    int multiplier = pow(10, n);

    return round(value * multiplier) / multiplier;
}

double Solver::get_discriminant(){
    return pow(m_b, 2) - 4 * m_a * m_c;
}

// se puede inicializar la clase con los coeficientes
Solver::Solver(double a, double b, double c){
    m_a = a;
    m_b = b;
    m_c = c;
}

// cuando no se pasan coeficientes, estos son cero por defecto
Solver::Solver(){
    m_a = 0;
    m_b = 0;
    m_c = 0;
}

void Solver::set_coefficients(double a, double b, double c){
    m_a = a;
    m_b = b;
    m_c = c;
}

void Solver::set_a(double a){
    m_a = a;
}

void Solver::set_b(double b){
    m_b = b;
}

void Solver::set_c(double c){
    m_c = c;
}

// este metodo muestra la ecuacion que actualmente sera resuelta
void Solver::show_equation(int precision){
    // no se hace el redondeo con setprecision, pues esa forma solo funciona
    // con el metodo cout. Se usa printf pues esta brinda mas versatilidad
    // al momento de hacer el formateo
    double a = round_to_n_decimals(m_a, precision);
    double b = round_to_n_decimals(m_b, precision);
    double c = round_to_n_decimals(m_c, precision);

    printf("(%lf)x^2 + (%lf)x + (%lf)\n", a, b, c);
}

void Solver::show_roots(int precision){
    double discriminant = get_discriminant();
    double real_part = -m_b / (2 * m_a);

    std::cout << std::setprecision(precision);
    // discriminante negativo, raices complejas
    if (discriminant < 0) {
        double imag_part = sqrt(-1 * discriminant) / (2 * m_a);

        // la raiz 1 es la que tiene la raiz del discriminante positivo,
        // si el coeficiente a es negativo entonces la raiz se vuelve negativa
        if (m_a > 0) {
            // las raices complejas son conjugadas entre si
            std::cout << "root 1: " << real_part << " + " << '(' << imag_part << ")i\n";
            std::cout << "root 2: " << real_part << " - " << '(' << imag_part << ")i\n";
        } else {
            std::cout << "root 1: " << real_part << " - " << '(' << imag_part << ")i\n";
            std::cout << "root 2: " << real_part << " + " << '(' << imag_part << ")i\n";
        }
    } else {
        std::cout << "root 1: " << real_part + sqrt(discriminant) / (2 * m_a) << '\n';
        std::cout << "root 2: " << real_part - sqrt(discriminant) / (2 * m_a) << '\n';
    }
}
