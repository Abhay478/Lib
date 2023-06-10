#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

#define LIM 256
#define TLIM 4096
#define K unsigned int //in bit fields only.
#define L long double
#define T unsigned long long int 
#define J double complex
struct Complex_Number {
    double real, imag;
};

typedef struct Complex_Number Complex;

L Poch(L q, int n);

#define Fact(n) (T)Poch(1.0, n)
#define lFact(n) (L)Poch(1.0, n)
#define P(n, r) Fact(n)/Fact(n - r)
#define C(n, r) P(n, r)/Fact(r)
#define rC(n, r) C(n + r - 1, r)
#define Alt(n) pow(-1, n)
#define Tetr(n) pow(n, n)
#define expG(a, n) pow(a, n)/lFact(n)

bool sprp(int n, int b);

#define fast_prime(n) ((n) == 3 || (sprp(n, 2) && sprp(n, 7) && sprp(n, 61))) ? (true) : (false)

L * Diff(int degree, L * coef);
int * gen_sieve(int upper_bound);
int getprime(int n, int * sieve);