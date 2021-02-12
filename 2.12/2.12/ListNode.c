#include "ListNode.h"


LN* ListCreate()
{
	LN* head = (LN*)malloc(sizeof(LN));
	head->next = head;
	head->prev = head;

	return head;
}
LN* newListNode(LTD  x)
{
	LN* new = (LN*)malloc(sizeof(LN));
	new->data = x;
	new->next = NULL;
	new->prev = NULL;

	return new;
}
void ListPushBack(LN* phead, LTD x)
{
	LN* new = newListNode(x);
	LN* tail = phead->prev;
	phead->prev = new;
	tail->next = new;
	new->next = phead;
	new->prev = tail;

	//����Ĵ���ɼ�Ϊ����һ��
	//ListInsert(phead, x);
}

void ListPrint(LN* phead)
{
	LN* cur = phead->next;
	while (cur != phead)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


void ListPopBack(LN* phead)
{
	LN* tail = phead->prev;
	LN* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	//free(tail);
	//��û�ж���
	tail->next = NULL;
	tail->prev = NULL;


	//ListErase(phead->prev);
}

void ListPushFront(LN* phead, LTD x)
{
	LN* new = newListNode(x);
	LN* next = phead->next;
	new->prev = phead;
	next->prev = new;
	new->next = next;
	phead->next = new;


	//ListInsert(phead->next, x);
}

void ListPopFront(LN* phead)
{
	assert(phead->next != NULL);

	LN* first = phead->next;
	LN* second = first->next;
	phead->next = second;
	second->prev = phead;
	//free(first);
	//û�ã������ڲ��ľֲ���������Ӱ������ı���
	first = NULL;


	//ListErase(phead->next);
}


void ListDestroy(LN* phead)
{
	LN* cur = phead->next;
	while (cur != phead)
	{
		LN* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	//phead = NULL;
}

LN* ListFind(LN* phead, LTD x)
{
	LN* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//��posǰ���������
void ListInsert(LN* pos, LTD x)
{
	LN* new = newListNode(x);
	LN* prev = pos->prev;
	prev->next = new;
	new->next = pos;
	new->prev = prev;
	pos->prev = new;
	//������prevָ��
	/*LN* new = newListNode(x);
	new->next = pos;
	new->prev = pos->prev;
	pos->prev->next = new;
	pos->prev = new;*/
}

//ɾ��posλ�õĽ��
void ListErase(LN* pos)
{
	LN* prev = pos->prev;
	LN* next = pos->next;
	prev->next = next;
	next->prev = prev;
}
