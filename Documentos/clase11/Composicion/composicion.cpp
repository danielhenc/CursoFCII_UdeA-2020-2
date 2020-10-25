#include <iostream>
#include "empleado.h" // definición de la clase Empleado

using namespace std;

int main()
{
Fecha nacimiento( 3, 4, 1989 );
Fecha contratacion( 3, 12, 2018 );
Empleado gerente( "Marce", "Sanchez", nacimiento, contratacion );
cout << endl;
gerente.imprimir();
 
cout << "\nPrueba del constructor de Fecha con valores inválidos:\n";
Fecha ultimoDiaDescanso( 15, 35, 1995 ); // mes y dia inválidos
cout << endl;
return 0;
}
