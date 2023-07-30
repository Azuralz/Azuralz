#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = 0;
//	for (a = 1; a <= 10; a++)
//	{
//		b *= a;
//		c += b;
//
//	}
//	
//	printf("%d %d", b, c);
//	return 0;
//}
#include <windows.h>
#include <string.h>
//int main()
//{
//	char arr1[] = "I LOVE YOU XU MING";
//	char arr2[] = "##################";
//	int left = 0;
//
//	while (left<=strlen(arr1))
//	{
//		arr2[left] = arr1[left];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//	}
//	printf("I LOVE YOU XU MING");
//	return 0;
//}
//int main()
//{
//	char password[20] = { 0 };
//	int n = 0;
//	for (n = 0; n < 3; n++)
//	{
//		printf("请输入密码\n");
//		scanf("%s", password);
//		if (strcmp(password, "12345678") == 0)
//		{
//			printf("登录成功\n");
//			break;
//
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (n == 3) {
//		printf("三次错误已锁定\n");
//	}
//	
//		return 0;
//}


void menu()
{
	printf("*************************************\n");
	printf("********       1.play       *********\n");
	printf("********       0.exit       *********\n");
	printf("*************************************\n");
	printf("*************************************\n");
}
#include <stdlib.h>
#include<time.h>
//void game()
//{
//	int shuru = 0;
//	int suiji = rand() % 100 + 1;
//	/*printf("%d\n", suiji);*/
//	while (1)
//	{
//		
//		printf("请输入数字\n");
//		scanf("%d", &shuru);
//		if (shuru < suiji)
//		{
//			printf("小了\n");
//		}
//		else if (shuru > suiji)
//		{
//			printf("打了\n");
//		}
//		else
//		{
//			printf("恭喜你猜对了！");
//		}
//
//	}
//
//}
//
//
//int main()
//{
//	int n = 0;
//	srand((unsigned int)time(NULL));
//
//	do 
//	{
//		menu();
//		printf("请输入！\n");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("输入错误请重新输入\n");
//			break;
//		}
//	} while (n);
//		return 0;
//}
//int main()
//{
//	printf("%s");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	
//	return 0;
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y += 4)
//	{
//		if (y % 100 == 0 && y % 400 != 0)
//		{
//
//		}
//		else
//		{
//			printf("%d ", y);
//		}
//		
//	}
//	return 0;
//}
int main()
{
	int a = 0;
	int b = 0;

	printf("华氏度\n");
	scanf("%d", a);
	b = 32 + a *1.8
	return 0;
}