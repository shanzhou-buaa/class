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
	//1.û�н��
	if (*pplist == NULL)
		return;
	//2.ֻ��һ�����
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//3.������
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
	//1.û�н��
	if (*pplist == NULL)
		return;

	//2.������
	else
	{
		ln* next = (*pplist)->next;//��֤�Ƚ��н����ò���
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

//��pos���ĺ������һ�����
void ListNodeInsertAfter(ln* pos, data x)
{
	assert(pos);
	ln* next = pos->next;
	ln* cur = BuyListNode(x);
	pos->next = cur;
	cur->next = next;
}
//�ڽ��ǰ����һ�������鷳

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