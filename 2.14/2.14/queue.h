#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef int QDT;
typedef struct QueueNode
{
	QDT data;
	struct QueueNode* next;
}QN;

typedef struct Queue
{
	struct QueueNode* front;
	struct QueueNode* back;
}Q;


void QueueInit(Q* q)
{
	assert(q);
	q->front = NULL;
	q->back= NULL;
}

//队尾入队
void QueuePush(Q* q, QDT x)
{
	QN* new = (QN*)malloc(sizeof(QN));
	new->data = x;
	new->next = NULL;
	if (q->back == NULL)
	{
		q->back = new;
		q->front = new;
	}
	else
	{
		q->back->next = new;
		q->back = new;
	}
}


//获取队列头部元素
QDT QueueFront(Q* q)
{
	assert(q);
	return q->front->data;
}

//获取队列尾部元素
QDT QueueBack(Q* q)
{
	assert(q);
	return q->back->data;
}


int QueueSize(Q* q)
{
	int n = 0;
	QN* cur = q->front;
	while(cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}


//检测队列是否为空
//非空返回非零
//空返回0
int QueueEmpty(Q* q)
{
	return QueueSize(q);
//	return (q->front == NULL) ? 1 : 0;
}


void QueueDestroy(Q* q)
{
	QN* cur = q->front;
	while (cur)
	{
		QN* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = NULL;
	q->back = NULL;
}


//队头出队列
void QueuePop(Q* q)
{
	assert(q);
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = NULL;
		q->back = NULL;
	}
	else
	{
		QN* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}


void test()
{
	Q q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d\n", QueueSize(&q));
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
}