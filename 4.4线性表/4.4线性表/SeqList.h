#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#pragma once

//#define N 100
//typedef struct SeqList
//{
//	int a[N];
//	int size;
//}sl;

typedef int data;
//SeqListDataType

typedef struct SeqList
{
	data* a;
	int size;//˳����е�ǰ��Ч���ݵĸ���
	int capacity;//˳��������洢�ĸ���
}sl;

//��ʼ��
void SeqListInit(sl* p);
//����
void SeqListDestroy(sl* p);
//β��
void SeqListPushBack(sl* p, data x);
//ͷ��
void SeqListPushFront(sl* p, data x);
//βɾ
void SeqListPopBack(sl* p);
//ͷɾ
void SeqListPopFront(sl* p);
//��ӡ
void SeqListPrint(sl* p);
//����
int SeqListFind(sl* p, data x);
//�м��������
void SeqListInsert(sl*p, int pos, data x);
//�м�ɾ������
void SeqListErase(sl* p, int pos);
//�޸�
void SeqListModify(sl* p, int pos, data x);