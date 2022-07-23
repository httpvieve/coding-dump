#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int main( int argc, char *argv[]){
       // int* stuff = (int*) malloc(5*sizeof(int)); //usually returns 4 bytes
        int* stuff = (int*) calloc(5, sizeof(int));  //initializes allloctated memomy to 0, number and size of elements should specified
        stuff[1] = 1; 
        stuff[2] = 2; 
        stuff[3] = 3; 
        stuff[4] = 4; 
 

        printf("The values are %d and %d", stuff[2], stuff[0]);
        free(stuff);
        return 0;
}
