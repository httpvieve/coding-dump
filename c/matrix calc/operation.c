#include "utils.h"

int GetMaxRows (Matrix array) {
        int max = 0, i;
        for (i = 1; i <= array.count; i++) {
                if (array.data[i].row_no >= max) max = array.data[i].row_no;
        }
        return max;
}


int isValid (Data array_1, Data array_2, int nMode) {
        switch (nMode) {
                case ADDITION:
                if (array_1.row_no == array_2.row_no && array_1.column_no == array_2.column_no) return VALID;
                break;
                case MATRIX_PROD:
                if (array_1.column_no == array_2.row_no) return VALID;
                break;
                default:
                break;
        }
        return INVALID;
}

int promptChoice (int min, int max) {
        int choice;
        do {
                scanf ("%d", &choice);
                if (choice >= min && choice <= max) {
                        //printf ("\n");
                        return choice;
                }
                else {
                        printf ("%sInvalid input!%s\n", RED, RESET);
                        choice = INVALID;
                        printf ("Enter valid choice [%d - %d]: ", min, max);

                }        
        } while (choice == INVALID);
        return 0;
}

int DuplicateChecker(Data input){

}
Data Sum (Data array_1, Data array_2) {
        Data sum;
        int i, j;
        sum.row_no = array_1.row_no;
        sum.column_no = array_1.column_no;
        
        for (i = 0; i < sum.row_no; i++)
                for (j = 0; j < sum.column_no; j++) 
                        sum.entry[i][j] = array_1.entry[i][j] + array_2.entry[i][j];
                
        return sum;
}

Data ScalarProduct (Data array, float constant) {
        Data product;
        int i, j;
        product.row_no = array.row_no;
        product.column_no = array.column_no;

        for (i = 0; i < product.row_no; i++)
                for (j = 0; j < product.column_no; j++) 
                        product.entry[i][j] = array.entry[i][j] * constant;
        return product;
}

Data MatrixProduct (Data array_1, Data array_2) {
        Data product;
        int i, j, k, key;
        
        product.row_no = array_1.row_no;
        product.column_no = array_2.column_no;
        key = array_1.column_no;

        for (i = 0; i < product.row_no; i++) 
                for (j = 0; j < product.column_no; j++) 
                        product.entry[i][j] = 0;

        for (i = 0; i < product.row_no; i++) {
                for (j = 0; j < product.column_no; j++) {
                        for (k = 0; k < key; k++) {
                                product.entry[i][j] += array_1.entry[i][k] * array_2.entry[k][j];
                        }
                }

        }

        return product;
}
