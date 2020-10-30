// Johan Carrillo - 1214734681
// This is the personal library for the main function in "main.cpp" program
#include <iostream>

using namespace std;


namespace number_library{  // namespace

	// Definition of the functions
	int integer_part(double number){
		// this function shows the integer part of the number

		return number;
	}

	double frac_part(double number){
		// this function shows the fractional part of the number

		return number - integer_part(number);
	}
}