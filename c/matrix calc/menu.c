#include "utils.h"
void OperationMenu (Matrix array) {
        int nChoice, max_rows;
        do {
                system("cls");
                max_rows = GetMaxRows (array);
                AllMatrices(array, max_rows);
                BORDER; printf ("\n%sPlease select an operation.%s\n", PURPLE, RESET); 
                printf ("\n\t[1] Addition\n");
                printf ("\t[2] Transpose\n");
                printf ("\t[3] Scalar Multiplication\n");
                printf ("\t[4] Matrix Multiplication\n");
                printf ("\t[5] Simultaneous Operation\n");
                printf ("\t%s\n", RETURN); 
                nChoice = promptChoice (0, 5);
                
                switch (nChoice){
                case ADDITION:
                        AdditionMenu (array);
                break;
                case TRANSPOSE:
                        TransposeMenu (array);
                break;
                case SCALAR_PROD:
                        ScalarProductMenu (array);
                break;
                case MATRIX_PROD:
                        MatrixProductMenu (array);
                break;
                case SIMULTANEOUS:
                        // WIP
                break;
                default:
                break;
                }
        } while (!(nChoice == EXIT));
        
}
void AdditionMenu (Matrix array) {
        int i, max_rows = GetMaxRows (array), index1, index2, key = INVALID;
        Data sum;
        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sSelect first matrix: %s\n", PURPLE, RESET); 
        for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
        printf ("\n");
        index1 = promptChoice (1, array.count);

        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sSelect second matrix: %s\n", PURPLE, RESET); 
        for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
        printf ("\n");
        index2 = promptChoice (1, array.count);
        key = isValid (array.data[index1], array.data[index2], ADDITION);
        if (key == VALID) {
                sum = Sum (array.data[index1], array.data[index2]);
                printf ("%s%c + %c = %s\n", PURPLE, ALPHA_CONV(index1), ALPHA_CONV(index2), RESET); 
                DisplayMatrix(&sum, FALSE, INVALID, INVALID);
        } else if (key == INVALID) printf("\n%sInvalid input!%s\n", RED, RESET); 
        BORDER; printf ("\nPress any key to continue...");
        getch();
}
void TransposeMenu (Matrix array) {
        int i, max_rows = GetMaxRows (array), index;
        Data newData;
        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sSelect a matrix: %s\n", PURPLE, RESET); 
        for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
        printf ("\n");

        index = promptChoice (1, array.count);

        system("cls");
        AllMatrices(array, max_rows);
        newData = Transpose (array.data[index]);
        printf ("%s%c\' = %s\n", PURPLE, ALPHA_CONV(index), RESET); 
        DisplayMatrix(&newData, FALSE, INVALID, INVALID);
        BORDER; printf ("\nPress any key to continue...");
        getch();
}
void ScalarProductMenu (Matrix array) {
        int i, max_rows = GetMaxRows (array), index;
        float constant;
        Data product;
        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sSelect a matrix: %s\n", PURPLE, RESET); 
        for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
        printf ("\n");

        index = promptChoice (1, array.count);

        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sEnter constant: %s\n", PURPLE, RESET); 
        scanf("%f", &constant);
        product = ScalarProduct (array.data[index], constant);
        printf ("%s%c * %.2f = %s\n", PURPLE, ALPHA_CONV(index), constant, RESET); 
        DisplayMatrix(&product, FALSE, INVALID, INVALID);
        BORDER; printf ("\nPress any key to continue...");
        getch();
}
void MatrixProductMenu (Matrix array) {
        int i, max_rows = GetMaxRows (array), index1, index2, key = INVALID;
        Data product;
        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sSelect first matrix: %s\n", PURPLE, RESET); 
        for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
        printf ("\n");
        index1 = promptChoice (1, array.count);

        system("cls");
        AllMatrices(array, max_rows);
        BORDER; printf ("\n%sSelect second matrix: %s\n", PURPLE, RESET); 
        for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
        printf ("\n");
        index2 = promptChoice (1, array.count);
        key = isValid (array.data[index1], array.data[index2], MATRIX_PROD);
        if (key == VALID) {
                product = MatrixProduct (array.data[index1], array.data[index2]);
                printf ("%s%c * %c = %s\n", PURPLE, ALPHA_CONV(index1), ALPHA_CONV(index2), RESET); 
                DisplayMatrix(&product, FALSE, INVALID, INVALID);
        } else if (key == INVALID) printf("\n%sInvalid input!%s\n", RED, RESET); 
        BORDER; printf ("\nPress any key to continue...");
        getch();
}