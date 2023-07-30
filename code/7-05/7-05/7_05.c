#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int Add(int x, int y)
//{
//	return(x + y);
//	 
//}
//int main()
//{
//	int (*p)(int, int) = &Add;
//	int ret = (*p)(3, 5);
//	printf("%d", ret);
//	return 0;
//}
int Add(int x, int y)
{
	return x + y;
}
int sum(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("*****************************\n");
	printf("********1.加法 2.减法********\n");
	printf("********3.乘法 4.除法********\n");
	printf("*****************************\n");
}

//int main()
//{
//	int input = 0;
//	do {
//		menu();
//		int (*pfArr[5])(int, int) = { NULL,Add,sum,mul,div };
//		int x  = 0;
//		int y = 0;
//		int ret = 0;
//		printf("请输入：");
//		scanf("%d", &input);
//		printf("请输入数字：\n");
//		scanf("%d %d", &x, &y);
//		 ret = (pfArr[input])(x, y);
//		printf("%d\n", ret);
//	} while (input);
//		return 0;
//}
int* arr[5]//整型指针数组//
int* (*p3)[5] = &arr;//整型指针数组//
int arr[5];
int (*p3)[5] = &arr;//整型数组的指针
int (*p)(int , int);//函数指针
int (*p[5])(int, int);//函数指针数组
int (*(*p)[5])(int, int);