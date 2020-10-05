//trapezoidalMethod.cpp

#include <iostream>
#include "trapezoidalMethod.h"


trapezoidalMethod::trapezoidalMethod(int n){
	// class constructor, initialize the partition of the interval
	N = n;
}

void trapezoidalMethod::setFunction(double (*function)(double), double a, double b){
	// function setter
	functionTointegrate = function;
	changeLimits(a, b);
}

void trapezoidalMethod::update_stepSize(void){
	// trapezoid's size setter
	h = (supLim - infLim) / N;
}

void trapezoidalMethod::changeLimits(double a, double b){
	// integration limits setter
	infLim = a;
	supLim = b;
	update_stepSize();	
}

double trapezoidalMethod::runIntegration(){
	// function helper to integrate from the inferior limit defined by the user 
	return Integrate(infLim);
}

double trapezoidalMethod::Integrate(double x ){
	// function that sum iteratively the area of the N trapezoids in the interval
	if(x < supLim)
		return trapezoidalArea(x, x + h, functionTointegrate) + Integrate( x + h);
	else
		return 0;
}

double trapezoidalMethod::trapezoidalArea(double a, double b, double (*f)(double)){
	// function to calculate the area of each trapezoid
	return 0.5 * (b - a) * ( (*f)(a) + (*f)(b));
}