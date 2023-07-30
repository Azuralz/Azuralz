#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int sco = 0;
//	int sum = 0;
//	int i = 0;
//	int max = 0;
//	int min = 100;
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &sco);
//		sum += sco;
//		if (sco > max)
//		{
//			max = sco;
//		}
//			
//		if (sco < min)
//		{
//			min = sco;
//		}
//			
//	}
//	printf("%.2f\n", (sum - max - min)/5.0);
//	return 0;
//}
int mian()
{
	int y = 0;
	int m = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d %d", &y, &m) != EOF)
	{
		int day = days[m];
		if (m == 2)
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
				day += 1;
		printf("%d", day);
	}

	return 0;
}