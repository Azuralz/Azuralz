#include "PhoneBook.h"
#define _CRT_SECURE_NO_WARNINGS 1
void menu()
{
	printf("******* ͨѶ¼ *************\n");
	printf("**1.������ϵ��2.ɾ����ϵ��**\n");
	printf("**3.������ϵ��4.�޸���ϵ��**\n");
	printf("**5.����ͨѶ¼6.�鿴ͨѶ¼**\n");
	printf("**********0.�˳�************\n");
}

int main()
{
	int input = 0;
	Contact con;//����ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			ADDContact(&con);
			break;
		case DELE:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			break;
		 default:
			 printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}