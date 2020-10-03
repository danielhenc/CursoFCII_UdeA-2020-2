#include <string>

class Dado
{
 public:
  
  Dado(std::string);
  /*Constructor. El argumento de tipo string es para nombrar el dado. Este nombre
    se usará para imprimir mensajes referentes al dado.*/
  
  void lanzarDado(bool);
  /*Método que le pide al usuario que lance el dado, por medio de ingresar por
    teclado el carácter l. Este método aumenta en 1 la variable tiradas, le
    le asigna un número aleatorio entre 1 y 6 a la variable ultimoResultado e
    imprime en consola un dibujo del dado con el último resultado si el argumento
    del método es true o solo imprime el resultado como un dígito si el argumento
    es false.*/
  
  int obtenerUltimoResultado();
  /*Método que sirve para recuperar el último resultado de haber tirado el dado.
    Si el dado no ha sido lanzado aún, el método retorna 0.*/
  
 private:
  
  void mostrarDado(int);
  /*Método que imprime en consola un dibujo de un dado con el valor que se le
    pase como argumento. Obviamente los posibles valores del argumentos son 1, 2,
    3, 4, 5 y 6.*/
  
  std::string nombreDado;
  
  int lados;
  
  int tiradas;
  
  int ultimoResultado;
};
