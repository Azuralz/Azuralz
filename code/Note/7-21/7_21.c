#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//
//void peint(unsigned int b)
//{
//	if (b/10 != 0)//��������
//	{
//		peint(b / 10);//�ݹ����޽ӽ���������
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
////ʵ��stecat����
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
	////strcmpʵ�ֱȽ��ַ�����С
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


	//////strncpyʵ���滻
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
// //            �ַ����Һ���strstr��ģ��ʵ��
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//�������������������
//	const char* s1 = NULL;//��ʼ������ָ�뷽�����str1 str2
//	const char* s2 = NULL;
//	char* cp = str1;//���ƶ���ָ�� ��s1���ҵ�һ����ȵ�
//	while (*cp)//���ַ����ʱ���� ��/0û�ҵ��ͷ���NULL
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 && *s2 && (*s1 == *s2))//��ֹԽ�磬��s1=s2ʱcpֹͣ++��s1++ s2++����ͬ�������˾��Զ�����
//		{
//			s2++;
//			s1++;
//		}
//		if (*s2 == '\0')//��s2�����˶���ͬ ����cp
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
//		printf("û�ҵ�\n");
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
//                            strtok����
//int main()
//{
//	char arr[20] = "zhou*xin/long";
//	char* p = "*/";//strtok�ĵڶ��������ָ�����
//	char tmp[20] = { 0 };
//	strcpy(tmp, arr);//��Ϊstrtok�������޸�Դ�ַ���������ȷ�������޸����ӱ���
//	char* ret = NULL;//����ָ�����strtok����ֵ
//	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
////���շ���ָ��   ret=��ָ��ʱ˵��������//�ѿ�ָ�뽻��strtok����ʱ���֮ǰ�����ĵ�ַ�����ָ�
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
////malloc ���� 
////���ܳ�ʼ�����ٵ��ڴ�
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
//// �������ٵ��ڴ�ֱ�ӳ�ʼ��
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
//�����ռ�1������ռ��� ֱ�Ӹı�2������ռ䲻�� ���ؿ�ָ�� ���� Ȼ�������� �ٷ���ָ�롣 
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
//	int* ptr = (int*)realloc(*p, 20 * sizeof(int));//������ʱָ�� ��ֹ���ؿ�ָ�� ��ָ��p�޸�
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
