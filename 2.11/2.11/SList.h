#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef int SLD;
typedef struct SListNode SLN;

struct SListNode
{
	SLD data;
	SLN* next;
};


void SListPushBack(SLN** pphead, SLD x);
void SListPopBack(SLN** pphead);
void SListPushFront(SLN** pphead, SLD x);
void SListPopFront(SLN** pphead);
void SListPrint(SLN* head);
SLN* SListFind(SLN* head, SLD x);
void SListInsertAfter(SLN* pos, SLD x);
void SListErase(SLN* pos);
void SListDestroy(SLN** pphead);