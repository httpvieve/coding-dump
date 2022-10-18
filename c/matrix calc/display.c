#include "utils.h"
void LoadingPhrase (int seconds) {
        int i;
        for (i = 0; i < seconds; i++) {
                printf (".");
                Sleep (200*seconds);
        }
}

void DisplayMatrix (Data *input, int isSingleEntry, int row, int column)
{
        int i, j;
        for (i = 0; i < input->row_no; i++)
        {
                printf ("\t");
                for (j = 0; j < input->column_no; j++) {
                        if (isSingleEntry == TRUE && i == row - 1 && j == column - 1) printf ("%s%.2f%s   ", RED, input->entry[i][j], RESET);
                        else printf ("%.2f   ", input->entry[i][j]);
                }
        printf ("\n");
        }
}

void DisplayAllMatrices (Matrix array, int inSelectingMode, int choice) {
        int i;
        system("cls");
        BORDER; printf ("\n%sCURRENT DATA [Total: %d]%s\n", CYAN, array.count, RESET); BORDER;
        if (inSelectingMode == TRUE) {
                for (i = 1; i < array.count + 1; i++) printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
                printf ("\n\t%s\n", RETURN);
        } else if (inSelectingMode == FALSE) {
                for (i = 1; i < array.count + 1; i++) {
                        if (i == choice) printf ("%s\n\t[%d] Matrix %c (%d x %d)%s", RED, i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no, RESET);
                        else printf ("\n\t[%d] Matrix %c (%d x %d)", i, ALPHA_CONV(i), array.data[i].row_no, array.data[i].column_no);
                }
        }
}
void ViewMatricesList (Matrix array) {
        int choice;
        system("cls");
        if (array.count == 0) {
                printf ("\n\t%sNo matrix data found!%s\n\nPlease add a matrix first. \n\nReturning back to main menu", RED, RESET);
                LoadingPhrase (3);
        } else {
                do {
                DisplayAllMatrices (array, TRUE, INVALID);
                choice = promptChoice (0, array.count);
                if (!(choice == EXIT)) {
                DisplayAllMatrices (array, FALSE, choice);
                printf ("\n"); BORDER; printf ("\nViewing data for Matrix %c\n", ALPHA_CONV(choice));
                DisplayMatrix(&array.data[choice], FALSE, INVALID, INVALID);
                BORDER; printf ("\nPress any key to continue...");
                getch();
                }
                } while (!(choice == EXIT));
        }
}
void DisplayRow (Matrix array, int row) {
        int a, c;
        for (a = 1; a <= array.count; a++) {
                for (c = 0; c < array.data[a].column_no; c++) {
                        if ((int)array.data[a].entry[row][c] == NULL) printf ("      ");
                        else printf ("%.2f  ", array.data[a].entry[row][c]);
                }
                printf ("\t");
        }
}

void AllMatrices (Matrix array, int max_rows)
{
        int a, b;
        if (max_rows > 1) {
        for (a = 1; a <= array.count; a++) {
                printf ("%sMatrix %c%s", CYAN, ALPHA_CONV(a), RESET);
                for (b = 0; b < array.data[a].column_no - 1; b++) {
                        printf ("\t");
                }
        }
        printf ("\n");
        for (a = 0; a < max_rows; a++) {
                DisplayRow (array, a);
                printf ("\n");
                }
        }
        
}
