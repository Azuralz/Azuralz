#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void reverse(char*left,char*right)//字符逆序；
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
//	int len = strlen(arr);//计算输入字符的长度，不知道输入字符的时候
//	                         //用strlen
//	reverse(arr, arr + len - 1);
//	char* strck = arr;//确认起始位置
//	while (*strck)
//	{
//		char* end = (arr);//创建逆序末端位置
//		while (*end != ' ')
//		{
//			end++;
//		}
//		reverse(arr, end - 1);
//		if (*end = ' ')
//		{	
//			strck = end + 1;//遇到空格后起始位置+1，
//		}
//		else
//			strck = end;//碰到\0的时候 就首位一直结束；
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