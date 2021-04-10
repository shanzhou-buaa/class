#include "ListNode.h"

ln* BuyListNode(data x)
{
	ln* newnode = (ln*)malloc(sizeof(ln));
	newnode->a = x;
	newnode->next = NULL;
	return newnode;
}

void ListNodePushBack(ln** pplist, data a)
{
	ln* newnode = BuyListNode(a);
	if (*pplist == NULL)
	{
		*pplist = newnode;
		return;
 	}
	ln* cur = *pplist;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newnode;
	return;
}

void ListNodePushFront(ln** pplist, data a)
{
	ln* newnode = BuyListNode(a);
	newnode->next = *pplist;
	*pplist = newnode;
	return;
}

void ListNodePopBack(ln** pplist)
{
	//1.没有结点
	if (*pplist == NULL)
		return;
	//2.只有一个结点
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//3.多个结点
	ln* tail = *pplist;	
	ln* prev = *pplist;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	prev->next = NULL;
}

void ListNodePopFront(ln** pplist)
{
	//1.没有结点
	if (*pplist == NULL)
		return;

	//2.多个结点
	else
	{
		ln* next = (*pplist)->next;//保证先进行解引用操作
		free(*pplist);
		*pplist = next;
	}
}

ln* ListNodeFind(ln* plist, data x)
{
	ln* cur = plist;
	while (cur != NULL)
	{
		if (cur->a == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

//在pos结点的后面插入一个结点
void ListNodeInsertAfter(ln* pos, data x)
{
	assert(pos);
	ln* next = pos->next;
	ln* cur = BuyListNode(x);
	pos->next = cur;
	cur->next = next;
}
//在结点前插入一个结点很麻烦

void ListNodeEraseAfter(ln* pos)
{
	assert(pos);
	if (pos->next == NULL)
		return;
	ln* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}
void ListNodePrint(ln* plist)
{
	while (plist != NULL)
	{
		printf("%d->", plist->a);
		plist = plist->next;
	}
	printf("NULL\n");
}