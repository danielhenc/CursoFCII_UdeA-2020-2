// Johan Carrillo - 1214734681
// Here it is defined functions of the class

#include "class.h"

Square::Square(){
	// The constructor receives the coeficients of the polynomial and end the program if a=0

	cout << "Este programa calcula las raices de un polinomio de la forma ax^2+bx+c\n";
	cout << "Inserte los coeficientes reales a, b y c en el respectivo orden" << endl;
	cin >> a >> b >> c;  // declared in class.h as private

	if( a==0 ){  // In case that a=0 the program breaks
		cout << " El primer coeficiente no puede ser cero" << endl;
		exit(0);
	}
}

void Square::show_complex(float real, float imaginary){
	// Show in screen both roots in the case they are complex numbers

	cout << "Las raices del polinomio son: \n";
	cout << setprecision(2) << real << " + " << setprecision(2) << imaginary << "i" << ", ";
	cout << setprecision(2) << real << " - " << setprecision(2) << imaginary << "i" << endl;
}

void Square::show_real(float sqrt1, float sqrt2){
	// Show in screen both roots in the case they are real numbers

	cout << "Las raices son: \n";
	cout << setprecision(2) << sqrt1 << ", ";
	cout << setprecision(2) << sqrt2 << endl;
}

void Square::calculate(){
	// Calculate the roots of the polynomial

	float discriminant = b*b - 4*a*c;  // discriminant of the polynomial
	float real, imaginary;  // Used in case the roots are complex
	float sqrt1, sqrt2;  // Used in case the roots are real

	if( discriminant<0 ){  // case complex roots
		imaginary = sqrt(-1 * discriminant) / float(2*a);  // imaginary part
		real = -1*b / float(2*a);  // real part

		show_complex(real, imaginary);  // show in screen the roots

	}
	else{  // case real roots
		sqrt1 = (-1*b + sqrt(discriminant)) / float(2*a);
		sqrt2 = (-1*b - sqrt(discriminant)) / float(2*a);

		show_real(sqrt1, sqrt2);
	}
}


