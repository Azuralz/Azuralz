#include"game1.h"


void chessboard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0;x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			board[x][y] = ' ';
		}
	}
}

void playchess(char board[ROW][COL], int row, int col)
{
	int x = 0;
	for (x = 0; x < row; x++)
	{
		int y = 0;
		for (y = 0; y < col; y++)
		{
			printf(" %c ",board[x][y]);
			if (y < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (x < row-1)
		{
			for (y = 0; y < col; y++)
			{
				printf("---");
				if (y < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");

		}
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	while (1)
	{
		printf("请输入坐标\n");
		scanf("%d%d", &x,&y);
		if (x <= row && x >= 1 && y <= col  && y >= 1)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用\n");
			}
				
		}
		else
		{
			printf("坐标非法");
		}
			
	}
}
int Full(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Iswin(char board[ROW][COL], int row, int col)
{
	int x = 0;
	
	for (x = 0; x < row; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][1] != ' ')
		{
			return board[x][1];
		}
	}
	for (x = 0; x < col; x++)
	{
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x] && board[1][x] != ' ')
		{
			return board[1][x];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (1 == Full(board,ROW,COL))
	{
		return 'P';
	}
	return 'C';
	
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{

		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}