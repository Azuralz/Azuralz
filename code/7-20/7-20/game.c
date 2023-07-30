#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//��ʼ������
void init(char show_board[ROW1][COL1], int mine_board[ROW1][COL1], int row, int col)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			show_board[i][j] = '*'; //����չʾ�����̽�����*��ʾû��ɨ��λ��
			mine_board[i][j] = 0;  //���̳�ʼȫ��Ϊ0
		}
	}

	//������
	for (int i = 0; i < MINE; i++)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine_board[x][y] == 0)
		{
			mine_board[x][y] = 1; //��������ף�������׽���Ӧλ�ø�Ϊ1
		}
		else
		{
			i--;
		}
	}
}


//��ӡ����
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
	//��ӡ�к�
	for (int i = 0; i <= col; i++)
	{
		printf("%2d  ", i);
	}
	printf("\n");

	//��ӡ����
	for (int i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("%2d  ", i);

		for (int j = 1; j <= col - 1; j++)
		{
			if (board[i][j] == 0)
			{
				//Ϊ�˷��㿴�ף���������׵�λ�ã��ÿո����
				printf(" %2c |", (char)board[i][j]);
			}
			else
			{
				//������׵�λ�ã���1��ASCll��ֵ��ʾ
				printf("%2c |", (char)board[i][j]);
			}
		}

		//��ӡ���һ����Щ���⣬û������|
		if (board[i][col] == 0)
		{
			printf(" %2c ", (char)board[i][col]);
		}
		else
		{
			printf("%2c ", (char)board[i][col]);
		}
		printf("\n");

		//��ӡ��---��Ҫ�ȹ涨����һ��   
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


//ɨ��

//�׵ĸ���
int countMine(int mine[ROW1][COL1], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
}

//�ݹ�
void extend(char show[ROW1][COL1], int mine[ROW1][COL1], int x, int y)
{
	//�������Ϸ������еݹ�
	if (x > 0 && x <= ROW && y > 0 && y <= COL)
	{
		//����count�����ܱ�������ͳ��
		int count = countMine(mine, x, y);
		//����ܱ��׵ĸ�����0�����еݹ�
		if (count == 0)
		{
			//���ܱ�Ϊ0��������Ϊ�ո�
			show[x][y] = ' ';
			//���ܱ��������еݹ�չ��
			for (int i = x - 1; i <= x + 1; i++)
			{
				for (int j = y - 1; j <= y + 1; j++)
				{
					//����ܱ�������û�б�ɨ�裬�����չ��
					if (show[i][j] == '*')
					{
						extend(show, mine, i, j);
					}
				}
			}
		}
		//�������������show_board���̸�Ϊ�ַ�״̬�µ��ܱ�����
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
		printf("������ɨ������:>");
		scanf("%d %d", &x, &y);
		//�������Ϸ���û�б�ռ�ã����Ҳ����ף������չ����֪���ܱ�����
		if (x > 0 && x <= row && y > 0 && y <= col && mine[x][y] == 0 && show[x][y] == '*')
		{
			extend(show, mine, x, y);
			return 1;
		}
		else
		{
			//�������Ϸ��������ף��򷵻�0��ɨ��ʧ��
			if (x > 0 && x <= row && y > 0 && y <= col && mine[x][y] == 1)
			{

				return 0;
			}
			//���������������Ƿ�����������
			else
			{
				printf("���������������������\n");
			}
		}
	}


}
