#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p = (int*)malloc(10 * sizeof(int*));
	if (p == NULL)
	{
		perror("main");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}