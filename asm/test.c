#include <stdio.h>

extern long long int sum (long long int param1, long long int param2, long long int* param3);

int main () 
{
        long long int param1, param2, param3, answer;
        
        param1 = 512;
        param2 = 1024;
        param3 = 5;

        answer = sum (param1, param2, &param3);
        printf (" %lld + %lld = %lld \n", param1, param2, answer);
        printf (" new PARAMETER 3 value is %lld", param3);

        return 0;
}