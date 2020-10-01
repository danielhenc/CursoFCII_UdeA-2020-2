#include <iostream>

using namespace std;

//clase para calcular las raíces de un polinomio cuadrático

class Raices{ 

private:
    float a, b, c;
    
public:
    Raices();
    void asignar_datos(float, float, float); //para declarar los valores de los coeficientes a, b, y c
    double calcular_raices(); //para calcular las raíces y mostrar los resultados

};
