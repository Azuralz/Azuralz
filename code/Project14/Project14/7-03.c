#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	float a = 5.62;
//	//0 100 0000   101100111101011100001010
//	//101.1        101100111101011100001010               00111101011100001010001111011
//	printf("%f", a);
//	return 0;
//}


//int main()
//{
//	char arr[] = "hello z";
//	printf("%s", arr);
//	return 0;
//}
//int main()
//{
//	////int* arr[3];//指针数组
//	//int a[5] = { 1,2,3,4,5, };
//	//int b[] = { 1,3,5,6, };
//	//int c[] = { 1,35,6,7 };
//	//int* arr[3] = { a,b,c };
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	int j = 0;
//	//	for (j = 0; j < 5; j++)
//	//	{
//	//		printf("%d", *(arr[i] + j));
//	//	}
//	//	printf("\n");
//	//}
//	return 0;
//}
/*//这时候pd为数组指针指向指针数组d；
double* d[5];
double* (*pd)[5] = &d;*/
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *((*pa)+ i));//*pa=arr 都是地址；
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5,},{1,3,4,5,7},{4,6,8,9,1} };
//	int(*pa)[3][5] = &arr;
//	printf("%d ", *(pa));
//
//	return 0;
//}
void print1(int(* pa)[5], int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		printf("%d", *((*pa) + i));
	}
}
int main()
{
	int arr[5] = {1,2,3,4,5};
	print1(arr, 5);
	return 0;
}