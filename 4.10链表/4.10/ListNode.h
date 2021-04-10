#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int data;
//data type

typedef struct ListNode
{
	data a;
	struct ListNode* next;
}ln;


void ListNodePushBack(ln** pplist, data a);

void ListNodePushFront(ln** pplist, data a);

void ListNodePopBack(ln** pplist);

void ListNodePopFront(ln** pplist);

ln* ListNodeFind(ln* plist, data x);

void ListNodeInsertAfter(ln* pos, data x);

void ListNodeEraseAfter(ln* pos);

void ListNodePrint(ln* plist);