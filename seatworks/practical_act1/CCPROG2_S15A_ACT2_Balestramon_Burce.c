// Genevieve Salalima Balestramon
// Vincent Maximus M. Burce 

#include <stdio.h>
#define ARR_SIZE 5

int 
activity2()
{
    int i, arrA[5];
    for (i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &arrA[i]);
    }
    for (i = 0; i < ARR_SIZE; i++)
    {
        printf("Value of [%d] is %d", i, arrA[i]);
        printf("\n");
    }
    for (i = 0; i < ARR_SIZE; i++)
    {
        printf("Address of arrA[%d] is %p", i, &arrA[i]);
        printf("\n");
    }
}

int 
main()
{
    activity2();
        
    return 0;
}

// QUESTIONS
// a. int
// b. pointer
// c. array (int) 
// d. 5