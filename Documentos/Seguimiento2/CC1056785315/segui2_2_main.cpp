#include "segui2_2_namespace.cpp"

using namespace Parte_entera_y_decimal;

int main()
{
  int entera;
  double fracc;
  
  cout << "Ingrese un numero (use un punto para distinguir la parte decimal): ";

  // Llamado de funciones del namespace
  entera = entero();
  fracc = partefracc();
  
  cout << "\nLa parte entera de su numero es " << entera << endl;
  cout << "La parte decimal de su numero es " << fracc << endl;
  
  return 0;
}
