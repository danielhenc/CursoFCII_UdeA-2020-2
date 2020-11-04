#include <fstream>
#include <string>
#include <iostream>
using namespace std;


void leerBytes(fstream& file,long a,int n, string *text)
{
    
    char ch;
    // Texto aleatorio generado con: http://www.randomtext.me/
    file.open("randomtext.txt"); 
    /*
    El ciclo va desde la posicion que se quiere empezar del archivo 
    y para lograr n iteracion, el valor maximo es de a + n
    */
    for( long offset = a; offset < a+n ; offset++)
    {
        // Posicion la lectura en offset leyendola desde el principio (ios::beg)
        file.seekg(offset,ios::beg);
        // Guarda el caracter en ch
        ch = file.get();
        text -> push_back(ch);        
    }

    cout << endl;
    
    file.close();
}


int main()
{
    long a = 1;
    int n = 10;
    fstream file;
    string text = "";
    
    cout << "Posicion del primer char: " ;
    cin >> a;
    cout << "Longitud deseada del texto: " ;
    cin >> n;

    // Pasa como parámetro adicional el lugar de memoria de text
    leerBytes(file,a,n,&text); 
    
    cout << "Texto: " << text << endl;
    
    return 0;
}