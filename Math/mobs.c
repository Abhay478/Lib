#include "Math.h"

int mobs(T x, int * sieve)
{
    if(!sieve){
        sieve = gen_sieve(x + 5);
    }
    if(x == 1) return 1;
    int c = 1;
    for(int i = 2; i <= x; i = getprime(i, sieve)){
        if(x%i == 0) c++;
        if(x%(i*i) == 0) return 0;
    }
    
    return (c%2 == 0) ? -1 : 1;
}

L inv_zeta(T x)
{
    double sum = 0;
    int * sieve = gen_sieve(1024);
    for(int i = 1; i < 1000; i++)
        sum += mobs(i, sieve)/pow(i, x);
    
    return 1/sum;

}

T * Divi(T x)
{
    T * out = (T *)malloc(sizeof(T));
    int c = 0;
    for(T i = 1; i <= x; i++)
        if(x%i == 0){
            out[c] = i;
            c++;
            out = (T *)realloc(out, (c+1)*sizeof(T));
        }
    return out;
}

L Lamb_W(L a)
{
    L sum = 0;
    if(fabsl(a) < 1/2.71828)
        for(int i = 1; i < 100; i++)
            sum -= Alt(i)*Tetr(i)*expG(a, i)/i;
    
    else
        for(int i = 1; i <= 1000; i++)
            sum -= (sum*exp(sum) - a)/((sum + 1)*exp(sum));
    
    return sum;

        
    
}

L Lamb_ser(int (*f)(T ), L q)
{
    L sum = 0;
    L quo = 1;
    for(int i = 1; i < 100; i++){
        quo = pow(q, i)/(1 - pow(q, i));
        sum += (*f)(i)*quo;
    }
    
    return sum;
}

J ceval(L * Coef, J val, int degree)
{
    if(degree == 0)
        degree = 1000;

    J out = 0;
    for(int i = 0; i <= degree; i++)
        out = Coef[i] + val*out;
    
    return out;
}

L eval(L * Coef, L val, int degree)
{

        //infinite sequence, evaluate first thousand terms.
    if(degree == 0)
        degree = 1000;
    
    L out = 0;
    for(int i = degree; i >= 0; i++)
        out = Coef[i] + val*out;
    
    return out;
}

J find_roots(L * Coef, int degree)
{
    volatile J i = rand();

    if(degree == 1) return Coef[0]/Coef[1];
    
    int count;
    while(1){
        i -= ceval(Coef, i, degree)/ceval(Diff(degree, Coef), i, degree != 0? degree - 1 : degree); 
        count++;
        if(cabs(ceval(Coef, i, degree)) < pow(10, -6)) return i;
        if(count > 1000){
            printf("Reevaluate.\n");
            return 0;
        }
    }
}
