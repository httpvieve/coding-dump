#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#ifndef HEADER_H
#define HEADER_H

char cBoard[3][3];
const char PLAYER = 'X';
const char COMPUTER ='O';
void initBoard();
void displayBoard();
int freeSpaceCounter();
void playerMove();
void compMove();
char checkWinner();
void declareWinner(char cPlayer);
void gameEngine (char cWinner);
#endif