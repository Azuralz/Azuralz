#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//get_max(int x,int y)
//{
//	if (x >= y)
//	{
//		return x;
//}
//	else
//	{
//		return y;
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int max = get_max(a, b);
//	printf("%d", max);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	*pa = 20;
//	printf("%d", a);
//	return 0;
//}
//void jiaohuan(int* na, int* nb)
//{
//	int z = 0;
//	z = *na;
//	*na = *nb;
//	*nb = z;
//		
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	jiaohuan(&a, &b);
//	printf("%d%d", a, b);
//	return 0;
//}
//int runnian(int x)
//{
//	if (x % 4 == 0 && x % 100 != 0 ||x % 400 == 0 )
//	{
//		return 1;
//	}
//		return 0;	
//}
//int main()
//{
//	int b = 0;
//	int a = 0;
//	for (a = 1000; a <= 2000; a++)
//	{
//		if (runnian(a) == 1)
//		{
//			b++;
//			printf("%d", a);
//		}
//	}
//	printf("\n个数%d", b);
//	return 0;
//}
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int sum = 12345;
//	/*scanf("%u", &sum);*/
//	print(sum);
//	return 0;
//}
////int main()
//{
//
//	return 0;
//}
//int runyear(int b)
//{
//	return b % 4 == 0 && b % 100 != 0 || b % 400 == 0 ? 1 : 0;
//
//}
//int main()
//{
//
//	int year = 0;
//	scanf("%d", &year);
//	if (runyear(year) == 1)
//	{
//		printf("%d是闰年\n", year);
//	}
//	else
//	{
//		printf("%d不是闰年\n", year);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d%d", b, a);
//	return 0;
//}
void m_table(int x)
{
	int y = 0;
	for (y = 1; y <= x; y++)
	{
		int z = 0;
		for (z = 1; z <= y; z++)
		{
			printf("%d*%d=%d ", z, y, (z * y));
		}
		printf("\n");
	}
}
int main()
{
	int a = 10;
	/*printf("%d的乘法口诀表\n", a);*/
	/*scanf("%d", &a);*/
	m_table(a);

	return 0;
} 