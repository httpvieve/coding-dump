#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define NULL 0
#include "header.h"
void initBoard()
{
        int a, b;
        for (a = 0; a < 3; a++){
                for (b = 0; b < 3; b++){
                        cBoard[a][b] = ' ';
                }
        }
}

void displayBoard()
{
        int a, b;
        for (a = 0; a < 3; a++){
                printf("|");
                for (b = 0; b < 3; b++){
                        printf(" %c |", cBoard[a][b]);
                }
                if (a != 2)
                        printf("\n|---|---|---|\n");
        }
        printf("\n");
}

int freeSpaceCounter()
{
        int a, b, nCounter = 9;
        for (a = 0; a < 3; a++){
                for (b = 0; b < 3; b++){
                        if(!(cBoard[a][b] == ' '))
                                nCounter --;

                }
        }
        return nCounter;
}

void playerMove()
{
        int a, b;
        do {
                printf("Enter row number [1, 3]: \n >>>");
                scanf("%d", &a);
                a--;
                printf("Enter column number [1, 3]: \n >>>");
                scanf("%d", &b);
                b--;
                if (!(cBoard[a][b] == ' ')){
                printf("Invalid move!\nSelected tile is already occupied.");

                } else {
                cBoard[a][b] = PLAYER;
                break;
                }
        } while (!(cBoard[a][b] == ' '));

}

void compMove()
{
        srand(time(NULL));
        int a, b;
        if (freeSpaceCounter() > 0){
                do {
                        a = rand() % 3;
                        b = rand() % 3;
                } while (!(cBoard[a][b] == ' '));
                cBoard[a][b] = COMPUTER;
        } else declareWinner(' ');
}

char checkWinner()
{
        int a, b;
        for (a = 0; a < 3; a++){
                if (cBoard[a][0] == cBoard[a][1] && cBoard[a][0] == cBoard[a][2]){
                        return cBoard[a][0];
                }
                if (cBoard[0][a] == cBoard[1][a] && cBoard[0][a] == cBoard[2][a]){
                        return cBoard[0][a];
                }
                if (cBoard[0][0] == cBoard[1][1] && cBoard[0][0] == cBoard[2][2]){
                        return cBoard[0][0];
                }
                if (cBoard[0][2] == cBoard[1][1] && cBoard[0][2] == cBoard[2][0]){
                        return cBoard[0][2];
                }
        }
        return ' ' ;
}

void declareWinner(char cPlayer)
{
        if (cPlayer == PLAYER){
                printf("YOU WIN!");

        } else if (cPlayer == COMPUTER){
                printf("YOU LOSE!");
        } else if (cPlayer == ' ' && freeSpaceCounter() == 0){
                printf("IT'S A DRAW!");
        }
}
void gameEngine (char cWinner)
{
        initBoard();
        while(cWinner == ' ' && (!(freeSpaceCounter() == 0))){
                displayBoard();
                playerMove();
                cWinner = checkWinner();
                if (!(cWinner == ' ') || freeSpaceCounter() == 0){
                        break;
                }
                compMove();
                cWinner = checkWinner();
                if (!(cWinner == ' ') || freeSpaceCounter() == 0){
                        break;
                }
        }
        displayBoard();
        declareWinner(cWinner);
}
#endif