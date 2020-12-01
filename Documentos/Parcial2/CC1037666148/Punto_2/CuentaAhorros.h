#ifndef CUENTA_A
#define CUENTA_A

#include <iostream>
#include "Cuenta.h"

class CuentaAhorros : public Cuenta
{
 public:
  CuentaAhorros(const double, const double);
  double calcularInteres(void) ;
 private:
  double tasa_interes;
  void Set_tasa(const double);
};

#endif
