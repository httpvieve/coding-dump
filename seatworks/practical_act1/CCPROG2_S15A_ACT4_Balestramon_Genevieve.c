
/* Name : Genevieve S. Balestramon
 * Section : S15A
 *
 * Activity 4 (Selection Sort version 2)
 * CC PROG2 Term 2
*/ 
#include <stdio.h>

#define ARR_SIZE 8

void
Swap(int *min_temp,
     int value)
{
  *min_temp = value; 
}

void
SelectionSort2(int A[],
              int n)
{

  int i, j, min, temp;

  for (i = 0; i < n-1; i++)
  {
    min = i;

    for (j = i + 1; j < n; j++)
    {
      if (A[min] > A[j])
        Swap(&min, j);
    }

    if (!(i == min))
    {
      Swap(&temp, A[i]);
      Swap(&A[i], A[min]);
      Swap(&A[min], temp);
    }
  }
}
int main()
{
  int i, arr[ARR_SIZE] = {10, 23, 11, 63, 55, 99, 20, 88};
  SelectionSort2(arr, ARR_SIZE);
  for (i = 0; i < ARR_SIZE; i++)
    printf("%d\n", arr[i]);
  return 0;
}
