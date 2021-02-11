#include "SList.h"


SLN* NewSListNode(SLD x)
{
	SLN* new = (SLN*)malloc(sizeof(SLN));
	if (new == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	new->data = x;
	new->next = NULL;
	return new;
}

void SListPushBack(SLN** pphead, SLD x)
{
	SLN* new = NewSListNode(x);
	if (*pphead == NULL)
	{
		*pphead = new;
	}
	else
	{
		SLN* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new;
	}
}

void SListPopBack(SLN** pphead)
{
	//1.空
	if (*pphead == NULL)
	{
		return;
	}
	//2.只有一个结点
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.正常
	else
	{
		SLN* prev = NULL;
		SLN* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = (tail)->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPushFront(SLN** pphead, SLD x)
{
	SLN* new = NewSListNode(x);
	new->next = *pphead;
	*pphead = new;
}

void SListPopFront(SLN** pphead)
{
	if (*pphead != NULL)
	{
		SLN* new = (*(pphead))->next;
		free(*(pphead));
		*pphead = new;
	}
}

void SListPrint(SLN* head)
{
	SLN* cur = head;
	while (cur != NULL)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLN* SListFind(SLN* head, SLD x)
{
	while (head != NULL)
	{
		if (head->data != x)
		{
			head = head->next;
		}
		else
		{
			return head;
		}
	}
	return NULL;
}

void SListInsertAfter(SLN* pos, SLD x)
{
	SLN* new = NewSListNode(x);
	SLN* next = pos->next;
	pos->next = new;
	new->next = next;
	
	//new->next = pos->next;
	//pos->next = new;
	//如果不定义一个新的指针就这样写
}

void SListErase(SLN* pos)
{
	SLN* next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
		next->next = NULL;
	}
	else
	{
		return;
	}
}

void SListDestroy(SLN** pphead)
{
	SLN* cur = (*pphead)->next;
	while (cur)
	{
		SLN* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}