/* Name : Genevieve S. Balestramon
 * Section : S15A
 *
 * Activity 4 (Selection Sort version 2)
 * CC PROG2 Term 2
*/ 
#include <stdio.h>
#define SIZE 5

void
print_array (int arr[],
              int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
void
Copy (int destination[],
      int source[],
      int n)
{
  int i;
  
  for (i = 0; i < n; i++)
    destination[i] = source[i];
}
void 
VectorAdd(int A[],
          int B[],
          int C[],
          int n)
{
  int i;

  for (i = 0; i < n; i++)
    C[i] = A[i] + B[i];
}
int main(int argc, char **argv)
{
  int A[SIZE] = {10, 20, 30, 40, 50};
  int B[SIZE];
  int C[SIZE] = {10, 20, 30, 40, 50};
  int D[SIZE] = {20, 25, 2, 100, 90};
  int E[SIZE];

  Copy (B, A, SIZE);
  print_array(A, SIZE);

  VectorAdd (C, D, E, SIZE);
  print_array(E, SIZE);

  return 0;
}