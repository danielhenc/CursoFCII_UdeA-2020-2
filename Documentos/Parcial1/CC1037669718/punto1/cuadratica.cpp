#include<iostream>
#include<iomanip>
#include<complex>

using namespace std;

class ecuacionCuadratica{
 public:
  
  complex<double> x[2] = {}; // Soluciones a la ecuación
  
  // Inicialización de la función
  ecuacionCuadratica( complex<double> A, complex<double> B, complex<double> C ){
    setConstantes(A, B, C);
  };
  
  // Función para definir las constantes
  void setConstantes( complex<double> A, complex<double> B, complex<double> C ){
    a = A;
    b = B;
    c = C;
    solve();
  };

  // Función para mostrar las constantes y las soluciones
  void imprimir(){
    cout << "Las constantes son a=" << a << ", b=" << b << ", c=" << c << "\n";
    cout << "Las soluciones son " << fixed << setprecision(2) << x[0] << " y " << fixed << setprecision(2) << x[1] << "\n";
  }
  
 private:
  complex<double> a, b, c; // Constantes de la ecuación

  // Función que halla las soluciones
  void solve(){ 
    x[0] = (-b+sqrt( b*b - 4.0*a*c ))/(2.0*a);
    x[1] = (-b-sqrt( b*b - 4.0*a*c ))/(2.0*a);
  };
};

int main(){

  complex<double> a, b, c;

  cout << "Este programa soluciona ecuaciones cuadráticas con constantes complejas.\nIntroduzca la constante a como \"(real,imaginaria)\"\n";
  cin >> a;
  cout << "Introduzca la constante b como \"(real,imaginaria)\"\n";
  cin >> b;
  cout << "Introduzca la constante c como \"(real,imaginaria)\"\n";
  cin >> c;
  cout << "\n";

  ecuacionCuadratica miEcuacion(a, b, c);

  miEcuacion.imprimir();
  
  return 0;
}
