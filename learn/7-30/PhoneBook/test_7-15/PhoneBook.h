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

void InitContact(Contact* pc);//��ʼ��ͨѶ¼
void ADDContact(Contact* pc);//������Ŀ
void PrintContact(const Contact* pc);//��ӡͨѶ¼
void DelContact(Contact* pc);//ɾ����Ŀ
void SearchContact(Contact* pc);//����ͨѶ¼
void ModifyContact(Contact*pc);//�޸�ͨѶ¼
void SortContact(Contact* pc);//����
void DestroyContact(Contact*pc);//�����ڴ� 
void WriteData(Contact*pc);//�������ݵ��ļ���
void LoadContact(Contact*pc);//���������ļ�
void Checkcapacity(Contact*pc);//��������Ƿ�����