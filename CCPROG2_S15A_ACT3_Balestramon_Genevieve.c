#include <stdio.h>
/*
    This function returns the integer with the maximum value in a given array.
*/
int
Maximum (int arrA[],
         int n)
{
    int i, min_temp = 0, max_temp = 0;
    for (i = 0; i < n; i++)
    {
        if (arrA[i] >= max_temp)
            max_temp = arrA[i];
        if (arrA[i] <= min_temp)
            min_temp = i;
    }
    printf("Index of minimum value : %d\n", min_temp);
    return max_temp;
}
/*
    This function returns the sum of all the prompted integers in a given array.
 */
int
Sum (int arrA[],
         int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += arrA[i];
    return sum;    
}
/*
    This function returns the mean of the data provided in the integer array.
*/
float
Average (int arrA[],
         int n)
{
    return (float)Sum(arrA, n)/n;
}
/*
    This function returns the number of positive integers present in the array.
*/
int
CountPositive (int arrA[],
         int n)
{
    int i, pos_counter = 0;
    for (i = 0; i < n; i++)
    {
        if (arrA[i] > 0)
            pos_counter++;
    }
    return pos_counter;    
}
/*
    This function returns the count of the odd numbers.
*/
int
CountOdd (int arrA[],
         int n)
{
    int i, odd_counter = 0;
    for (i = 0; i < n; i++)
    {
        if (arrA[i]%2 == 1 || arrA[i]%2 == -1)
            odd_counter++;
    }
    return odd_counter;    
}

int main (int argc, char **argv)
{    
    int arr_list[] = {10, 23, 11, 63, -55, 99, -20, 88};
    int arr_size = sizeof(arr_list)/sizeof(arr_list[0]);

    printf("Maximum value : %d\n", Maximum(arr_list, arr_size));
    printf("Sum of the integers : %d\n", Sum(arr_list, arr_size));
    printf("Average : %.3f\n", Average(arr_list, arr_size));
    printf("Number of postive integers : %d\n", CountPositive(arr_list, arr_size));
    printf("Number of odd integers : %d\n", CountOdd(arr_list, arr_size));
    return 0;
}