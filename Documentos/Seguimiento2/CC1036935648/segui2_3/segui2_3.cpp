/*
 * @brief Ejercicio 6 de la sección 8.4 del libro de Branson 2da edición
 * @author Andrés Santiago Duque
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * @brief Imprime un número de bytes encontrados en un archivo
 *        desde una posición inicial.
 * @param f  Archivo a leer
 * @param offset  Posición del primer byte
 * @param n  Número de bytes a leer
 */
void leerBytes(ifstream& f, long offset, int n);

/**
 * @brief Guarda un numero de bytes leidos desde un archivo
          a partir de una posición inicial en un string.
 * @param f  Archivo a leer
 * @param offset  Posición del primer byte
 * @param n    Número de bytes a leer
 * @param str  String donde se almacenarán los caracteres.
 */
void leerBytes(ifstream& f, long offset, int n, string& str);

int main()
{  
    ifstream f("test.dat");
    
    if (f.fail()) // comprueba la apertura con exito
    {
        cout << "\nEl archivo no se abrió con éxito."
             << "\n Por favor compruebe que el archivo existe en realidad."
             << endl;
        exit(1);
    }

    cout << "=========================================" << endl
         << "               Numeral a)                " << endl
         << "=========================================" << endl
         << endl;

    /* prueba de la función */
    for(int i=0; i<10; i++)
    {
        cout << "offset: " << i << "\tnumber of bytes: " << i + 2 << endl;
        leerBytes(f,i,i+2);
    }


    cout << endl
         << "=========================================" << endl
         << "               Numeral b)                " << endl
         << "=========================================" << endl
         << endl;

    string str;

    /* prueba de la función */
    for(int i=0; i<10; i++)
    {
        cout << "offset: " << i << "\tnumber of bytes: " << i + 2 << endl;
        leerBytes(f,i,i+2, str);
        cout << str << endl;
    }
    
    return 0;
}

void leerBytes(ifstream& f, long offset, int n)
{
    /* Calcular la posición del último carácter en el archivo */
    f.seekg(0, ios::end);
    long lastChar = f.tellg();

    if(offset <= lastChar)
    {
        f.seekg(offset, ios::beg);

        /* Asegurar que existen todos los bytes que se van a leer*/
        if(lastChar < offset + n)
            n = lastChar - offset;

        char c;
        for(int i=0; i<n; ++i)
        {
            f.get(c);
            cout << c;
        }
        cout << endl;
    }
}

void leerBytes(ifstream& f, long offset, int n, string& str)
{
    str.clear(); //limpiar la cadena

    /* Calcular la posición del último carácter en el archivo */
    f.seekg(0, ios::end);
    long lastChar = f.tellg();

    if(offset <= lastChar)
    {
        f.seekg(offset, ios::beg);

        /* Asegurar que existen todos los bytes que se van a leer*/
        if(lastChar < offset + n)
            n = lastChar - offset;

        char c;
        for(int i=0; i<n; ++i)
        {
            f.get(c);
            str.push_back(c);
        }
    }
}
