#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void reverse(char*left,char*right)//�ַ�����
//{
//	while (left < right)
//	{
//		char temp = 0;
//		temp=*left;
//		*left = *right;
//		*right = temp;
//		
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	int len = strlen(arr);//���������ַ��ĳ��ȣ���֪�������ַ���ʱ��
//	                         //��strlen
//	reverse(arr, arr + len - 1);
//	char* strck = arr;//ȷ����ʼλ��
//	while (*strck)
//	{
//		char* end = (arr);//��������ĩ��λ��
//		while (*end != ' ')
//		{
//			end++;
//		}
//		reverse(arr, end - 1);
//		if (*end = ' ')
//		{	
//			strck = end + 1;//�����ո����ʼλ��+1��
//		}
//		else
//			strck = end;//����\0��ʱ�� ����λһֱ������
//			
//		
//	}
//	return 0;
//}
int main()
{
	char a = 128;
	printf("%u\n", a);
	return 0;
}