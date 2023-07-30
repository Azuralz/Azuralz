#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 2;
	int b = 3;
	int c = a;
	a = b;
	b = c;
	printf("%d %d", a, b);
	return 0;
}