#include "PhoneBook.h"
#define _CRT_SECURE_NO_WARNINGS 1



//void InitContact(Contact* pc)//初始化通讯录 静态
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
void InitContact(Contact* pc)//初始化通讯录 动态
{
	pc->data = (PepInfor*)malloc(Defult * sizeof(PepInfor));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = Increas;
	LoadContact(pc);
}

void LoadContact(Contact* pc)//加载数据文件
{
	FILE* p = fopen("Contact.dat", "r");
	if (p == NULL)
	{
		perror("fopen");
		return;
	}
	PepInfor num = { 0 };
	while (fread(&num, sizeof(PepInfor), 1, p))//当读取结束是fread返回的是o因为每次读取1个数据
	{
		Checkcapacity(pc);//考虑增容
		pc->data[pc->sz] = num;
		pc->sz++;
	}
	fclose(p);
	p == NULL;
}
//void ADDContact(Contact* pc)//增加项目静态版本
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满\n");
//		return;
//	}
//	else
//	{
//		printf("请输入名字：");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入年龄：");
//		scanf("%d", &(pc->data[pc->sz].age));
//		printf("请输入性别：");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("请输入电话号码：");
//		scanf("%s", pc->data[pc->sz].tel);
//		printf("请输入地址：");
//		scanf("%s", pc->data[pc->sz].addr);
//		pc->sz++;
//		printf("添加成功\n");
//	}
//}
void Checkcapacity(Contact* pc)//检查容量是否增容
{
	if (pc->sz == pc->capacity)
	{
		PepInfor* ptr = (PepInfor*)realloc(pc->data, (pc->capacity + Increas) * sizeof(PepInfor));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += Increas;
			printf("增容成功\n");
		}
		else
		{
			perror("ADD");
			printf("增加失败\n");
			return;
		}
	}
}
void ADDContact(Contact* pc)//增加项目动态版本
{
	Checkcapacity(pc);//考虑增容问题
		printf("请输入名字：");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄：");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别：");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话号码：");
		scanf("%s", pc->data[pc->sz].tel);
		printf("请输入地址：");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("添加成功\n");
}

void PrintContact(const Contact* pc)//打印通讯录
{
	int i = 0;
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-10s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-10s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tel, pc->data[i].addr);
	}
}
int Findbyname(Contact* pc, char name[])//姓名查找
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)//删除项目
{
	char name[Max_name] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
	}
	printf("请输入需要删除的名字：");
	scanf("%s", name);
	int tem = Findbyname(pc, name);
	if (tem == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	for (i = tem; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(Contact* pc)//搜索通讯录
{
	char name[Max_name] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
	}
	printf("请输入需要查找的名字：");
	scanf("%s", name);
	int tem = Findbyname(pc, name);
	if (tem == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-10s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-15s\t%-5d\t%-5s\t%-12s\t%-10s\n", pc->data[tem].name, pc->data[tem].age, pc->data[tem].sex, pc->data[tem].tel, pc->data[tem].addr);

}
void ModifyContact(Contact* pc)//修改通讯录
{
	char name[Max_name] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
	}
	printf("请输入需要修改的名字：");
	scanf("%s", name);
	int tem = Findbyname(pc, name);
	if (tem == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[tem].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[tem].age));
	printf("请输入性别：");
	scanf("%s", pc->data[tem].sex);
	printf("请输入电话号码：");
	scanf("%s", pc->data[tem].tel);
	printf("请输入地址：");
	scanf("%s", pc->data[tem].addr);
	printf("修改成功\n");
}

void SortContact(Contact* pc)//排序
{
	for (int i = 0; i < pc->sz ; i++)
	{
		for (int j = 0; j < pc->sz - i-1; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PepInfor tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
			}
		}
	}
}

void DestroyContact(Contact* pc)//销毁内存 
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void WriteData(Contact* pc)//保存数据
{
	FILE* p = fopen("Contact.dat", "w");
	if (p == NULL)
	{
		perror("WriteData");
		return;
	}
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PepInfor), 1, p);
	}
	fclose(p);
	p = NULL;
}