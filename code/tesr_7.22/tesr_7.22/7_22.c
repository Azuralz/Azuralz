#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//          *memcpy�ڴ濽��ģ��ʵ��*
//void* my_memcpy(void* dest, void* src, size_t num)
//// ����������ָ��               
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



//            *ģ��ʵ��memmove����*
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	if (dest < src)//��ǰ���󿽱�����ֹ�ظ�
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//�Ӻ���ǰ����
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);//numΪ����
//		}
//	}
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1, arr1+2, 20);
//	return 0;
//}




//                          *memset*  �ڴ����ָ���ַ�
//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 20);
//	return 0;
//}




//                           * ��������*
//struct Book
//{
//	char name[20];
//	int price;
//	char number[20];
//}b1, b2, b3;//����Ϊȫ�ֱ���
//int main()
//{
//	struct Book b4;//����Ϊ�ֲ�����
//	return 0;
//}



//                       *λ��*
struct S
{
	//int����һ�ο���4���ֽ�ռ���ٿ���4���ֽ�
	//λ�ϲ���ƽ̨  ����ֲ�������ʹ��
	//����Ϊ��Ϊint ����char 
	int _a : 2;//ռ 2 ��bitλ
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
int main()
{
	printf("%d \n", sizeof(struct S));
	return 0;
}