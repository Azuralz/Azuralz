#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//
//void peint(unsigned int b)
//{
//	if (b/10 != 0)//限制条件
//	{
//		peint(b / 10);//递归无限接近限制条件
//	}
//	printf("%d ", b % 10);
//}
//
//int main()
//{
//	unsigned int a = 0;
//	scanf("%u", &a);
//	peint(a);
//	return 0;
//}
//int main()
//{
//	char arr[] = {'a','b','c'};
//	int len = strlen(arr);
//	printf("%d", len);
//	return 0;
//}
//int main()
//{
//	char arr[20] = "**************";
//	strcpy(arr, "hello");
//	
//
//	printf("%s", arr);
//	return 0;
//}
////实现stecat函数
//void my_strcat(char* dest, const char*sce)
//{
//	assert(dest && sce);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *sce++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr[20] = "hello ";
//	char arr1[] = "world";
//	my_strcat(arr, arr1);
//	printf("%s\n", arr);
//	return 0;
//}

//
//int main()
//{
	////strcmp实现比较字符串大小
	/*char* p = "abc";
	char* q = "abd";
	int sz = strcmp(p, q);
	if (sz < 0)
	{
		printf("p<q \n");
	}
	if (sz == 0)
	{
		printf("p=q\n");
	}
	if (sz > 0)
	{
		printf("p>q\n");
	}*/


	//////strncpy实现替换
	////char arr[20] = "abcdfkjdla";
	////char arr1[] = "lll";
	////strncpy(arr, arr1, 5);
	////printf("%s", arr);
	////return 0;
	//int a = sizeof int;
	//int b = sizeof(int);

	
//		char str[] = "Hello World!";
//		size_t len = sizeof(str) / sizeof(char);
//		size_t i;
//		for (i = 0; i < len; ++i)
//		printf("%c",str[i])
//			return 0;
//	
//}
//int main(int argc, char** argv)
//{
//	char str[] = "Hello World!";
//	size_t len = sizeof(str) / sizeof(char);
//	size_t i;
//	for (i = 0; i < len; ++i)
//		printf("%c",str[i])
//
//		return 0;
//}
// 
// //            字符查找函数strstr的模拟实现
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//两个不变的量做参照用
//	const char* s1 = NULL;//初始化两个指针方便放入str1 str2
//	const char* s2 = NULL;
//	char* cp = str1;//可移动的指针 在s1上找第一个相等的
//	while (*cp)//首字符相等时进入 到/0没找到就返回NULL
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 && *s2 && (*s1 == *s2))//防止越界，当s1=s2时cp停止++，s1++ s2++找相同，找完了就自动跳下
//		{
//			s2++;
//			s1++;
//		}
//		if (*s2 == '\0')//把s2找完了都相同 返回cp
//		{
//			 return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[20] = "abbbcdkl";
//	char arr1[] = "bbc";
//	char* p = my_strstr(arr, arr1);
//	if (p == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("%s", p);
//	}
//	return 0;
//}
// 
// 
// 
// 
//                            strtok函数
//int main()
//{
//	char arr[20] = "zhou*xin/long";
//	char* p = "*/";//strtok的第二个参数分隔符号
//	char tmp[20] = { 0 };
//	strcpy(tmp, arr);//因为strtok函数会修改源字符串，所以确保不被修改增加变量
//	char* ret = NULL;//创建指针接收strtok返回值
//	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
////接收返回指针   ret=空指针时说明结束了//把空指针交给strtok函数时会从之前结束的地址继续分隔
//	{
//		printf("%s\n", ret);
//	}
//
//
//	return 0;
//}



//int main()
//{
//	FILE* p = fopen("test.text", "r");
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	fclose(p);
//	p = NULL;
//	return 0;
//}
// 
// 
// 
////malloc 函数 
////不能初始化开辟的内存
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = (int*)malloc(10 * sizeof(int*));
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	return 0;
//}

//// calloc
//// 函数开辟的内存直接初始化
//int main()
//{
//	int* p = calloc(10, sizeof(int*));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	//out:000000000
//	return 0;
//}

//realloc
//调整空间1。后面空间足 直接改变2。后面空间不足 返回空指针 拷贝 然后再扩充 再返回指针。 
//int main()
//{
//	int* p = calloc(10, sizeof(int*));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = 5;
//	}
//	int* ptr = (int*)realloc(*p, 20 * sizeof(int));//创建临时指针 防止返回空指针 把指针p修改
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//void* getmom(char* pc)
//{
//	pc = (char*)malloc(100);
//}
//void test(void)
//{
//	char* p = NULL;
//	p = getmom(&p);
//	strcpy(p, "hello world");
//	printf(p);
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
