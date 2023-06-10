#include "Math.h"

bool Prime(int n)
{
    if(n == 3 || n == 2) return true;
    if(n <= 1 || n%3 == 0 || n%2 == 0) return false;
    double x = sqrt(n);
    for(int i = 5; i <= x; i += 6)
        if(n%i == 0 || n%(i + 2) == 0) return true;

    return false;
}

bool sprp(int n, int b)
{
    int d = n - 1;
    int s = 0;
    while(d%2 == 0){
        d /= 2;
        s++;
    }
    if((int)pow(b, d)%n == 1) return true;
    for(int r = 0; r < s; r++)
        if((int)pow(b, d*pow(2, r))%n == n - 1) return true;
    return false;
}

int * gen_sieve(int upper_bound)
{
    int S[] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
    int p = (int)ceil(sqrt(upper_bound));
    int * bools = calloc(upper_bound + 2, sizeof(int));
    int * primes = calloc(upper_bound + 2, sizeof(int));

    primes[0] = 4;
    primes[1] = 2;
    primes[2] = 3;
    primes[3] = 5;

    for(int x = 1; x <= p; x++){
        for(int y = 1; y <= p; y += 2){
            int m = 4*x*x + y*y;
            if(m > upper_bound) break;
            int q = m % 60;
            int s[] = {1, 13, 17, 29, 37, 41, 49, 53};
            for(int j = 0; j < 8; j++)
                if(q == s[j]) {bools[m] = !bools[m]; break;}   
        }
    }
    for(int x = 1; x <= p; x++){
        for(int y = 2; y <= p; y += 2){
            int m = 3*x*x + y*y;
            if(m > upper_bound) break;
            int q = m % 60;
            int s[] = {7, 19, 31, 43};
            for(int j = 0; j < 4; j++)
                if(q == s[j]) {bools[m] = !bools[m]; break;}
        }
    }
    for(int x = 2; x <= p; x++){
        for(int y = x - 1; y >= 1; y -= 2){
            int m = 3*x*x - y*y;
            if(m > upper_bound) break;
            int q = m % 60;
            int s[] = {11, 23, 47, 59};
            for(int j = 0; j < 4; j++)
                if(q == s[j]) {bools[m] = !bools[m]; break;}
        }
    }

    int * holes = calloc(upper_bound + 2, sizeof(int));
    int c = 0;
    for(int i = 0; i <= upper_bound; i += 60){
        for(int j = 0; j < 16; j++){
            holes[c] = i + S[j];
            c++;
        }
    }
    // holes[0] = c;
    for(int i = 1; i < c; i++){
        int sq = holes[i]*holes[i];
        if(sq > upper_bound) break;
        if(bools[i]){
            for(int r = 0; r < c; r++){
                int m = sq * r;
                if(m > upper_bound) break;
                bools[m] = 0;
            }
        }
    }
    for(int i = 7; i <= upper_bound; i++){
        if(bools[i]){
            primes[primes[0]] = i;
            primes[0]++;
        }
    }
    free(bools);
    free(holes);

    return primes;
}

int getprime(int n, int * sieve)
{
    int l = 1;
    int h = sieve[0];
    while(h > l){
        int m = (h + l) / 2;
        if(sieve[m] <= n && sieve[m + 1] > n) return sieve[m + 1];

        if(sieve[m] < n) l = m + 1;
        if(sieve[m] > n) h = m - 1;
    }
    return -1;
}