#ifndef SOLVER_H
#define SOLVER_H

class Solver {
private:
    // coeficientes de la ecuacion
    double m_a;
    double m_b;
    double m_c;

    double round_to_n_decimals(double value, int n);
    double get_discriminant();
public:
    // se puede inicializar la clase con los coeficientes
    Solver(double a, double b, double c);
    // cuando no se pasan coeficientes, estos son cero por defecto
    Solver();

    void set_coefficients(double a=0, double b=0, double c=0);
    void set_a(double a=0);
    void set_b(double b=0);
    void set_c(double c=0);

    // este metodo muestra la ecuacion que actualmente sera resuelta
    void show_equation(int precision=2);
    void show_roots(int precision=2);
};

#endif
