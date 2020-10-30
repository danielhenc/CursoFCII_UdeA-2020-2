/**
 *  Librería personal creada para los ejercicios
 *  7.5.5 y 7.5.6 del libro de Branson segunda edición
 */

#include <string>
#include <iostream>

namespace mylib
{
    /**
     * @brief Retorna la parte entera de un número
     * @param number    Número del que se extraera la parte entera
     * @return Parte entera de "number"
     */
    int entero(std::string number)
    {
        int ind = number.find('.'); //Buscar el punto decimal
        int ent; //parte entera

        if( ind != std::string::npos ) // Se encontró el punto decimal?
            ent = static_cast<int>(std::stod(number.substr(0,ind))); // conversión string->double->int
        else
            ent = static_cast<int>(std::stod(number)); // conversión string->double->int
        return ent;
    }

    /**
     * @brief Retorna la parte fraccionaria de un número
     * @param number    Número al cúal se le sacará la parte fraccionaria
     * @return
     */
    double partefrac(std::string number)
    {
        int ent = entero(number); //parte entera
        double frac = std::stod(number) - ent;
        return frac;
    }
}
