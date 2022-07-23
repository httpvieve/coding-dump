/*
* Name: Genevieve S. Balestramon
* Section: S15A
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 20
typedef char string[201];
typedef struct
{
	string names[5];
	int age[5];
	float grade[5];
	string status[5];
} grade_struct;

/*file_exists
	returns 1 if filepath exists, otherwise, 0
	@param string filename - filename/filepath
	@return int - 1 if file exists, 0 otherwise
*/

void get_status(grade_struct *grades);
FILE *open_file(string filename);
int 
file_exists(string filename)
{
	FILE *fp;

	// function implementation
	fp = open_file(filename);
	if (fp == NULL)
	{
		return 0;
	}
	else
	{
		fclose(fp);
		return 1;
	}

}

/*open_file
	returns pointer to thefile
	@param string filename - filename/filepath
	@return FILE *fp - pointer to the file
*/
FILE 
*open_file(string filename)
{
	FILE *fp;
	
	// function implementation
	fp = fopen (filename, "r");
	return fp;
}

/*read_file
	initializes the names, age, and grade member of a grade_struct object
	@param string filename - pointer to the file
	@param grade_struct *grades - pointer to a grade_struct object
*/
void  read_file(FILE *fp, grade_struct *grades)
{
	string token;
	string name;
	int age;
	float grade;
	int i, key = 0, index;
	string phrase[20];

	// function implementation
	while(fscanf (fp, "%s", token) == 1)
		strcpy(phrase[key++], token);

	for (i = 0; i < MAX_LINES; i++)
	{
		key = 0;
		if (strcmp(phrase[i], "Name") == 0)
			for (index = i; index <  i + 5; index++)
				strcpy(grades->names[key++], phrase[index + 1]);
	
		if (strcmp(phrase[i], "Age") == 0)
			for (index = i; index <  i + 5; index++)
				grades->age[key++] = atoi((phrase[index + 1]));

		if (strcmp(phrase[i], "Grade") == 0)
		{
			key = 0;
			for (index = i ; index <  i + 5; index++)
			{
				
				grades->grade[key] = atof(phrase[index + 1]);
				get_status(grades);
				key++;
			}
		}
	}

}

	


/*get_status
	initializes the status member of a grade_struct object based on the grade member.
	Value should be "PASSED" if grade is > 0.0, otherwise, "FAILED".
	@param grade_struct *grades - pointer to a grade_struct object
*/
void get_status(grade_struct *grades)
{
	int i;
	
	// function implementation
	
}

/*to_csv
	converts the grade_struct object values into a csv file
	@param string filename - filename of the output file
	@param grade_struct *grades - pointer to a grade_struct object
*/
void 
to_csv(string filename, grade_struct *grades)
{
	int i;
	FILE *fp; 
	
	// makes sure that the output file will always start as an empty file
	fp = fopen(filename, "w");
	
	// function implementation
	fprintf(fp, "Name,Age,Grade,Status\n");
	for (i = 0; i < 5; i++)
	{
		fprintf(fp, "%s,%d,%.1f,%s\n", grades->names[i], grades->age[i], grades->grade[i], grades->status[i]);
	}
	fclose(fp);
}


int
main()
{
	// DO NOT MODIFY THIS MAIN FUNCTION
	string filename = "input.txt";
	int exists = 0;
	grade_struct grades;
	FILE *fp;
	
	exists = file_exists(filename);
	
	if (exists)
	{
		fp = open_file(filename);
		read_file(fp, &grades);
		get_status(&grades);
		to_csv("BALESTRAMON_GENEVIEVE_Output.csv", &grades);
		
		fclose(fp);
	}
	else
		printf("ERROR: file does not exists.\n");
	
		
	return 0;
}

