
#include "functions.h"

int main()
{
        char cWinner = ' ', cAns;
        do {
                gameEngine(cWinner);
                printf("\nWould you like to play the game again ?");
                scanf("%s", &cAns);
        } while (cAns == 'y' || cAns == 'Y');
        return 0;
}