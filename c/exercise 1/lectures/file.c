#include <stdio.h>
#define ARR_SIZE 10
int main()
{
    int arr_list[ARR_SIZE];
    int arr_temp;
    FILE *nFile;
    if ((nFile = fopen("file.txt", "r")) == NULL)
    {
        printf("File does not exist!\n");
    }
    else 
    {
        fscanf(nFile, "%d", &arr_temp);
        for (int i = 0; i < ARR_SIZE ; i++)
            fscanf(nFile, "%d", &arr_list[i]);
    }
    printf("%s", arr_list[2]);
    return 0;
}