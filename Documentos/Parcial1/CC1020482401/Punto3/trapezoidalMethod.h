//trapezoidalMethod.h

#include <iostream>

class trapezoidalMethod{
    // This class contains and applies the necessary methods
    // to integrate a function using the trapezoidal method 
    public:
    	trapezoidalMethod(int);
    	void setFunction(double (*)(double), double, double);
        void changeLimits(double, double);
        double runIntegration();

    private:
        double Integrate(double);
        double trapezoidalArea(double , double , double (*)(double));
        void update_stepSize(void);	

        double (*functionTointegrate)(double);
        // intrgrations limits
        double infLim = 0.0;
        double supLim = 1.0;
        // variable for interval partition
        double N;
        double h;
};