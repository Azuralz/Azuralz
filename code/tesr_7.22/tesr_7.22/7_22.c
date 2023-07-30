#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//          *memcpy内存拷贝模拟实现*
//void* my_memcpy(void* dest, void* src, size_t num)
//// 返回无类型指针               
//{
//	assert(dest && src);
//	void* s1 = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return s1;
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1, 15);
//	printf("%d", arr2[5]);
//	return 0;
//}



//            *模拟实现memmove函数*
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	if (dest < src)//从前往后拷贝，防止重复
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//从后往前拷贝
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);//num为变量
//		}
//	}
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1, arr1+2, 20);
//	return 0;
//}




//                          *memset*  内存放入指定字符
//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 20);
//	return 0;
//}




//                           * 创建类型*
//struct Book
//{
//	char name[20];
//	int price;
//	char number[20];
//}b1, b2, b3;//这里为全局变量
//int main()
//{
//	struct Book b4;//这里为局部变量
//	return 0;
//}



//                       *位断*
struct S
{
	//int类型一次开辟4个字节占满再开辟4个字节
	//位断不跨平台  可移植程序避免使用
	//尽量为都为int 或者char 
	int _a : 2;//占 2 个bit位
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
int main()
{
	printf("%d \n", sizeof(struct S));
	return 0;
}