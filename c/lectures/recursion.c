#include <stdio.h>

int nthFiboTerm (int n)
{
        if (n == 0)
                return 0;
        else if (n == 1)
                return 1;
        else
                return nthFiboTerm(n - 1) + nthFiboTerm(n - 2);
}
int main (int argc, char *argv[])
{
        int n;
        n = 9;
        printf ("%d term: %d", n, nthFiboTerm(n));
return 0;
}