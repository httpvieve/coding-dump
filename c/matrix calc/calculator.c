#include "menu.c"
#include "display.c"
#include "operation.c"

Data Initialize (Data input, int count)
{
        int i, j;
        system("cls");
        printf ("\nModifying dimensions for matrix %c...", ALPHA_CONV(count));;
        printf ("\n\tPlease enter the number of rows: ");
        scanf ("%d", &input.row_no);
        printf ("\tPlease enter the number of columns: ");
        scanf ("%d", &input.column_no);
        for (i = 0; i < input.row_no; i++)
                for (j = 0; j < input.column_no; j++) input.entry[i][j] = 0;
        
        printf ("%sNew matrix %c successfully added!%s\n\n", CYAN, ALPHA_CONV(count), RESET);
        printf ("Loading entries");
        LoadingPhrase (2);
        return input;
}
Data UpdateAllEntry (Data input, int count) {
        int i, j;
        for (i = 0; i < input.row_no; i++)
        {
                
                for (j = 0; j < input.column_no; j++) {
                        system("cls");
                        DisplayMatrix(&input, TRUE, i + 1, j + 1);
                        printf ("\nPlease enter the value for the current entry: ");
                        scanf ("%f", &input.entry[i][j]);
                        printf ("%sSuccessfully updated!%s\n\n", GREEN, RESET);
                        Sleep (250);
                }
        }
        system("cls");
        printf ("%sEntries for matrix %c successfully updated!%s\n\n", CYAN, ALPHA_CONV(count), RESET);
        DisplayMatrix(&input, FALSE, INVALID, INVALID);
        printf ("\nReturning back to main menu");
        //getch();
        return input;
}
Matrix EditSingleEntry (Matrix input) {
        int row, column, choice;
        system("cls");
        if (input.count == 0) {
                printf ("\n\t%sNo matrix data found!%s\n\nPlease add a matrix first. \n\nReturning back to main menu", RED, RESET);
                LoadingPhrase (3);
        } else {
                do {
                        DisplayAllMatrices (input, TRUE, INVALID);
                        choice = promptChoice (0, input.count);
                        if (!(choice == 0)) {
                                system("cls");
                                printf ("Viewing data for Matrix %c\n\n", ALPHA_CONV(choice));
                                DisplayMatrix(&input.data[choice], FALSE, INVALID, INVALID); 
                                printf ("\nEdit entry data for which row? ");
                                scanf ("%d", &row); 
                                printf ("Edit entry data for which column? ");
                                scanf ("%d", &column);
                                
                                system("cls");
                                printf ("Current data in selected entry is %.2f.\n\n", input.data[choice].entry[row - 1][column - 1]);
                                DisplayMatrix(&input.data[choice], TRUE, row, column);
                                printf ("\nEnter new data: ");
                                scanf ("%f", &input.data[choice].entry[row - 1][column - 1]);
                                printf ("%sEntries for matrix %c successfully updated!%s\n\n", CYAN, ALPHA_CONV(choice), RESET);
                                DisplayMatrix(&input.data[choice], FALSE, INVALID, INVALID);
                                printf ("Returning back to list");
                        LoadingPhrase (3);
                        }
                } while (!(choice == EXIT));
        }  
        return input;
} 

Matrix AddNewMatrix (Matrix matrixData) {
        matrixData.count++;
        matrixData.data[matrixData.count] = Initialize(matrixData.data[matrixData.count], matrixData.count);
        matrixData.data[matrixData.count] = UpdateAllEntry(matrixData.data[matrixData.count], matrixData.count);
        LoadingPhrase (2);
        return matrixData;
}

int main ()
{
        Matrix matrixData;
        matrixData.count = 0;
        int nChoice, max_rows = 0;

        do {
                system("cls");
                max_rows = GetMaxRows (matrixData);
                AllMatrices(matrixData, max_rows);
                BORDER;
                printf ("\n\t%s\n", "[1]\tAdd a new matrix");
                printf ("\t%s\n", "[2]\tView all matrices"); 
                printf ("\t%s\n", "[3]\tDelete a matrix"); 
                printf ("\t%s\n", "[4]\tEdit matrix entry"); 
                printf ("\t%s\n", "[5]\tSolve matrices"); 
                printf ("\t%s\n", EXIT_PROGRAM); BORDER;
                printf ("\n");
                nChoice = promptChoice (0, 5);
                switch (nChoice){
                case 1:
                        matrixData = AddNewMatrix (matrixData);
                break;
                case 2:
                        ViewMatricesList (matrixData);
                break;
                case 3:
                        // wip
                break;
                case 4:
                        matrixData = EditSingleEntry (matrixData);
                break;
                case 5:
                        OperationMenu(matrixData);
                break;
                default:
                break;
                }
        } while (!(nChoice == EXIT));
       
        return 0;
}