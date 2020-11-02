//Ejercicio 5
/* a. Escriba una función de C++, entero(), que devuelve la parte entera de cual-
quier número transmitido a la función. (Sugerencia: Asigne el argumento trans-
mitido a una variable de número entero.)
b. Incluya la función escrita en el ejercicio 5a en un programa que funcione. Ase-
gúrese que su función es llamada desde main() y devuelve en forma correcta
un valor a main(). Haga que main() use una instrucción cout para desple-
gar el valor devuelto. Pruebe la función transmitiéndole varios datos.
c. Cuando esté seguro que la función entero() escrita para el ejercicio 5a fun-
ciona en forma correcta, guárdela en un espacio de nombres y en una bibliote-
ca personal de su elección. */

/* 6. a. Escriba una función de C++, partefracc(), que devuelva la parte fracciona-
ria de cualquier número transmitido a la función. Por ejemplo, si se transmite
el número 256.879 a partefracc(), deberá devolverse el número .879. Ha-
ga que la función partefracc() llame a la función entero() que escribió
en el ejercicio 5a. El número devuelto puede determinarse entonces como el nú-
mero transmitido a partefracc() menos el valor devuelto cuando el mismo
argumento es transmitido a entero().
b. Incluya la función escrita en el ejercicio 6a en un programa que funcione. Ase-
gúrese que la función es llamada desde main() y devuelve en forma correcta
un valor a main(). Haga que main() use una instrucción cout para desple-
gar el valor devuelto. Pruebe la función transmitiéndole varios datos.
c. Cuando esté seguro que la función partefracc() escrita para el ejercicio 6a
funciona en forma correcta, guárdela en el mismo espacio de nombres y biblio-
teca personal seleccionados para el ejercicio 5c. */


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
namespace partes{

int entero( double ); //Definición de la función entero con un double osea cualquier hijueputa número
float partefracc( double ); //Definicción de la función partefrac. Esta si tiene que devolver un float.

int entero( double x){
	int pint = 0;
	pint = x; 
	return pint;
			}

float partefracc( double x){
	float pint = 0.0;
	float pfrac = 0.0;
	pint = entero( x );
	pfrac = abs( pint - x);
	return pfrac;

			    }
		}
