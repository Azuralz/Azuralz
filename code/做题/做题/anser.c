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
//	printf("��һ�ֻ���һ��Ϊ %f\n", ppart1 );
//	printf("�ڶ��ֶ���һ��Ϊ %f\n", ppart2);
//	printf("%f", part1);
//	
//}

//#include<stdio.h>//ͷ�ļ�
//int main() //������
//{
//    float interest_Rate1, interest_Rate2, interest_Rate3;//���帡�������ʱ���
//    interest_Rate1 = 0.0036; //��ʼ����һ�ַ�ʽ������
//    interest_Rate2 = 0.0225; //��ʼ���ڶ��ַ�ʽ������
//    interest_Rate3 = 0.0198; //��ʼ�������ַ�ʽ������
//
//    float principal_0, principal_1, principal_2, principal_3;//�������
//    principal_0 = 1000;//��ʼ������
//
//    principal_1 = principal_0 * (1 + interest_Rate1);//��һ�ֱ�Ϣ��
//    principal_2 = principal_0 * (1 + interest_Rate2);//�ڶ��ֱ�Ϣ��
//    principal_3 = principal_0 * (1 + interest_Rate3 / 2) * (1 + interest_Rate3 / 2);//�����ֱ�Ϣ��
//
//    printf("��һ�ֱ�Ϣ�ͣ�%f\n", principal_1);//�����һ�ֱ�Ϣ��
//    printf("�ڶ��ֱ�Ϣ�ͣ�%f\n", principal_2);//����ڶ���Ϣ��
//    printf("�����ֱ�Ϣ�ͣ�%f\n", principal_3);//��������ֱ�Ϣ��
//
//    return 0; //��������ֵΪ0
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
//	printf("��С����������%d %d", a, b);
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
//#include<stdio.h>//ͷ�ļ�
//int main()//������
//{
//	char character_Big, character_Small;//�����ַ�����
//	printf("��������ĸ��");
//	scanf("%c", &character_Big);//���������ַ�
//	character_Big >= 'A' && character_Big <= 'Z') ? (character_Big + 32) : character_Big;
//	printf("%c\n", character_Small);//���
//	return 0;//��������ֵΪ0
//}
//#include<stdio.h>//ͷ�ļ�
//int main()//������
//{
//    char grade; //����ɼ������ַ�����
//    printf("����ɼ�����");//��ʾ���
//    scanf("%c", &grade); //��������
//    printf("�ɼ��Σ�");//��ʾ���
//    switch (grade) //switch���֧
//    {
//    case'A':printf("85-100\n"); break;//���A�ĳɼ��ֲ�
//    case'B':printf("70-84\n"); break;//���B�ĳɼ��ֲ�
//    case'C':printf("60-69\n"); break;//���C�ĳɼ��ֲ�
//    case'D':printf("������С��60\n"); break;//���D�ĳɼ��ֲ�
//    default:printf("����ɼ��ȼ�����\n");//����ɼ���������
//    }
//    return 0;//��������ֵΪ0
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
//		printf("����������: ");
//		scanf("%f", &money1);
//		money = money + money1;
//		
//	}
//	avg = money / n_man;
//	printf("�ܹ� %d �˾赽10w��ƽ�����Ϊ %f", n_man, avg);
//	return 0;
//}
#include<stdio.h>//ͷ�ļ�
int main()//������
{
	float amount, aver, total;//���帡���ͱ���
	float sum = 100000; //���帡���ͱ����Ҹ���ֵ
	int i;//�������ͱ���
	for (i = 1, total = 0; i < 1001; i++)//ѭ������
	{
		printf("������������Ǯ����");//��ʾ���
		scanf("%f", &amount); //��������
		total = total + amount;
		if (total > sum)
			break;//����ѭ��
	}
	aver = total / i;
	printf("��%d���˾��֮��ﵽ10��+\nƽ��ÿ�˾�%5.2f\n", i, aver);
	return 0;//��������ֵΪ0
}