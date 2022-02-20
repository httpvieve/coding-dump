#include<stdio.h>
#include<math.h>
#define NUM_MAX 2000001

int main()
{
        long long a = 0, b = 0, sum = 0;
        static int primes[NUM_MAX];
        for (a =  0; a <= NUM_MAX; a++) {
                primes[a] = 1;
        }
        for (a = 2; a <= sqrt(NUM_MAX); a++) {
                if (primes[a] == 1){
                        for(b = a; a*b <= NUM_MAX; b++){
                                primes[a * b] = 0;
                        }
                }
        }
        for (a = 2; a <= NUM_MAX; a++){
                if (primes[a] == 1){
                        sum += a;
                }
        }
        printf("%lld", sum);
        return 0;
}