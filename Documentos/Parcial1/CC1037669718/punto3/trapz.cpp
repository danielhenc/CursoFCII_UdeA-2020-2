#include<iostream>
#include<cmath>

using namespace std;

double trapz(double y[], double x[], int N){
  // N debe coincidir con el tamaño de los arreglos y[] y x[]
  double s = 0;
  
  for( int i = 1; i < N; i++ ){
    s += 0.5 * ( y[i] + y[i-1] ) * ( x[i] - x[i-1] ); // Suma el área de cada trapezoide
  }

  return s;
}

int main(){

  cout << "Para comprobar el funcionamiento, integramos la campana gaussiana y verificamos que se coincida con el valor teórico\n";

  int N = 10000; // Número de puntos para la integración
  double x[N] = {}, y[N] = {}; // Puntos
  double a = -5, b = 5, delta_x; // Puntos iniciales y finales para la integración

  delta_x = (b - a)/N; // Paso en x
  
  for( int i = 0; i < N ; i++ ){ // Generamos los puntos de la función
    x[i] = a + i * delta_x;
    y[i] = exp(-x[i]*x[i]);
  }

  if ( abs( sqrt( M_PI ) - trapz( y , x , N ) ) < 1e-10){ // Verificamos que la integral sí de raíz de pi
    cout << "¡La integral numérica coincide con su valor teórico hasta, como mínimo, 10 cifras significativas!\n";
  }
  
  return 0;
}
