#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct BinaryTree;
typedef struct BinaryTree* data;

typedef struct QueueNode
{
	struct QueueNode* next;
	data val;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

void QueuePush(Queue* q, data x);

void QueuePop(Queue* q);

data QueueFront(Queue* q);

data QueueBack(Queue* q);

bool QueueEmpty(Queue* q);

int QueueSize(Queue* q);