#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//初始化棋盘
void init(char show_board[ROW1][COL1], int mine_board[ROW1][COL1], int row, int col)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			show_board[i][j] = '*'; //用于展示的棋盘界面用*表示没有扫的位置
			mine_board[i][j] = 0;  //雷盘初始全置为0
		}
	}

	//布置雷
	for (int i = 0; i < MINE; i++)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine_board[x][y] == 0)
		{
			mine_board[x][y] = 1; //随机布置雷，如果是雷将对应位置改为1
		}
		else
		{
			i--;
		}
	}
}


//打印棋盘
void printBoard(char board[ROW1][COL1], int row, int col)
{
	for (int i = 0; i <= col; i++)
	{
		printf("%2d  ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%2d  ", i);
		for (int j = 1; j <= col - 1; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %c ", board[i][col]);

		printf("\n");
		if (i < row)
		{
			printf("    ");
			for (int j = 1; j <= col; j++)
			{
				printf("--- ");
			}
		}
		printf("\n");
	}
	printf("\n");

}

void printBoard1(int board[ROW1][COL1], int row, int col)
{
	//打印行号
	for (int i = 0; i <= col; i++)
	{
		printf("%2d  ", i);
	}
	printf("\n");

	//打印雷盘
	for (int i = 1; i <= row; i++)
	{
		//打印列号
		printf("%2d  ", i);

		for (int j = 1; j <= col - 1; j++)
		{
			if (board[i][j] == 0)
			{
				//为了方便看雷，如果不是雷的位置，用空格代替
				printf(" %2c |", (char)board[i][j]);
			}
			else
			{
				//如果是雷的位置，用1的ASCll码值表示
				printf("%2c |", (char)board[i][j]);
			}
		}

		//打印最后一列有些特殊，没有最后的|
		if (board[i][col] == 0)
		{
			printf(" %2c ", (char)board[i][col]);
		}
		else
		{
			printf("%2c ", (char)board[i][col]);
		}
		printf("\n");

		//打印的---行要比规定的少一行   
		if (i < row)
		{
			printf("    ");
			for (int j = 1; j <= col; j++)
			{
				printf("--- ");
			}
		}
		printf("\n");
	}
	printf("\n");

}


//扫雷

//雷的个数
int countMine(int mine[ROW1][COL1], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
}

//递归
void extend(char show[ROW1][COL1], int mine[ROW1][COL1], int x, int y)
{
	//如果坐标合法，进行递归
	if (x > 0 && x <= ROW && y > 0 && y <= COL)
	{
		//定义count进行周边雷数的统计
		int count = countMine(mine, x, y);
		//如果周边雷的个数是0，进行递归
		if (count == 0)
		{
			//将周边为0的雷区改为空格
			show[x][y] = ' ';
			//对周边雷区进行递归展开
			for (int i = x - 1; i <= x + 1; i++)
			{
				for (int j = y - 1; j <= y + 1; j++)
				{
					//如果周边雷区还没有被扫描，则进行展开
					if (show[i][j] == '*')
					{
						extend(show, mine, i, j);
					}
				}
			}
		}
		//否则输入坐标的show_board棋盘改为字符状态下的周边雷数
		else
		{
			show[x][y] = count + '0';
		}

	}
}

int searchMine(char show[ROW1][COL1], int mine[ROW1][COL1], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入扫雷坐标:>");
		scanf("%d %d", &x, &y);
		//如果坐标合法，没有被占用，并且不是雷，则进行展开，知道周边有雷
		if (x > 0 && x <= row && y > 0 && y <= col && mine[x][y] == 0 && show[x][y] == '*')
		{
			extend(show, mine, x, y);
			return 1;
		}
		else
		{
			//如果坐标合法但是是雷，则返回0，扫雷失败
			if (x > 0 && x <= row && y > 0 && y <= col && mine[x][y] == 1)
			{

				return 0;
			}
			//除以上情况，坐标非法，重新输入
			else
			{
				printf("输入坐标错误，请重新输入\n");
			}
		}
	}


}
