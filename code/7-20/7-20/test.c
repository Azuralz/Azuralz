#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/*
* ��ӡ�˵�
* 1 ��ʼ   0����
* ������ά����
* ��ʼ����ά����
* ������  һ�����̲��ã�һ�����̴�ӡ
* ��������ɨ��
*	������ף�����
*	��������ף���λ�ø�Ϊ�ܱ��׵ĸ���
*	ʣ�������ף���Ϸ�ɹ�
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
	//��������
	char show_board[ROW1][COL1] = { 0 };
	int mine_board[ROW1][COL1] = { 0 };
	//��ʼ������
	init(show_board, mine_board, ROW1, COL1);
	//��ӡ����
	printBoard(show_board, ROW, COL);
	//printBoard1(mine_board, ROW, COL);

	while (1)
	{
		//ɨ��
		int ret = searchMine(show_board, mine_board, ROW, COL);
		system("cls");

		//ɨ�׳ɹ�
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
			printf("ɨ�׳ɹ�\n");
			printBoard1(mine_board, ROW, COL);
			break;
		}

		//ɨ��ʧ��
		if (ret == 0)
		{
			printf("ɨ��ʧ�ܣ��㱻ը����!!!\n");
			printBoard1(mine_board, ROW, COL);
			break;
		}

		//��ӡ����
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
			printf("��ǰ���̹����%d���ף��ҳ�ȫ���׻�ʤ\n", MINE);
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);

	return 0;
}
