
#include "Math.h"

L Poch(L q, int n)
{
    L res = 1.0;
    for(L i = q + n - 1; i >= q; i--)
        res *= i;
    
    return res;
}

T doubleFact(int n)
{
    if(n%2) return Fact(n)/(T)(pow(2, n/2)*Fact(n/2));
    else return Fact(n/2)*(T)pow(2, n/2);
}
            
T rP(int n, int r, int * d)
{
    int l = d[0];
    T per = P(n, r);
    
    for(int i = 1; i < l; i++)
        per /= Fact(d[i]);
    
    return per;
}        

L hyp(L z, int n_up, int n_down, ...)
{
    va_list p_arg;
    va_start(p_arg, n_down);

    double top[n_up];
    double bottom[n_down];

    for(int i = 0; i < n_up; i++)
        top[i] = va_arg(p_arg, double);
    
    for(int i = 0; i < n_down; i++)
        bottom[i] = va_arg(p_arg, double);

    va_end(p_arg);
    
    L out = 0;
    L quo;
    L prev = 1;

    for(int n = 0; fabsl(prev - out) > pow(10, -8); n++){
        quo = 1/lFact(n);
        for(int i = 0; i < fmax(n_up, n_down); i++)
            quo *= ((i<n_up)? Poch(top[i], n) : 1) / ((i<n_down) ? Poch(bottom[i], n) : 1);
        
        prev = out;
        out += quo*pow(z, n);
    }
    return out;
}
