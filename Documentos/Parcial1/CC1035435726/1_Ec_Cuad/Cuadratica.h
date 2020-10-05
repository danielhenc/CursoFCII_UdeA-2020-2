#include <iostream>

using namespace std;

class Cuadratica{

//establecemos todos los metodos como publicos
public:
    Cuadratica(double, double, double); //El constructor
    void seta(double);//establecer primer coeficiente a
    double geta();//retornar el cofieciente si el usuario lo desa
    void setb(double);//establecer segundo coeficiente b
    double getb();
    void setc(double);//establecer tercer coeficiente b
    double getc();    
    void getRoots();//prototipo funcion que obtendra raices
//Las variables se establecen privadas
private:
    double a, b, c;
    
};

