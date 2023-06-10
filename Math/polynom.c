#include "Math.h"

L * Diff(int degree, L * coef)
{
    L * out = (L *)calloc(degree, sizeof(double));
    for(int i = 0; i < degree; i++)
        out[i] = coef[i + 1] * (i + 1);
    
    return out;
}

L * Teg(int degree, L * coef, L teg_cons)
{
    L * out = (L *)calloc(degree + 2, sizeof(int));
    out[0] = teg_cons;
    for(int i = 1; i < degree + 2; i++)
        out[i] = coef[i - 1]/i;
    
    return out;
}
