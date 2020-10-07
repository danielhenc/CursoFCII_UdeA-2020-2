#include <iostream>

class QuadPoly{
    public:
        QuadPoly(float, float, float);
        void calculate_Roots(); // function to calculate roots
        void print_equation(); // function to display the symbolic polynomial
        float Roots[2][2]; // roots of the form [ [Re(x+), Im(x+)], 
                           //                     [Re(x-), Im(x-)] ]

    private:
        float discriminant(); // function to calculate the polynomial discriminant

        // polynomial coefficients 
        // --> a2*x^2 + a1*x + a0
        float a0 = 0; 
        float a1 = 0;
        float a2 = 0;
};