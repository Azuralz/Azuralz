#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

////int main()
////{
////	int a = 0;
////	int b = 0;
////	scanf("%d %d", &a, &b);
////	if (a > b)
////		printf("���ֵ%d\n", a);
////	else
////		printf("���ֵ%d\n", b);
////
////
////
////	return 0;
////}
////int main() 
////{
////	int a = 0;
////	scanf("%d", &a);
////	a%5==0 ? printf("��") : printf("����");
////
////	return 0;
////
////}
////
////int main()
////{
////	int a = 0;
////	int b = 0;
////	int c = 0;
////	
////	
////	printf("����������:");
////	scanf("%d %d", &a, &b);
////
////	 c = a;
////	 a = b;
////	 b = c;
////	printf("a = %d, b = %d", a, b);
////
////	return 0;
////
////}
////
////#include <stdio.h>
//
////int main() {
////    int a = 0;
////    int b = 0;
////    int temp = 0; //����һ����ʱ����
////
////    printf("�����������֣�");
////    scanf("%d%d", &a, &b); //10  20
////
////    temp = a;
////    a = b;
////    b = temp;
////    printf("a = %d, b = %d\n", a, b);//20  10
////    return 0;
////}
////int main()
////{
////	int a = 0;
////	printf("�ж�һ�����Ƿ�Ϊ����");
////	scanf("%d", &a);
////	if (a%2 == 0) 
////	{
////		printf("��");
////	}
////
////
////
////	return 0;
//////}
////int main() {
////	int a = 0;
////	for (a = 1; a <= 100; a++)
////	{
////		if (a % 2 == 0)
////		{
////			printf(" ");
////		}
////		else
////		{
////			printf("%d", a);
////		}
////	}		
////	return 0;
////}
////23 34 3 5
////int main()
////{
////	int a = 1;
////	scanf("%d", &a);
////	switch ( a ) 
////	{
////	case 1:
////		printf("ɵ��\n");
////	case 2:
////		printf("ɵ��\n");
////		break;
////	case 3:
////		printf("����\n");
////		break;
////	}
////
////
////	return 0;
//
////}
//
////
////int main()
////{
////
////	int i = 1;
////	while (i <= 10, i++)
////	{
////		printf("%d", i);
////		
////	}
////	return 0;
////
////
////int main()
////{
////	printf("Happy new year!");
////}
//int main() 
//{
//	printf("������������1");
//
//
//}
//int main()
//{
//
//	int a = 0;
//	int b = 0;
//	printf("����1.  "); scanf("%d", &a);
//	printf("    2.  "); scanf("%d", &b);
//	
//		
//	
//
//
//	return 0;
//}
/*�򵥼���*/
//#include<stdio.h>
//int main()
//{
//    float a, b;
//    float h, c, j, s;
//    scanf("%f%f", &a, &b);
//    h = a + b;
//    c = a - b;
//    j = a * b;
//    s = a / b;
//    printf("��=%f,��=%f,��=%f,��=%f\n", h, c, j, s);
//}
#include <stdio.h>
#define MAX_ASCII 127

int main()
{
    char num, enter;
    int temp = 1;
    for (; temp > 0;)
    {
        printf("----------------------------\n");
        printf("|**      ��ʼ            **|\n");
        printf("|**ASCII  ת  �ַ�  ��:1 **|\n");
        printf("|**�ַ�   ת  ASCII ��:2 **|\n");
        printf("|**      ����       ��:0 **|\n");
        printf("----------------------------\n");
        scanf("%d", &temp);
        if (temp == 1)
        {
            printf("��������ֵС�� %d �������ַ���", MAX_ASCII);
            scanf("%d", &num);
            printf("ASCIIΪ %d ,��Ӧ���ַ�Ϊ %c \n", num, num);
        }
        if (temp == 2)
        {
            printf("����һ���ַ�: \n");
            scanf("%c", &enter);      //�س���Ҳ���ַ�,��������ʹ������������֮.
            scanf("%c", &num);
            printf("     %c �� ASCII Ϊ %d    \n", num, num);
        }
    }
    return 0;
}
//int main()
//{
//
//	return 0;
//}