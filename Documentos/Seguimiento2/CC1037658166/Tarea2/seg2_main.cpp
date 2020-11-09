#include <iostream>
#include <string>
#include "namespace.cpp"

using namespace std;

int main()
{
    float x;
    cout << "Ingrese un numero con decimales que desee partir ";
    cin >> x;
    
    
    cout << "La parte entera de " << x << " es " << my_namespace::parte_entera(x) << endl;
    cout << "La parte fraccionaria de " << x << " es " << my_namespace::parte_fraccionaria(x) << endl;
    
    return 0;
}