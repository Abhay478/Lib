
#include "Math.h"


J Join(Complex c)
{
    return c.real + c.imag*I;
}

Complex Split(J c)
{
    struct Complex_Number z;
    z.real = creal(c);
    z.imag = cimag(c);
    return z;
}

J Accept()
{
    Complex c;
    scanf("%lf %lf", &c.real, &c.imag);

    return Join(c);
}
