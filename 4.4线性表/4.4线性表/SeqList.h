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
	int size;//顺序表中当前有效数据的个数
	int capacity;//顺序表中最大存储的个数
}sl;

//初始化
void SeqListInit(sl* p);
//销毁
void SeqListDestroy(sl* p);
//尾插
void SeqListPushBack(sl* p, data x);
//头插
void SeqListPushFront(sl* p, data x);
//尾删
void SeqListPopBack(sl* p);
//头删
void SeqListPopFront(sl* p);
//打印
void SeqListPrint(sl* p);
//查找
int SeqListFind(sl* p, data x);
//中间插入数据
void SeqListInsert(sl*p, int pos, data x);
//中间删除数据
void SeqListErase(sl* p, int pos);
//修改
void SeqListModify(sl* p, int pos, data x);