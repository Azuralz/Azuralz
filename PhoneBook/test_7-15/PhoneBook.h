#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define Max_name 20
#define Max_sex 5
#define Max_tel 20
#define Max_addr 20
#define MAX 1000
#define Defult 3
#define Increas 2



enum option
{
	EXIT,
	ADD,
	DELE,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
typedef struct PepInfor
{
	char name[Max_name];
	int age;
	char sex[Max_sex];
	char tel[Max_tel];
	char addr[Max_addr];
}PepInfor;

typedef struct Contact
{
	PepInfor* data;
	int capacity;
	int sz;
}Contact;

void InitContact(Contact* pc);//初始化通讯录
void ADDContact(Contact* pc);//增加项目
void PrintContact(const Contact* pc);//打印通讯录
void DelContact(Contact* pc);//删除项目
void SearchContact(Contact* pc);//查找通讯录
void ModifyContact(Contact*pc);//修改通讯录
void SortContact(Contact* pc);//排序
void DestroyContact(Contact*pc);//销毁内存 
void WriteData(Contact*pc);//保存数据到文件中
void LoadContact(Contact*pc);//加载数据文件
void Checkcapacity(Contact*pc);//检查容量是否增容