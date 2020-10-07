#ifndef TRAPEZOIDALRULE_H
#define TRAPEZOIDALRULE_H



/**
 * @brief Interfaz para usar la clase de integración
 *        numérica con una función genérica.
 */
class Function
{
public:
    /**
     * @brief Evalua la función en x
     * @param x   Valor donde se evalará la función.
     * @return La función evaluada en x
     * @warning Esta función debe ser implementada por
     *          una clase derivada.
     */
    virtual float eval(float x) =0;
};



/**
 * @brief Clase que realiza integración numérica por medio de
 *        la regla del trapezoide
 *
 */
class TrapezoidalRule
{
public:

    TrapezoidalRule(Function *f=0, unsigned int k=4);

    /**
     * @brief seleccionar la función a integrar
     * @param f  Función (objeto de la clase Function) que se va a integrar
     */
    void setFuction(Function *f);

    /**
     * @brief Establece el número de iteraciones
     * @param k Numero de iteraciones
     */
    void setIterNumb(unsigned int k);

    /**
     * Integrar la función entre (init, end)
     * @param init  Punto inicial
     * @param end   Punto final
     * @note    Este método se basa en el algoritmo descrito en la
     *          sección 14.6 del libro de Bronson "C++ para ingeniería
     *          y ciencias" segunda edición.
     */
    float integrate(float init, float end);

private:

    unsigned int k; //Número de iteraciones que se van a realizar
    float init,end; //limites de integración
    Function *func;

    /**
     * @brief Calcula los términos T_k
     * @param k
     * @param T_k_1  Término T_{k-}
     * @return
     */
    float TK(unsigned int k, float T_k_1);
};

#endif // TRAPEZOIDALRULE_H
