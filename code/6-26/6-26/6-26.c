#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()//��0-100�к���9������
//{
//	int n = 0;
//	int b = 0;
//	for (n = 1; n <= 100; n++)
//	{
//		if (n / 10 == 9 || n % 10 == 9 )
//		{
//			printf("%d ", n);
//			b++;
//		}
//	}
//	printf("\nb=%d", b);
//	return 0;
//}
//
//int fx2(int b)
//{
//	for (b = 2; b <= 100; b += 2)
//	{
//		return 1 /b;
//	}
//}
//int fx1(int a)
//{
//	for (a = 1; a <= 100; a += 2)
//	{
//		return 1 / a;
//	}
//}
//int main()
//{
//	int n = 0;
//	double c = 0;
//	for (n = 1; n <= 100; n++)
//	{
//		c += 1.0 / n;
//	}
//	printf("%lf", c);
//		
//	return 0;
//
//����1 / 1 - 2 / 1 + 3 / 1 - 4 / 1 + 1 / 5.......... + 1 / 99 - 1 / 100��ֵ��ӡ�����
//int main()
//{
//	int a = 0;
//	double b = 0;//С������
//	int c = 1;
//	for (a = 1; a <= 100; a++)
//	{
//		b += c * 1.0 / a;//1.0����Ϊb��������
//		c = -c;//һ��ѭ����������+-+-+-
//	}
//	printf("%lf", b);
//
//	return 0;
////}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = arr[0];
//	int n = 0;
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] > n)
//		{
//			n = arr[i];
//		}
//		
//	}
//	printf("%d", n);
//	return 0;
//}
//int Digitsum(int n)
//{
//	if (n > 9)
//	{
//		return Digitsum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int num = 1729;
//	int sum = Digitsum(num);
//	printf("%d", sum);
//
//
//	return 0;
//}
// 

//��n ��k �η�
//double azura(int a,int b)
//{	
//	if (b == 0)	
//		return 1.0;	
//	if (b > 0)
//		return a * azura(a, b - 1);
//	if (b < 0)
//		return 1.0 / (azura(a, -b));
//}
//int main()
//{
//	int arr[] = { 1,2,5,7,9 };
//	int* p = arr;
//	printf("%d", *p);
//	return 0;
//}
//��ά����
//int main()
//{        //���� ����
//	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };//��ֵ
//	//˳����ϵ��´����ҡ���
//	 {{1��2}��{2��3}��{4��5} }��
//}
void azura(int arr[], int sz)
{
	//ȷ������
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		//һ��ð�ݳ���Ĺ���
		int b = 0;
		for (b = 0; b <sz - 1-a   ; b++)
		{
			if (arr[b] > arr[b+1])
			{
				//����
				int c = arr[b];
				arr[b] = arr[b+1];
				arr[b+1] = c;
			}	
		}	
	}
}
int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	azura(arr, sz);

	int d = 0;
	for (d = 0; d < 10; d++)
	{
		printf("%d", arr[d]);
	}
	return 0;
}