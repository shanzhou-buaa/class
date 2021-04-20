#include "dlist.h"

dln* BuyDListNode(data x)
{
	dln* newnode = (dln*)malloc(sizeof(dln));
	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

dln* DListNodeInit()
{
	dln* newnode = (dln*)malloc(sizeof(dln));
	newnode->val = -1;//随意
	newnode->next = newnode;
	newnode->prev = newnode;

	return newnode;
}

void DListNodePushBack(dln* phead, data x)
{
	//assert(phead);
	//dln* newnode = BuyDListNode(x);//创建新结点

	//dln* tail = phead->prev;//找尾

	////连接结点
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;

	DListNodeInsertBefore(phead, x);
}

void DListNodePushFront(dln* phead, data x)
{
	//assert(phead);

	//dln* newnode = BuyDListNode(x);

	//dln* first = phead->next;

	//first->prev = newnode;
	//newnode->next = first;
	//newnode->prev = phead;
	//phead->next = newnode;

	DListNodeInsertBefore(phead->next, x);
}


void DListNodePopBack(dln* phead)
{
	//assert(phead);
	//assert(phead != phead->next);//防止链表中只有一个phead，没有别的结点

	//dln* tail = phead->prev;
	//dln* tailPrev = phead->prev->prev;
	//free(tail);

	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	DListNodeErase(phead->prev);
}

void DListNodePopFront(dln* phead)
{
	//assert(phead);
	//assert(phead != phead->next);

	//dln* first = phead->next;
	//dln* firstNext = phead->next->next;
	//free(first);

	//phead->next = firstNext;
	//firstNext->prev = phead;

	DListNodeErase(phead->next);
}

dln* DListNodeFind(dln* phead, data x)
{
	assert(phead);
	dln* cur = phead->next;

	while (cur != phead)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}

	return NULL;
}

void DListNodeInsertBefore(dln* pos, data x)
{
	assert(pos);

	dln* newnode = BuyDListNode(x);
	dln* prev = pos->prev;

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void DListNodeErase(dln* pos)
{
	assert(pos);

	dln* prev = pos->prev;
	dln* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}

void DListNodePrint(dln* phead)
{
	dln* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

int DListNodeEmpty(dln* phead)
{
	return (phead->next == phead);
}

int DListNodeSize(dln* phead)
{
	assert(phead);

	int size = 0;
	dln* cur = phead->next;

	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

void DListNodeDsetroy(dln* phead)
{
	assert(phead);
	dln* cur = phead->next;
	while (cur != phead)
	{
		dln* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}