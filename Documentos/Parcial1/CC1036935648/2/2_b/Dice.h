

class Dice
{
public:
    Dice();

    /**
     * Retorna un número aleatorio entre 1 y 6
     */
    int Throw();
private:

    /**
     * Variable para indicar si la semilla de los números 
     * aleatorios ya fue inicializada
     */
    static bool isSeedInitiliced;
};
