//����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

//����ֵ
#define MAXSIZE 1000
#define OVERFLOW 0

typedef struct//�ڵ���������
{
	float a;
	int e;
}Polynomial;

typedef struct//����ṹ����
{
	Polynomial* elen;
	int length;
}SqList;


void InitList(SqList*L)//��ʼ�����Ա�
{
	L->elen = malloc(MAXSIZE * sizeof(Polynomial));//Ϊ���Ա��ٿռ�
	if (L->elen)//����ʧ��
	{
		perror("����");
		exit(OVERFLOW);
	}
	L->length = 0;//������Ϊ0
}
void DestroyList(SqList*L)
{

}

int main()
{
	SqList a ;
	InitList(&a);
	return 0;
}