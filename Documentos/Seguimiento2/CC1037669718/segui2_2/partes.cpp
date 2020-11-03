
namespace partes{
  int entero( double x ){
    int s;
    s = x; // al asignar un double a un int se obtiene la parte entera
    return s;
  }
  
  double partefracc( double x ){
    double r;
    r = x - entero(x);
    return r;
  }
}
