#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef int SLData;

typedef struct SeqList
{
	SLData* a;
	int size;//有效数据的个数
	int capacity;//容量
}SL;

void SLInit(SL* ps);

void SLCheck(SL* ps);

//尾插
void SLPushBack(SL* ps, SLData x);

//尾删
void SLPopBack(SL* ps);

//头插
void SLPushFront(SL* ps, SLData x);

//头删
void SLPopFront(SL* ps);

//任意位置插入
void SLInsert(SL* ps, int pos, SLData x);

//任意位置删除
void SLErase(SL* ps, int pos);

void SLPrint(SL* ps);

void SLDestroy(SL* ps);

int SLBinarySearch(SL* ps, SLData x, int left, int right);

void SLBubbleSort(SL* ps);
