#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 9
#define COL 9
#define ROW1 ROW+2   //为了便于统计每个位置周边雷的数目，所以行和列都多两列，不过打印时不打印
#define COL1 COL+2

#define MINE 9      //布置的雷的数目

//初始化棋盘
void init(char show_board[ROW1][COL1], int mine_board[ROW1][COL1], int row, int col);

//打印棋盘
void printBoard(char board[ROW1][COL1], int row, int col);
void printBoard1(int board[ROW1][COL1], int row, int col);

//打印雷
void printBoard1(int board[ROW1][COL1], int row, int col);

//扫雷
int searchMine(char show[ROW1][COL1], int mine[ROW1][COL1], int row, int col);
