#include "PhoneBook.h"
#define _CRT_SECURE_NO_WARNINGS 1



//void InitContact(Contact* pc)//��ʼ��ͨѶ¼ ��̬
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
void InitContact(Contact* pc)//��ʼ��ͨѶ¼ ��̬
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

void LoadContact(Contact* pc)//���������ļ�
{
	FILE* p = fopen("Contact.dat", "r");
	if (p == NULL)
	{
		perror("fopen");
		return;
	}
	PepInfor num = { 0 };
	while (fread(&num, sizeof(PepInfor), 1, p))//����ȡ������fread���ص���o��Ϊÿ�ζ�ȡ1������
	{
		Checkcapacity(pc);//��������
		pc->data[pc->sz] = num;
		pc->sz++;
	}
	fclose(p);
	p == NULL;
}
//void ADDContact(Contact* pc)//������Ŀ��̬�汾
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼����\n");
//		return;
//	}
//	else
//	{
//		printf("���������֣�");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("���������䣺");
//		scanf("%d", &(pc->data[pc->sz].age));
//		printf("�������Ա�");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("������绰���룺");
//		scanf("%s", pc->data[pc->sz].tel);
//		printf("�������ַ��");
//		scanf("%s", pc->data[pc->sz].addr);
//		pc->sz++;
//		printf("��ӳɹ�\n");
//	}
//}
void Checkcapacity(Contact* pc)//��������Ƿ�����
{
	if (pc->sz == pc->capacity)
	{
		PepInfor* ptr = (PepInfor*)realloc(pc->data, (pc->capacity + Increas) * sizeof(PepInfor));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += Increas;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("ADD");
			printf("����ʧ��\n");
			return;
		}
	}
}
void ADDContact(Contact* pc)//������Ŀ��̬�汾
{
	Checkcapacity(pc);//������������
		printf("���������֣�");
		scanf("%s", pc->data[pc->sz].name);
		printf("���������䣺");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�������Ա�");
		scanf("%s", pc->data[pc->sz].sex);
		printf("������绰���룺");
		scanf("%s", pc->data[pc->sz].tel);
		printf("�������ַ��");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("��ӳɹ�\n");
}

void PrintContact(const Contact* pc)//��ӡͨѶ¼
{
	int i = 0;
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-10s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tel, pc->data[i].addr);
	}
}
int Findbyname(Contact* pc, char name[])//��������
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
void DelContact(Contact* pc)//ɾ����Ŀ
{
	char name[Max_name] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
	}
	printf("��������Ҫɾ�������֣�");
	scanf("%s", name);
	int tem = Findbyname(pc, name);
	if (tem == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	int i = 0;
	for (i = tem; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(Contact* pc)//����ͨѶ¼
{
	char name[Max_name] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	printf("��������Ҫ���ҵ����֣�");
	scanf("%s", name);
	int tem = Findbyname(pc, name);
	if (tem == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-15s\t%-5d\t%-5s\t%-12s\t%-10s\n", pc->data[tem].name, pc->data[tem].age, pc->data[tem].sex, pc->data[tem].tel, pc->data[tem].addr);

}
void ModifyContact(Contact* pc)//�޸�ͨѶ¼
{
	char name[Max_name] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	printf("��������Ҫ�޸ĵ����֣�");
	scanf("%s", name);
	int tem = Findbyname(pc, name);
	if (tem == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("���������֣�");
	scanf("%s", pc->data[tem].name);
	printf("���������䣺");
	scanf("%d", &(pc->data[tem].age));
	printf("�������Ա�");
	scanf("%s", pc->data[tem].sex);
	printf("������绰���룺");
	scanf("%s", pc->data[tem].tel);
	printf("�������ַ��");
	scanf("%s", pc->data[tem].addr);
	printf("�޸ĳɹ�\n");
}

void SortContact(Contact* pc)//����
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

void DestroyContact(Contact* pc)//�����ڴ� 
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void WriteData(Contact* pc)//��������
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