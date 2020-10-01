class Cuadratica
{
 public:
  
  Cuadratica(double, double, double);//Constructor
  
  void imprimirEcuacion();//ax² + bx + c = 0
  
  double obtenerDiscriminante();//Método que retorna la variable discriminante
  
  void obtenerRaiz(double [2][2]);//Pone las raices en el argumento dado
  
  void imprimirRaices();//Imprime las raices con dos cifras decimales
  
 private:
  
  double a, b, c;//Coeficientes de la ecucación cuadrática
  
  double discriminante;//discriminante = b² - 4*a*c
  
  double raiz[2][2];
  /*
    Las raices se guardan en el arreglo 2-dimensional raiz de la siguiente forma:
    raiz = {{Re(raiz0),Im(raiz0)},
            {Re(raiz1),Im(raiz1)}}
   */
};
