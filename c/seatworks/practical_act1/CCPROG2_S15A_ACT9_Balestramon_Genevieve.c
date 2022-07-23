/*
        Student : Genevieve Balestramon
        Activity 9 : Structure Declaration
*/
#include <stdio.h>

struct fullName {
        char last_name[30];
        char first_name[30];
        char middle_name[30];
} ;

struct birthDay {
        int month;
        int day;
        int year;
} ;

int 
main(int argc, char **argv)
{
        struct fullName student_name;
        struct birthDay student_birth; 
        return 0;
}