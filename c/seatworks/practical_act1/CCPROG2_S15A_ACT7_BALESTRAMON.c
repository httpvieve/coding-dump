#include <stdio.h>
#include <string.h>

#define ROW_SIZE 2
#define COL_SIZE 2
#define MAX 5

typedef char str30[31];

/* Task 1: Implement input_string_array
	input_string_array
	initializes the 1D array using scanf.
*/

void 
input_string_array (str30 S[], int size)
{
	int i;
	printf("enter string for array index :\n");
	for (i = 0; i < size; i++){
		printf("\t[%d] >> ", i);
		scanf("%s", S[i]);
	}
}

/* Task 2: Implement print_string_array
	print_string_array
	displays content of the 1D array.
*/

void 
print_string_array (str30 S[], int size)
{
	int i;
	printf("strings in array = {");
		for (i = 0; i < size; i++){
			printf("%s", S[i]);
			if (i != size - 1)
			printf(", ");
		}
	printf("}");
}

void
string_1d_io_b()
{
	str30 S[MAX];
	
	printf("[1D array with size %d]\n", MAX);

	input_string_array(S , MAX); // complete the arguments
	print_string_array(S , MAX); // complete the arguments
}

/* Task 3: Implement input_string_array_2d
	input_string_array_2d
	initializes the 2D array using scanf.
*/

void 
input_string_array_2d (str30 arr[][COL_SIZE],int size)
{
	int i, j;
	printf("enter string for array index :\n");
	for (i = 0; i < size; i++){
		for (j = 0; j < COL_SIZE; j++){
		printf("\t[%d][%d] >> ", i, j);
		scanf("%s[^\n]", arr[i][j]);
		}
		}

}

/* Task 4: Implement print_string_array_2d
	print_string_array_2d
	displays content of the 2D array.
*/

void 
print_string_array_2d (str30 arr[][COL_SIZE],int size)
{
	int i, j;
	printf("strings in array = {\n");
	for (i = 0; i < size; i++){
		for (j = 0; j < COL_SIZE; j++){
			printf("%s", arr[i][j]);
			if (j != COL_SIZE - 1)
			printf(", ");
		}
		printf("\n");
	}
	printf("}");

}
void string_2d_io_b()
{
	str30 M[ROW_SIZE][COL_SIZE];

	printf("\n\n[2D array with size %d]\n", ROW_SIZE);

	input_string_array_2d(M, ROW_SIZE); // complete the arguments
	print_string_array_2d(M, ROW_SIZE); // complete the arguments
}

int
main()
{

	string_1d_io_b();
	string_2d_io_b();
	
	return 0;
}



