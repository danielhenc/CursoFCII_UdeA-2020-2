#include "trapezoidalrule.h"
#include <cmath>

TrapezoidalRule::TrapezoidalRule(Function *f, unsigned int k)
{
    setIterNumb(k);
    setFuction(f);
}

void TrapezoidalRule::setFuction(Function *f)
{
    func = f;
}

void TrapezoidalRule::setIterNumb(unsigned int k)
{
    this->k = k;
}

float TrapezoidalRule::integrate(float init, float end)
{
    float tk=0;
    this->init = init;
    this->end = end;

    /* Aproximaciones sucesivas al valor de la integral*/
    for(unsigned int n=0; n<=k ; ++n )
        tk = TK(n, tk);

    return tk; //valor de la integral
}

float TrapezoidalRule::TK(unsigned int k, float T_k_1)
{
    float dx = (end - init)/pow(2,k); //Ancho del trapecio
    float s = 0;
    if(k==0)
        return 0.5*(func->eval(end) - func->eval(end - init))*(end-init); //T_0

    for(int i=1; i<pow(2,k); i+=2)
        s += func->eval(init + i*dx);

    return 0.5*T_k_1 + dx*s;
}




