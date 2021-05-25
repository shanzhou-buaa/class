#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QNDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QNDataType val;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

void QueuePush(Queue* q, QNDataType x);

void QueuePop(Queue* q);

QNDataType QueueFront(Queue* q);

QNDataType QueueBack(Queue* q);

bool QueueEmpty(Queue* q);

int QueueSize(Queue* q);
#define MAX 99999999

int graph[101][101];
int book[101];
int point, line;
int del;

void dfs1(int cur)
{
	printf("%d ", cur);

	int i = 0;
	for (i = 0; i < point; i++)
	{
		if (graph[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			dfs1(i);
		}
	}
	return;
}

void dfs2(int cur)
{
	if (cur == del)
		return;
	printf("%d ", cur);

	int i = 0;
	for (i = 0; i < point; i++)
	{
		if (i == del)
			continue;
		if (graph[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			dfs2(i);
		}
	}
	return;
}
int main()
{
	scanf("%d%d", &point, &line);
	int i, j;
	for (i = 0; i < line; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (i = 0; i < point; i++)
	{
		for (j = 0; j < point; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else if (graph[i][j] != 1)
				graph[i][j] = MAX;
		}
	}
	scanf("%d", &del);

	//1.深度优先
	book[0] = 1;
	dfs1(0);
	printf("\n");
	
	for (i = 0; i < 101; i++)
		book[i] = 0;

	//2.广度优先
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 0);
	book[0] = 1;
	while (!QueueEmpty(&q))
	{
		int cur = QueueFront(&q);
		for (i = 0; i < point; i++)
		{
			if (graph[cur][i] == 1 && book[i] == 0)
			{
				QueuePush(&q, i);
				book[i] = 1;
			}
		}
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	for (i = 0; i < 101; i++)
		book[i] = 0;

	//3.
	book[0] = 1;
	dfs2(0);
	printf("\n");

	for (i = 0; i < 101; i++)
		book[i] = 0;

	//4.
	QueueInit(&q);
	QueuePush(&q, 0);
	book[0] = 1;
	while (!QueueEmpty(&q))
	{
		int cur = QueueFront(&q);
		if (cur != del)
		{
			for (i = 0; i < point; i++)
			{
				if (i == del)
					continue;
				if (graph[cur][i] == 1 && book[i] == 0)
				{
					QueuePush(&q, i);
					book[i] = 1;
				}
			}
			printf("%d ", QueueFront(&q));
			QueuePop(&q);
		}
		else
		{
			if (QueueEmpty(&q))
				break;
			else
				QueuePop(&q);
		}
	}
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	return 0;
}

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
	free(pq);
}

void QueuePush(Queue* pq, QNDataType x)
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

QNDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

QNDataType QueueBack(Queue* pq)
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