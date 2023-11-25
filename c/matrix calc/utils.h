#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define TRUE 1 
#define FALSE 0

#define MAX 50

#define INVALID -1
#define VALID 1

#define RED "\033[1;31m"
#define PURPLE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#define EXIT_PROGRAM "[0]\tExit" 
#define RETURN "[0] Return to main menu"

#define BORDER for (int i = 0; i < 40; i++) printf("%c", 205);
#define ALPHA_CONV(x) x + 64

enum Mode { 
        EXIT = 0,
        ADDITION = 1,
        TRANSPOSE = 2,
        SCALAR_PROD = 3,
        MATRIX_PROD = 4,
        SIMULTANEOUS = 5
};

typedef struct Data {
        int row_no;
        int column_no;
        float entry[MAX][MAX];
} Data;
typedef struct Matrix {
        int count;
        Data data[MAX];
} Matrix;

int GetMaxRows (Matrix array);
int promptChoice (int min, int max);
int DuplicateChecker(Data input);
int isValid (Data array_1, Data array_2, int nMode);

void LoadingPhrase (int seconds);
void OperationMenu (Matrix array);
void AdditionMenu (Matrix array);
void TransposeMenu (Matrix array);
void ScalarProductMenu (Matrix array);
void MatrixProductMenu (Matrix array);
void AllMatrices (Matrix array, int max_rows);
void ViewMatricesList (Matrix array);
void DisplayRow (Matrix array, int row) ;
void DisplayMatrix (Data *input, int isSingleEntry, int row, int column);
void DisplayAllMatrices (Matrix array, int inSelectingMode, int choice);

Data Sum (Data array_1, Data array_2);
Data Transpose (Data array);
Data ScalarProduct (Data array, float constant);
Data MatrixProduct (Data array_1, Data array_2);
Data Initialize (Data input, int count);
Data UpdateAllEntry (Data input, int count);
Matrix EditSingleEntry (Matrix input);
Matrix AddNewMatrix (Matrix matrixData);

#endif