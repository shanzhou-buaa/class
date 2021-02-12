#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef int LTD;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTD data;
}LN;

LN* ListCreate();

void ListDestroy(LN* phead);

void ListPrint(LN* phead);

void ListPushBack(LN* phead, LTD x);

void ListPopBack(LN* phead);

void ListPushFront(LN* phead, LTD x);

void ListPopFront(LN* phead);

LN* newListNode(LTD x);

LN* ListFind(LN* phead, LTD x);

void ListInsert(LN* pos, LTD x);

void ListErase(LN* pos);
