#include <iostream>
#include <cstring> 

using namespace std;

int main()
{
  char *cadena1 = "abcdefghijklmnopqrstuvwxyz";
  char *cadena2 = "cuatro";
  char *cadena3 = "Boston"; // Pero boston perdio con miami, que triste ;(

  cout << "La longitud de\"" << cadena1 << "\" es " << strlen( cadena1 )
       << "\nLa longitud de\"" << cadena2 << "\" es " << strlen( cadena2 )
       << "\nLa longitud de\"" << cadena3 << "\" es " << strlen( cadena3 )
       << endl;
  
 return 0; 
}
