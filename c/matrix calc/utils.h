#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ENTRY_PRINT(x) if (x < 10) printf ("[  %f ]", x); \
                        else if (x > 9) printf ("[ %f ]", x);\

#define MAX 30
typedef struct Matrix {
        int rows;
        int columns;
        float data[MAX][MAX]; 
} matrixData;


#endif