/*
        Student Name: Genevieve S. Balestramon
        Section: S15A

        Activity 10: Value of Structure as Parameter and Return Value

        TODO :
        1. Declare struct data type named "movieType".
        2. Implement fave_movie() -> returns a struct variable 
                containing details of you favorite movie.
        3. Implement print_movie() -> displays the details of 
                your favorite movie with proper labels.                
*/

#include <stdio.h> 
#include <string.h>

#define MAX 50

typedef char data[MAX];

/**
 * typedef struct movieType 
 * @year: year when the movie was released
 * @title: full title of the movie
 *      struct popularity
 *      @rating: all-time rating of the movie 
 *      @rank: all-time rank of the movie in the IMDB site 
 *      struct writers
 *      @story: (writer - story)
 *      @screenplay: (writer - screenplay)
 * @maincast: main actors of the movie
 * 
 * Used in storing th details of the movie
 */

typedef struct {
        int year;
        data title;
        data director; 
        
        struct
        {
                float rating;
                int rank;
        } popularity;
       
        struct 
        {
                data story;
                data screenplay;
        } writer;
        
        data maincast[MAX];
} movieType;

/*
        This is a struct function that assigns and stores all the details of my favorite movie
                which will be prompted to other functions  
        @return details of the movie
*/
movieType fave_movie()
{
        movieType myFave = {2019, 
                           "Parasite", 
                           "Bong Joon Ho", 
                           {8.5, 165},
                           {"Bong Joon Ho", "Han Jin-won"},
                           {"Kang-ho Song", "Sun-kyun Lee", "Yeo-jeong Cho"}};
        return myFave;
}

/*
        This function organizely displays the details of my favorite 
                movie with respective labels included.
        @param struct data which stores the movie infos
*/
void 
print_movie (movieType data)
{
        int i;

        printf("   Title : %s (%d)\n", data.title, 
                                       data.year);
        printf("Director : %s\n", data.director);
        printf(" Writers : %s (story), \n\t   %s (screeenplay)\n", data.writer.story, 
                                                                   data.writer.screenplay);
        printf("   Casts : ");
        for (i = 0; i < 3; i ++) 
                printf("%s\n\t   ", data.maincast[i]);

        printf("\n-------IMDB POPULARITY DATA-------\n");
        printf("Popularity Rating : %.2f/10\n", data.popularity.rating);
        printf("  Popularity Rank : %d\n", data.popularity.rank);
}

int
main()
{
        movieType movie;
        movie = fave_movie();
        print_movie(movie);
        return 0;
}