/*
    Skeleton file for PASSWORD problem.
	
    lASTNAME, FIRSTNAME: 
	SECTION: 
	DATE: 
	
    Violation of any of the RESTRICTIONS will result to point deduction. 
*/


/* Do NOT include other header files.  

   Do NOT use library functions that we did not discuss/cover in class.
*/
#include <stdio.h>
#include <string.h>

/* Use these string typedefs. */
typedef char String30[31];
typedef char String60[61];



/*
    TO DO: 
    
    Implement the functions as specified in the PASSWORD.PDF file.
	
	RESTRICTIONS:
	1. Make sure that you follow the function prototypes specified in population.h
	2. Do NOT call printf() or scanf() in any of the required function definition
	   EXCEPT in the main() function.
	3. Use only the library function that we discussed in class.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
*/


/* 
   Step 1: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void pass_init (String60 temp, 
	        String30 first, 
		String30 last)
{
	int a, i, j, len_1 = strlen(first), len_2 = strlen(last), ctr = len_1;
	for (i = 0; i <= len_1 + len_2 + 1; i++)
	{
		if (i < len_1)
			temp[i] = first[i]; 
		else if ( i == len_1)
			temp[i] = '_';
		else 
			temp[i] = last[i - len_1 - 1];
	}
	
}

/* 
   Step 2: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void pass_length_checker (String60 password)
{
	int key, len = strlen(password);
	String60 temp;

	if (len < 8)
	{
		key = (int) (password[len - 1]) + 1;
		while (len < 8)
		{
			password[len++] = (char)(key);
			if (key == 122)
				key = 97;
			else
				key++;
		}
		password[8] = '\0';
	}
}

/* 
   Step 3: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void pass_capitalize (String60 password)
{
	int i, len = strlen(password);

	for (i = 0; i < len; i++)
	{
		if (i == 0 && password[i] > 96 && password[i] < 123)
			password[i] = (char) (((int) (password[i])) - 32);
		if (password[i] == '_' && password[i + 1] > 96 && password[i + 1] < 123) 
			password[i + 1] = (char) (((int) (password[i + 1])) - 32);

	}
}

/* 
   Step 4: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void pass_replace_vowel (String60 password)
{
	int i, len = strlen(password), conv;

	for (i = 0; i < len; i++)
	{
		conv = (int) password[i];
		switch (conv)
		{
		case 97:
			password[i] = (char)(64);
		break;
		case 101:
			password[i] = (char)(51);
		break;
		case 105:
			password[i] = (char)(49);
		break;
		case 111:
			password[i] = (char)(48);
		break;
		case 117:
			password[i] = (char)(94);
		break;
		}
	}

}

/* 
   Step 5: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void pass_replace_consonant (String60 password)
{
	int i, len = strlen(password), conv;

	for (i = 0; i < len; i++)
	{
		conv = (int) password[i];
		switch (conv)
		{
		case 115:
			password[i] = (char)(42);
		break;
		case 116:
			password[i] = (char)(63);
		break;
		}
	}
} 
int main()
{
	String30 firstName, lastName;
	String60 password;

	// Do NOT add any printf() for prompts before the scanf() function calls.
	scanf("%s", firstName);
	scanf("%s", lastName);
	
	
	// Call Step 1 function after this comment and before the printf() statement.
	pass_init (password, firstName, lastName);
	printf("%s\n", password);  // prints the password value after step 1.
	
	
	// Call Step 1 function after this comment and before the printf() statement.
	pass_length_checker (password);
	printf("%s\n", password);  // prints the password value after step 1.
	
	
	// Call Step 2 function after this comment and before the printf() statement.
	pass_capitalize (password);
	printf("%s\n", password);  // prints the password value after step 2.
	
	
	// Call Step 3 function after this comment and before the printf() statement.
	pass_replace_vowel (password);
	printf("%s\n", password);  // prints the password value after step 3.
	
	
	// Call Step 4 function after this comment and before the printf() statement.
	pass_replace_consonant (password);
	printf("%s\n", password);  // prints the password value after step 4.
	
	
	// Call Step 5 function after this comment and before the printf() statement.
	
	//printf("%s\n", password);  // prints the FINAL password value after step 5.
	
	return 0;
}

	
	
	
