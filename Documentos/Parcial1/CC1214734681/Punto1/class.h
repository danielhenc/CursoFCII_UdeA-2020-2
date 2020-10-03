// Johan Carrillo - 1214734681
// Here it is declared the class and included the libraries that
// the code needs to work

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


class Square{
public:
	Square();  // constructor that receives the coeficients of the polinomial
	void calculate();  // calculates the roots of the polynomial

private:
	float a, b, c;  // Coeficients of the polynomial

	void show_complex(float, float);  // show in screen the two roots if are complex
	void show_real(float, float);  // show in screen the two roots if are real
};