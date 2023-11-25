import java.util.Scanner;
public class RaggedArray {
        public static void main (String[] args) {
                Scanner prompt = new Scanner (System.in);
                int nRows, i, j;

                System.out.print("Enter the number of rows: \n\t-> ");
                nRows = prompt.nextInt ();

                String[][] strArray = new String[nRows][];
                
                int[] nColumns = new int[nRows]; 
                
                for (i = 0; i < nRows; i++) {
                        System.out.println("Enter the number of columns for row #" + (i + 1) + ":\n\t-> ");
                        nColumns[i] = prompt.nextInt ();
                        for (j = 0; j < nColumns[i]; j++) {
                                System.out.println("Enter data for row #" + (i + 1) + " column #" + (j + 1) + ":\n\t-> ");
                                strArray[i][j] = prompt.nextLine ();
                                System.out.println("Data successfully updated!");
                        }
                }

                for (i = 0; i < nRows; i++) {
                        System.out.print("{ ");
                        for (j = 0; j < nColumns[i]; j++) {
                                System.out.println(strArray[i][j] + ", ");
                        }
                        System.out.print("}");
                }

                prompt.close ();

        }
}