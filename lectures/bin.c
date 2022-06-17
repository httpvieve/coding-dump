#include <stdio.h>
#include <string.h>

struct nameTag {
        char First[20];
        char Last[20];
 };

struct studentTag {
        int ID;
        struct nameTag name;
        float grade;
 };
typedef struct studentTag student;
int main ()
{
        FILE *source;
        
        // WRITING FILES
        /*
        char ch = 'A';
        int i = 123;
        float f = 6.87f;
        double d = 3.1416;

        source = fopen ("binary.dat", "wb");
        fwrite (&ch, sizeof(char), 1, source);
        fwrite (&i, sizeof(int), 1, source);
        fwrite (&f, sizeof(float), 1, source);
        fwrite (&d, sizeof(double), 1, source);
        */
       /*
        int i;
        int A[5] = {10, 20, 30, 40, 50};

        source = fopen("array.dat", "wb");
        for (i = 0; i < 5; i++) fwrite (&A[i], sizeof(int), 1, source);
                // writing the elements of an array individually      
        fwrite (&A, sizeof(int), 5, source);
                //writing the array as a whole
        */
       // READING FILES 
       
        int x;
        source = fopen("sample.dat", "rb");
        fread (&x, sizeof(int), 1, source);
        printf("Value of x : %d", x);

        char ch;
        int i;
        float f;
        double d;
        source = fopen("binary.dat", "rb");

        fread (&ch, sizeof(char), 1, source);
        fread (&i, sizeof(int), 1, source);
        fread (&f, sizeof(float), 1, source);
        fread (&d, sizeof(double), 1, source);

        printf("Value of ch : %c\n", ch);
        printf("Value of i : %d\n", i);
        printf("Value of f : %f\n", f);
        printf("Value of d : %f\n", d);
        
       //WRITING STRUCTS
        // student A;
        // student B[100];

        // A.ID = 121;
        // strcpy(A.name.Last, "Huang");
        // strcpy(A.name.First, "Renjun");
        // A.grade = 4.0;

        // B[0].ID = 121;
        // strcpy(B[0].name.Last, "Filbert");
        // strcpy(B[0].name.First, "Gonzales");
        // B[0].grade = 3.0;

        // source = fopen ("struct.dat", "wb");
        // fwrite (&A, sizeof(student), 1, source);
        // fwrite (&B, sizeof(student), 100, source);

        // fprintf (stdout, "%d\n", A.ID);
        // fprintf (stdout, "%s ", A.name.First);
        // fprintf (stdout, "%s\n", A.name.Last);
        // fprintf (stdout, "%f\n", A.grade);
        
        // fprintf (stdout, "%d\n", B[0].ID);
        // fprintf (stdout, "%s ", B[0].name.First);
        // fprintf (stdout, "%s\n", B[0].name.Last);
        // fprintf (stdout, "%f\n", B[0].grade);
        
        fclose (source);
        return 0;
}
        //size_t -> number of objects that will be written in the file