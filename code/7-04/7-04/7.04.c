#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ϣ���㹹��һ������Ϊn�ġ�����'y'��'o'��'u'�����ַ���ɵ��ַ�������Ҫ��֤���ַ�������ǡ��
//k/*��"you"�Ӵ������ܰ������*/

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
	//С��1you 2   youyouyou 
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