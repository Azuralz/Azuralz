#include "PhoneBook.h"
#define _CRT_SECURE_NO_WARNINGS 1
void menu()
{
	printf("******* 通讯录 *************\n");
	printf("**1.增加联系人2.删除联系人**\n");
	printf("**3.查找联系人4.修改联系人**\n");
	printf("**5.排序通讯录6.查看通讯录**\n");
	printf("**********0.退出************\n");
}

int main()
{
	int input = 0;
	Contact con;//创建通讯录
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择->");
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
			 printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}