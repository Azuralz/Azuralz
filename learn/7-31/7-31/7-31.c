//引用头文件
#include <stdio.h>
#include <stdlib.h>

//定义值
#define MAXSIZE 1000
#define OVERFLOW 0

typedef struct//节点数据类型
{
	float a;
	int e;
}Polynomial;

typedef struct//储存结构类型
{
	Polynomial* elen;
	int length;
}SqList;


void InitList(SqList*L)//初始化线性表
{
	L->elen = malloc(MAXSIZE * sizeof(Polynomial));//为线性表开辟空间
	if (L->elen)//分配失败
	{
		perror("错误");
		exit(OVERFLOW);
	}
	L->length = 0;//长度置为0
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