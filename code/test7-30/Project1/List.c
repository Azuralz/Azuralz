#include <stdlib.h>
#define MaxSize 100

typedef struct //�������ݽṹ���� 
{
	float a; //ϵ��
	int e;  //ָ��
}Polynomial;

typedef struct //�����洢�ṹ����
{
	Polynomial* elem; //ָ��ĳ�����ݵ�ָ��
	int length; //���ݵĳ���
}Splist;

void InitList(Splist* L)
{
	L->elem = (Splist*)malloc(sizeof(Polynomial) * MaxSize);
	if (L->elem == NULL)
	{

	}
	L->elem = 0;
}
int main()
{


}