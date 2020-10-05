class second_order_equation_solver
{
public:

    second_order_equation_solver(float, float, float);
    void set_coefficients(float, float, float);
    void display_roots();
    void calculate_roots();
    
private:

    float A;
    float B;
    float C;
    std::tuple <float,float> R1;
    std::tuple <float,float> R2;

};