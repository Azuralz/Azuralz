#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 9
#define COL 9
#define ROW1 ROW+2   //Ϊ�˱���ͳ��ÿ��λ���ܱ��׵���Ŀ�������к��ж������У�������ӡʱ����ӡ
#define COL1 COL+2

#define MINE 9      //���õ��׵���Ŀ

//��ʼ������
void init(char show_board[ROW1][COL1], int mine_board[ROW1][COL1], int row, int col);

//��ӡ����
void printBoard(char board[ROW1][COL1], int row, int col);
void printBoard1(int board[ROW1][COL1], int row, int col);

//��ӡ��
void printBoard1(int board[ROW1][COL1], int row, int col);

//ɨ��
int searchMine(char show[ROW1][COL1], int mine[ROW1][COL1], int row, int col);
