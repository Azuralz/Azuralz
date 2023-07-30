#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

////int main()
////{
////	int a = 0;
////	int b = 0;
////	scanf("%d %d", &a, &b);
////	if (a > b)
////		printf("最大值%d\n", a);
////	else
////		printf("最大值%d\n", b);
////
////
////
////	return 0;
////}
////int main() 
////{
////	int a = 0;
////	scanf("%d", &a);
////	a%5==0 ? printf("能") : printf("不能");
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
////	printf("输入两个数:");
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
////    int temp = 0; //定义一个临时变量
////
////    printf("输入两个数字：");
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
////	printf("判断一个数是否为奇数");
////	scanf("%d", &a);
////	if (a%2 == 0) 
////	{
////		printf("否");
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
////		printf("傻逼\n");
////	case 2:
////		printf("傻逼\n");
////		break;
////	case 3:
////		printf("你是\n");
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
//	printf("输入两个数字1");
//
//
//}
//int main()
//{
//
//	int a = 0;
//	int b = 0;
//	printf("输入1.  "); scanf("%d", &a);
//	printf("    2.  "); scanf("%d", &b);
//	
//		
//	
//
//
//	return 0;
//}
/*简单计算*/
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
//    printf("和=%f,差=%f,积=%f,商=%f\n", h, c, j, s);
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
        printf("|**      开始            **|\n");
        printf("|**ASCII  转  字符  按:1 **|\n");
        printf("|**字符   转  ASCII 按:2 **|\n");
        printf("|**      结束       按:0 **|\n");
        printf("----------------------------\n");
        scanf("%d", &temp);
        if (temp == 1)
        {
            printf("请输入数值小于 %d 的任意字符：", MAX_ASCII);
            scanf("%d", &num);
            printf("ASCII为 %d ,对应的字符为 %c \n", num, num);
        }
        if (temp == 2)
        {
            printf("输入一个字符: \n");
            scanf("%c", &enter);      //回车键也算字符,所以这里使用其他变量替之.
            scanf("%c", &num);
            printf("     %c 的 ASCII 为 %d    \n", num, num);
        }
    }
    return 0;
}
//int main()
//{
//
//	return 0;
//}