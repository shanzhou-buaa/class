#include "Queue.h"

void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, data x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//没有结点
	//只有一个结点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL; 
	}
	//多个结点
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

data QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

data QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->val;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return (pq->head == NULL);
}

int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->head;

	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}