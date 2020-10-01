#include <iostream>
#include <iomanip>

#include "cuadratica.h"



int main(){
  float var_a, var_b, var_c;
  
  cout<< "ingrese numero que acompaña a x^2 (a): "<< endl;
  cin>>var_a;
  
  cout<< "ingrese numero que acompaña a x (b): "<< endl;
  cin>>var_b;
  
  cout<< "ingrese numero constante (c): "<< endl;
  cin>>var_c;

  cuadratica raices(var_a,var_b,var_c);
  raices.imprimirResultado();


  return 0;

}
