

#ifndef CUENTA_H
#define CUENTA_H


class Cuenta
{
public:

    /**
     * Recibe el saldo inicial
     */
    Cuenta(double saldo=0);

    /**
     * @brief Suma un valor al saldo
     * @return saldo actual
     */
    double abonar(double);

    /**
     * @brief Retira un valor al saldo, siempre y cuando, el saldo
     *        no quede con un valor negativo
     * @return saldo actual. 
     */
    double cargar(double);

    /**
     * Retorna el saldo actual
     */
    double getSaldo();

protected:
    double saldo;

};


class CuentaAhorros : public Cuenta
{
public:

    /**
     * @param saldo  Saldo inicial
     * @param interes Tasa de interes inicial
     */
    CuentaAhorros(double saldo, double interes);

    /**
     * Retorna el interes sobre el saldo actual
     */
    double calcularInteres();

    /**
     * Modifica la tasa de interes actual
     */
    void setInteres(double);

private:

    double interes; //tasa de interés

};

class CuentaCheques : public Cuenta
{

public:
    
    /**
     * @param saldo  Saldo inicial
     * @param cuota  Cuota por transacción
     */
    CuentaCheques(double saldo, double cuota);

    /**
     * @brief Suma un valor al saldo
     * @return saldo actual
     */
    double abonar(double);

    /**
     * @brief Retira un valor al saldo, siempre y cuando, el saldo
     *        no quede con un valor negativo
     * @return saldo actual. 
     */
    double cargar(double);

private:

    double cuota; //Cuota por transacción
};

#endif // CUENTA_H
