#include"game1.h"
void menu()
{
	printf("*************************\n");
	printf("*******1. ��ʼ��Ϸ*******\n");
	printf("*******0. �˳���Ϸ*******\n");
	printf("*************************\n");
}
void game()
{
	char az = 0;
	char board[ROW][COL] = { 0 };//�����������
	chessboard(board, ROW, COL);//��ʼ������
	playchess(board, ROW, COL);//��������
	while (1)
	{
		playermove(board, ROW, COL);//�������
		playchess(board, ROW, COL);
		az = Iswin(board, ROW, COL);//�Ƿ�Ӯ��
		//*���Ӯ�� #����Ӯ��  Pƽ�� F����  C����
		if (az != 'C')//�жϼ������
		{
			break;
		}
		computermove(board, ROW, COL);
		playchess(board, ROW, COL);
		az = Iswin(board, ROW, COL);//�Ƿ�Ӯ��
		//*���Ӯ�� #����Ӯ��  Pƽ�� F����  C����
		if (az != 'C')//�жϼ������
		{
			break;
		}

	}
	if (az == '*')
	{
		printf("��Ӯ��\n");
	}
	else if (az == '#')
	{
		printf("������\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()//������
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//�˵�
		printf("������");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}