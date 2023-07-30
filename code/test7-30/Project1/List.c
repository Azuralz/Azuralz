#include <stdlib.h>
#define MaxSize 100

typedef struct //创建数据结构类型 
{
	float a; //系数
	int e;  //指数
}Polynomial;

typedef struct //创建存储结构类型
{
	Polynomial* elem; //指向某个数据的指针
	int length; //数据的长度
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