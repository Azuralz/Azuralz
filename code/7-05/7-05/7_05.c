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
	printf("********1.�ӷ� 2.����********\n");
	printf("********3.�˷� 4.����********\n");
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
//		printf("�����룺");
//		scanf("%d", &input);
//		printf("���������֣�\n");
//		scanf("%d %d", &x, &y);
//		 ret = (pfArr[input])(x, y);
//		printf("%d\n", ret);
//	} while (input);
//		return 0;
//}
int* arr[5]//����ָ������//
int* (*p3)[5] = &arr;//����ָ������//
int arr[5];
int (*p3)[5] = &arr;//���������ָ��
int (*p)(int , int);//����ָ��
int (*p[5])(int, int);//����ָ������
int (*(*p)[5])(int, int);