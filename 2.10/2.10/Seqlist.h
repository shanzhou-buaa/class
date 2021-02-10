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
	int size;//��Ч���ݵĸ���
	int capacity;//����
}SL;

void SLInit(SL* ps);

void SLCheck(SL* ps);

//β��
void SLPushBack(SL* ps, SLData x);

//βɾ
void SLPopBack(SL* ps);

//ͷ��
void SLPushFront(SL* ps, SLData x);

//ͷɾ
void SLPopFront(SL* ps);

//����λ�ò���
void SLInsert(SL* ps, int pos, SLData x);

//����λ��ɾ��
void SLErase(SL* ps, int pos);

void SLPrint(SL* ps);

void SLDestroy(SL* ps);

int SLBinarySearch(SL* ps, SLData x, int left, int right);

void SLBubbleSort(SL* ps);
