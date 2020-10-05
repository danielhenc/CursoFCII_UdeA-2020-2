#include <iostream>
#include <cmath>
#include "quadPoly.h"

using std::cout;
using std::endl;


QuadPoly::QuadPoly(float a, float b, float c){
    // This class constructor sets the polynomial coefficients
    a2 = a;
    a1 = b;
    a0 = c;
}   

float QuadPoly::discriminant(){
    // This function calculate discrimiant of the polynomial 
    // --> (b^2-4ac)
    return a1 * a1 - 4* a2 * a0;  
}

void QuadPoly::calculate_Roots(){
    // This function calculate the roots with
    // x = term1 +- term2
 
    float term1 = a1 / ( -2.0 * a2);
    float term2 = 0;
    float delta = discriminant();

    // if the discriminant is < 0, the Imaginary part of the solution appear 
    if(delta <= 0) 
        term2 = sqrt(-1 * delta) / (2.0 * a2);
    else
        term1 += sqrt(delta) / (2.0 * a2);

    Roots[0][0] = term1 ;
    Roots[0][1] = term2 ;
    Roots[1][0] = term1;
    Roots[1][1] = -1.0 * term2;
}

void QuadPoly::print_equation(){
    // This method only show in terminal the symbolic form of the polynomial
    cout << "(" << a2 << ")" << "x^2 + " << "(" << a1 << ")" << "x + " << "(" << a0 <<")"; 
}