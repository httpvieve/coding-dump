#include <stdio.h>
#define ARR_SIZE 8
int 
getMinValue(int arr[], 
            int arr_size)
{
    int i, temp = 0;
    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] <= temp)
            temp = arr[i];
    }
    return temp;
}
int 
getMaxValue(int arr[], 
            int arr_size)
{
    int i, temp = 0;
    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] >= temp)
            temp = arr[i];
    }
    return temp;
}
int 
posNumCounter (int arr[], 
               int arr_size)
{
    int i, counter = 0;
    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
            counter++;
    }
    return counter;
}
int 
negNumCounter (int arr[], 
               int arr_size)
{
    int i, counter = 0;
    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] < 0)
            counter++;
    }
    return counter;
}
int 
getSum (int arr[], 
        int arr_size)
{
    int i, nSum = 0;
    for (i = 0; i < arr_size; i++)
        nSum += arr[i];
    return nSum;
}
int main(int argc, char **argv)
{
    int arrSort[ARR_SIZE] = {10, 23, 11, 63, -55, 99, -20, 88};
    printf("Minimum value of array is %d\n", getMinValue(arrSort, ARR_SIZE));
    printf("Maximum value of array is %d\n", getMaxValue(arrSort, ARR_SIZE));
    printf("Number of postive intergers is %d\n", posNumCounter(arrSort, ARR_SIZE));
    printf("Number of negative intergers is %d\n", negNumCounter(arrSort, ARR_SIZE));
    printf("Sum of the integers in array is %d\n", getSum(arrSort, ARR_SIZE));

    return 0;
}