#include "utils.h"
void DisplayMatrix (matrixData *matrix)
{
        int i, j;
        for (i = 0; i < matrix->rows; i++)
        {
                for (j = 0; j < matrix->columns; j++) ENTRY_PRINT (matrix->data[i][j]);
        printf ("\n");
        }
}
void InitializeMatrix (matrixData *matrix)
{
        int i, j;
        for (i = 0; i < matrix->rows; i++)
        {
                for (j = 0; j < matrix->columns; j++) matrix->data[i][j] = 0;
        printf ("\n");
        }
}
void UpdateSingleEntry (matrixData *matrix)
{
        int row, column;
        DisplayMatrix (matrix);
        printf ("Change entry value for which row? ");
        scanf ("%d", &row);
        printf ("Change entry value for which column? ");
        scanf ("%d", &column);
        printf ("Current value in selected entry is %d.\nEnter new value: ");
        scanf ("%lf", &matrix->data[row][column]);
        printf ("Successfully changed!");
}
matrixData UpdateAllEntry (matrixData matrix)
{
        int i, j;
        printf ("Please enter the value for each entry. \n");
        for (i = 0; i < matrix.rows; i++)
        {
                for (j = 0; j < matrix.columns; j++) 
                {
                printf ("R%dC%d ->", i, j); 
                scanf ("%f", &matrix.data[i][j]);
                }
        printf ("\n");
        }
        return matrix;
}

void ScalarMultiplication ()
{

}
void Addition () 
{

}
void MatrixMultiplication ()
{

}
void Transpose () 
{

}
int main ()
{
        int nMatrix;
        printf ("Please enter the number of matrices to be solved\n\t>> ");
        scanf ("%d", &nMatrix);
        matrixData matrix[nMatrix];    
        for (int i = 0; i < nMatrix; i++) InitializeMatrix (&matrix[i]);

        int i, j;
        for (i = 0; i < nMatrix; i++){
                printf ("Enter the number of rows for MATRIX %c \n\t>> ", i + 97);
                scanf ("%d", &matrix[i].rows);
                printf ("Enter the number of columns for MATRIX %c \n\t>> ", i + 97);
                scanf ("%d", &matrix[i].columns);
                matrix[i] = UpdateAllEntry(matrix[i]); 
                DisplayMatrix (&matrix[i]);
        }
        //InitializeMatrix (matrix);
        //DisplayMatrix (matrix);

        //printf ("Select an operation: %s%s%s%s%s", "\ta. Addition\n", "\tb. Scalar Multiplication\n", "\tc. Matrix Multiplication\n", "\td. Transpose\n", "\te. Exit\n");
        //scanf (" %c", &matrix.operation);



        //int matrixArray[matrix.rows][matrix.column];
        //DisplayBoard (&matrix);
        
        

       
        return 0;
}