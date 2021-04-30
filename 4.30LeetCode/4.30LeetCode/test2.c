#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int data;

typedef struct QueueNode
{
	struct QueueNode* next;
	data val;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

void QueuePush(Queue* q, data x);

void QueuePop(Queue* q);

data QueueFront(Queue* q);

data QueueBack(Queue* q);

bool QueueEmpty(Queue* q);

int QueueSize(Queue* q);

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


typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	//empty空队列,full有元素的队列
	Queue* empty = &obj->q1;
	Queue* full = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = &obj->q2;
		full = &obj->q1;
	}

	//向有元素的队列里push
	QueuePush(full, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	Queue* empty = &obj->q1;
	Queue* full = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = &obj->q2;
		full = &obj->q1;
	}

	//有元素的队列出队至只剩一个元素
	while (QueueSize(full) > 1)
	{
		QueuePush(empty, QueueFront(full));
		QueuePop(full);
	}

	int top = QueueFront(full);
	QueuePop(full);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	Queue* empty = &obj->q1;
	Queue* full = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = &obj->q2;
		full = &obj->q1;
	}

	//有元素的队列出队至只剩一个元素
	while (QueueSize(full) > 1)
	{
		QueuePush(empty, QueueFront(full));
		QueuePop(full);
	}

	int top = QueueFront(full);
	QueuePush(empty, QueueFront(full));
	QueuePop(full);
	return top;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
	obj = NULL;
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/

int main()
{

	return 0;
}