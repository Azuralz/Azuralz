#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
////void math_1(int n,int conut)
////{
////	while (n / 3 != 0)
////	{
////		conut = conut + (n / 3);
////		n = n / 3 + n % 3;
////	}
////	if (n % 3 == 2)
////	{
////		conut = conut + 1;
////	}
////	printf("%d\n", conut);
////}
////int main()
////{
////	int n = 0;
////	int conut = 0;
////	do
////	{
////		scanf("%d", &n);
////		switch (n)
////		{
////		case 0:
////			break;
////		default:
////			math_1(n,conut);
////			break;
////		}
////	} while (n);
////	return 0;
////}
////明明生成了
////�
////N个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。
////
////数据范围：
////
////1≤n≤1000  ，输入的数字大小满
////1≤val≤500
////void shuchu(int arr[], int c)
////{
////
////}
//
//
//	
////void shuchu(int arr[], int SZ)
////{
////	int a = 0;
////	int min;
////	for(a=0;a<SZ;a++)
////	{
////		int b = 0;
////		for (b = 0; b < SZ; b++)
////		{
////			if (arr[a] > arr[b])
////			{
////				arr[a] = arr[b] + arr[a];
////				arr[b] = arr[a] - arr[b];
////				arr[a] = arr[a] - arr[b];
////			}
////			
////		}
////		printf("%d", arr[a]);
////	}
////}
////void shuchu(int arr[], int n)
////{
////	int a = 0;
////	for (a = 0; a < n - 1; a)
////	{
////
////	}
////}
////int main()
////{
////	int n = 0;
////	scanf("%d", &n);
////	int arr[] = { 0 };
////	int c = 0;
////	for(c=0;c<n;c++)
////	{	
////		int val = 0;
////		scanf("%d", &val);
////	      arr[c] = val;
////		
////					
////	}
////	/*shuchu(arr, n);*/
////	return 0;
//}

////int main()
////{
////	int n = 0;
////	int arr = 0;
////
////	return 0;
////}
//#include<stdio.h>
//
//void sort_arr(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        int j = 0;
//        for (j = 0; j < sz - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    int num;
//    while (scanf("%d", &n) != EOF)
//    {
//        int* arr = (int*)malloc(n * sizeof(int));
//        for (int i = 0; i < n; i++)
//        {
//            scanf("%d", &num);
//            arr[i] = num;
//        }
//        sort_arr(arr, n);
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                if (arr[i] == 0)
//                {
//                    break;
//                }
//                else if (arr[i] == arr[j])
//                {
//                    arr[j] = 0;
//                }
//                else if (arr[j] > arr[i])
//                {
//                    break;
//                }
//            }
//        }
//
//        for (int i = 0; i < n; i++)
//        {
//            if (arr[i] != 0)
//            {
//                printf("%d\n", arr[i]);
//            }
//        }
//        free(arr);
//    }
//}

void outandpf(int ARR[], int n)
{
	
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n)
	{
		int arr[1000] = { 0 };
		int a = 0;
		int val;
		for (a = 0; a < n; a++)
		{
			scanf("%d", &val);
			arr[a] = val;
		}
		for (a = 0; a < n - 1; a++)
		{
			int j = 0;
			for (j = 0; j < n - a - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int tem = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tem;
						
				}
				else if (arr[j] = arr[j + 1])
				{
					arr[j] = 0;
				}
					
				
			}
		}
		
	}
		return 0;
}
//#include <stdlib.h> //不知道是什么意思
//#include <stdio.h>
//#include <string.h> //数组

//int main()
//{
//    int n; //规定输入数的个数
//
//    int a;
//
//    //以数组下标来存储随机数，下标对应的数组值为1，来说明是否是存储的随机数
//    while (~scanf("%d", &n)) //如果输入的n不为0，那么就执行括号内的内容
//    {
//        int count[1001] = { 0 }; //初始化
//        int i;                    //规定一个i
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d", &a);
//            count[a] = 1;                //此时数组中以a为下标的那个值就为1
//        }
//        for (i = 0; i < 1001; i++)
//        {
//            if (count[i] == 1)            /*如果数组以i为下标的那个值为1，那么就将它输出，也就是说，按照从小到大的次序依次输出曾经有过输入的下标。很绝*/
//            {
//                printf("%d\n", i);
//            }
//        }
//    }
//
//    return 0;
//}