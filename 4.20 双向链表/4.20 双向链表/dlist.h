#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int data;

typedef struct DListNode
{
	struct DListNode* prev;
	struct DListNode* next;
	data val;
}dln;

dln* BuyDListNode(data x);

dln* DListNodeInit();

void DListNodePushBack(dln* phead, data x);

void DListNodePushFront(dln* phead, data x);

void DListNodePopBack(dln* phead);

void DListNodePopFront(dln* phead);

void DListNodePrint(dln* phead);

dln* DListNodeFind(dln* phead, data x);

dln* DListNodeFind(dln* phead, data x);

//在pos前插入数据
void DListNodeInsertBefore(dln* pos, data x);

void DListNodeErase(dln* pos);

int DListNodeEmpty(dln* phead);

int DListNodeSize(dln* phead);

void DListNodeDsetroy(dln** phead);