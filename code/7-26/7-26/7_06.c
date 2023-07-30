#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()
{
	printf("\n************* 菜单 ************\n");
	printf("**********1.加法 2.减法********\n");
	printf("**********3.乘法 4.除法********\n");
	printf("*************************0.退出\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sum(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
//{
//	int input = 0;
//	do
//	{
//		int x = 0;
//		int y = 0;
//		int ret = 0;
//		int(*pa[5])(int, int) = { NULL,Add,Sum,Mul,Div };
//		menu();
//		printf("请输入：");
//		scanf("%d", &input);
//		printf("请输入两个数；");
//		scanf("%d %d", &x, &y);
//		ret = pa[input]( x, y);
//		printf("%d\n", ret);
//		
//	} while (input);
//	return 0;
//}
int corrras(int (*pa)(int x, int y))
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
}
int main()
{
	int input = 0;
	int ret = 0;
	menu();
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		ret = corras(Add);
		break;
		printf("%d", ret);
	case 2:
		ret = corrras(Sum);
		printf("%d", ret);
		break;
	case 3:
		ret = corras(Mul);
		printf("%d", ret);
		break;
	case 4:
		ret = corrras(Div);
		printf("%d", ret);
		break;
	}

}

