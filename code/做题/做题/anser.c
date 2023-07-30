#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	float principal = 1000;
//	float part1 = 1003.6;
//	float part2 = 0.0225;
//	float part3 = 0.0198;
//	float ppart1 = (1.0 + part1) * principal;
//	float ppart2 = (1.0 + part2) * principal;
//	float ppart3 = (1.0 + part3) * principal;
//	printf("第一种活期一年为 %f\n", ppart1 );
//	printf("第二种定期一年为 %f\n", ppart2);
//	printf("%f", part1);
//	
//}

//#include<stdio.h>//头文件
//int main() //主函数
//{
//    float interest_Rate1, interest_Rate2, interest_Rate3;//定义浮点型利率变量
//    interest_Rate1 = 0.0036; //初始化第一种方式年利率
//    interest_Rate2 = 0.0225; //初始化第二种方式年利率
//    interest_Rate3 = 0.0198; //初始化第三种方式年利率
//
//    float principal_0, principal_1, principal_2, principal_3;//定义变量
//    principal_0 = 1000;//初始化本金
//
//    principal_1 = principal_0 * (1 + interest_Rate1);//第一种本息和
//    principal_2 = principal_0 * (1 + interest_Rate2);//第二种本息和
//    principal_3 = principal_0 * (1 + interest_Rate3 / 2) * (1 + interest_Rate3 / 2);//第三种本息和
//
//    printf("第一种本息和：%f\n", principal_1);//输出第一种本息和
//    printf("第二种本息和：%f\n", principal_2);//输出第二本息和
//    printf("第三种本息和：%f\n", principal_3);//输出第三种本息和
//
//    return 0; //函数返回值为0
//}
//int main()
//{
//	char a = 0;
//	scanf("%c", &a);
//	printf("%c", (a + 32));
//}


//int main()
//{
//	char a = 'L';
//	char b = 'O';
//	char c = 'V';
//	char d = 'E';
//	printf("%c", a);
//	printf("%c", b);
//	printf("%c", c);
//	printf("%c", d);
//	printf("\n");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	while (a > b)
//	{
//		a = a + b;
//		b = a - b;
//		a = a - b;
//	}
//	printf("从小到大依次是%d %d", a, b);
//	return 0;
//} 
//int main()
//{
//	char a, b;
//	scanf("%c", &a);
//	 ;
//	b = ('A' <=a && a <='Z') ? ( a + 32) : a;
//	printf("%c", b );
//	return 0;
//}
//#include<stdio.h>//头文件
//int main()//主函数
//{
//	char character_Big, character_Small;//定义字符变量
//	printf("请输入字母：");
//	scanf("%c", &character_Big);//键盘输入字符
//	character_Big >= 'A' && character_Big <= 'Z') ? (character_Big + 32) : character_Big;
//	printf("%c\n", character_Small);//输出
//	return 0;//函数返回值为0
//}
//#include<stdio.h>//头文件
//int main()//主函数
//{
//    char grade; //定义成绩级别字符变量
//    printf("输入成绩级别：");//提示语句
//    scanf("%c", &grade); //键盘输入
//    printf("成绩段：");//提示语句
//    switch (grade) //switch多分支
//    {
//    case'A':printf("85-100\n"); break;//输出A的成绩分布
//    case'B':printf("70-84\n"); break;//输出B的成绩分布
//    case'C':printf("60-69\n"); break;//输出C的成绩分布
//    case'D':printf("不及格小于60\n"); break;//输出D的成绩分布
//    default:printf("输入成绩等级有误\n");//输出成绩级别有误
//    }
//    return 0;//函数返回值为0
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
	/*for (a = 1; a <= 100; a++)
	{
		b = b + a;
	}
	printf("%d", b);*/
	/*while (a<=100)
	{
		b = a + b;
		a++;
	}
	printf("%d", b);*/
	/*do
	{
		b = b + a;
		a++;
	} while (a <= 100);
	printf("%d", b);
	return 0;*/
//int main()
//{
//	int n_man;
//	float money,money1;
//	float avg;
//	for (n_man = 0, money = 0; money <= 100000; n_man++)
//	{
//		printf("请输入捐款数: ");
//		scanf("%f", &money1);
//		money = money + money1;
//		
//	}
//	avg = money / n_man;
//	printf("总共 %d 人捐到10w，平均捐款为 %f", n_man, avg);
//	return 0;
//}
#include<stdio.h>//头文件
int main()//主函数
{
	float amount, aver, total;//定义浮点型变量
	float sum = 100000; //定义浮点型变量且赋初值
	int i;//定义整型变量
	for (i = 1, total = 0; i < 1001; i++)//循环条件
	{
		printf("请依次输入捐款钱数：");//提示语句
		scanf("%f", &amount); //键盘输入
		total = total + amount;
		if (total > sum)
			break;//跳出循环
	}
	aver = total / i;
	printf("第%d个人捐款之后达到10万+\n平均每人捐款：%5.2f\n", i, aver);
	return 0;//函数返回值为0
}