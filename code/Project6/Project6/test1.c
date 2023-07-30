#include"game1.h"
void menu()
{
	printf("*************************\n");
	printf("*******1. 开始游戏*******\n");
	printf("*******0. 退出游戏*******\n");
	printf("*************************\n");
}
void game()
{
	char az = 0;
	char board[ROW][COL] = { 0 };//存数据下棋的
	chessboard(board, ROW, COL);//初始化棋盘
	playchess(board, ROW, COL);//生成棋盘
	while (1)
	{
		playermove(board, ROW, COL);//玩家下棋
		playchess(board, ROW, COL);
		az = Iswin(board, ROW, COL);//是否赢了
		//*玩家赢了 #电脑赢了  P平局 F满了  C继续
		if (az != 'C')//判断继续与否
		{
			break;
		}
		computermove(board, ROW, COL);
		playchess(board, ROW, COL);
		az = Iswin(board, ROW, COL);//是否赢了
		//*玩家赢了 #电脑赢了  P平局 F满了  C继续
		if (az != 'C')//判断继续与否
		{
			break;
		}

	}
	if (az == '*')
	{
		printf("你赢了\n");
	}
	else if (az == '#')
	{
		printf("你输了\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()//主界面
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//菜单
		printf("请输入");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}