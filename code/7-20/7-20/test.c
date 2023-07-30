#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/*
* 打印菜单
* 1 开始   0结束
* 创建二维数组
* 初始化二维数组
* 布置雷  一个棋盘布置，一个棋盘打印
* 根据坐标扫雷
*	如果是雷，结束
*	如果不是雷，此位置改为周边雷的个数
*	剩下所有雷，游戏成功
*
*/

void menu()
{
	printf("****************\n");
	printf("**** 1 play ****\n");
	printf("**** 0 exit ****\n");
	printf("****************\n");

}


void game()
{
	//定义棋盘
	char show_board[ROW1][COL1] = { 0 };
	int mine_board[ROW1][COL1] = { 0 };
	//初始化棋盘
	init(show_board, mine_board, ROW1, COL1);
	//打印棋盘
	printBoard(show_board, ROW, COL);
	//printBoard1(mine_board, ROW, COL);

	while (1)
	{
		//扫雷
		int ret = searchMine(show_board, mine_board, ROW, COL);
		system("cls");

		//扫雷成功
		int num = 0;

		for (int i = 1; i <= ROW; i++)
		{
			for (int j = 1; j <= COL; j++)
			{
				if (show_board[i][j] == '*')
				{
					num++;
				}
			}
		}

		if (num == MINE)
		{
			printf("扫雷成功\n");
			printBoard1(mine_board, ROW, COL);
			break;
		}

		//扫雷失败
		if (ret == 0)
		{
			printf("扫雷失败，你被炸死了!!!\n");
			printBoard1(mine_board, ROW, COL);
			break;
		}

		//打印棋盘
		printBoard(show_board, ROW, COL);
		//printBoard1(mine_board, ROW, COL);
	}
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("当前雷盘共埋藏%d个雷，找出全部雷获胜\n", MINE);
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
