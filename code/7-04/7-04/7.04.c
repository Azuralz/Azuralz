#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//游游希望你构造一个长度为n的、仅由'y'、'o'、'u'三种字符组成的字符串，需要保证该字符串包含恰好
//k/*个"you"子串。你能帮帮她吗*/

int main()
{
	char arr[1000] = {0};
	int n;
	int k;
	scanf("%d %d", &n, &k);
	int lon = 0;
	for (lon = 0; lon < n; )
	{
		arr[lon] = 'y';
		arr[lon + 1] = 'u';
		arr[lon + 2] = 'o';
		lon += 3;
		
	}
	//小于1you 2   youyouyou 
	int j = 0;  /*012345678*/
	for (j = 0; j < (k * 3); )
	{
		arr[j] = 'y';
		arr[j + 1] = 'o';
		arr[j + 2] = 'u';
		j += 3;
	}
	printf("%s", &arr);
	
	return 0;
}