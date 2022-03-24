#include <stdio.h>

int main()
{
    int A[5];
    int i;

    for (i = 0; i < 5; i++)
        A[i] = 0;

    for (i = 0; i < 5; i++){
        printf("Value of [%d] is %d", i, A[i]);
        printf("\n");
    }
    return 0;
}