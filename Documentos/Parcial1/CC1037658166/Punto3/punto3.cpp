// Jacobo Parodi Díez - Parcial 1 de Física Computacional II

#include <iostream>
#include <cmath>
using namespace std;

float trapezoid(float (*f)(float), float a, float b, int n)
{
    /*
    Regla del trapecio:
    Entrada:
        - f : Funcion a integrar
        - a : Límite inferior de integración
        - b : Límite superior de integración
        - n : Número de trapecios usados
        
    Salida:
        - suma : Estimado de la integral
    */
    
    float h = (b-a)/n; 
    float suma = 0.5*h*(f(a) + f(b));
        
    for(int i = 1; i < n ; i++ )
    {
        suma += h*f(a+i*h);
    }
    
    return suma;
}

// Función a integrar. Se puede probar con cualquiera.
float f(float x)
{
    return sin(x)*pow(x,3) - log(x);
}


int main()
{
    float a,b;
    int n;
    
    cout << "Límite inferior: ";
    cin >> a;
    
    cout << "Límite superior: ";
    cin >> b;
    
    cout << "Número de trapecios: ";
    cin >> n;
    
    float S = trapezoid(f,a,b,n);

    cout << "Valor de la integral: " << S << endl;
        
    return 0;
}

