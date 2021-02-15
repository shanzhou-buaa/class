#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef struct QueueNode
{
	int data;
	struct QueueNode* next;
}QN;

typedef struct Queue
{
	QN* front;
	QN* back;
}Q;


typedef struct {
	Q q1;
	Q q2;
} MyStack;

void QueueInit(Q* q)
{
	q->front = NULL;
	q->back = NULL;
}

void QueuePush(Q* q, int x)
{
	QN* newnode = (QN*)malloc(sizeof(QN));
	newnode->data = x;
	newnode->next = NULL;
	if (q->back == NULL)
	{
		q->back = newnode;
		q->front = newnode;
	}
	else
	{
		QN* back = q->back;
		q->back = newnode;
		back->next = newnode;
	}
}

void QueuePop(Q* q)
{
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = NULL;
		q->back = NULL;
	}
	else
	{
		QN* newfront = q->front->next;
		free(q->front);
		q->front = NULL;
	}
}

int QueueTop(Q* q)
{
	return q->front->data;
}

//返回元素个数
int QueueSize(Q* q)
{
	QN* cur = q->front;
	int n = 0;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	return n;
}
//空返回0
//非空返回元素个数
int QueueEmpty(Q* q)
{
	return QueueSize(q);
}

//获取队列头部元素
int QueueFront(Q* q)
{
	assert(q);
	return q->front->data;
}

//获取队列尾部元素
int QueueBack(Q* q)
{
	assert(q);
	return q->back->data;
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

/** Initialize your data structure here. */
MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q2, x);
	else
		QueuePush(&obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Q* empty = &obj->q1;
	Q* not_empty = &obj->q2;
	if (!QueueEmpty(&obj->q2))
	{
		not_empty = &obj->q1;
		empty = &obj->q2;
	}
	while (QueueSize(not_empty) > 1)
	{
		QueuePush(empty, QueueFront(not_empty));
		QueuePop(not_empty);
	}
	int top = QueueBack(not_empty);
	QueuePop(not_empty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q2);
	else
		return QueueBack(&obj->q1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueSize(&obj->q1) || QueueSize(&obj->q2))
		return false;
	else
		return true;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
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