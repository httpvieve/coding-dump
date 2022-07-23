#include <stdio.h>

int main()
{
    char cCourseCode[7] = {'C', 'C', 'P', 'R', 'O', 'G', '2'};
    int A[5];
    int i;

    // note : for loop is often used together with arrays  
    for (i = 0; i < 7; i++)
        printf("%c", cCourseCode[i]);
    printf("\n");
    // initialize elements of array A
    A[0] = 3;
    A[1] = -5;
    A[2] = 1000;
    A[3] = 123;
    A[4] = 47;
    for (i = 0; i < 5; i++){
        printf("Value of [%d] is %d", i, A[i]);
        printf("\n");
    }
    return 0;
}