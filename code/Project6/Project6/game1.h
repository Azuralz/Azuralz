#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void chessboard(char board[ROW][COL], int row, int col);
void playchess(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);