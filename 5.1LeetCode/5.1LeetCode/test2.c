#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int data;
typedef struct stack
{
	data* a;
	int top;//栈顶
	int capacity;//栈的容量
}stack;

void StackInit(stack* st);

void StackDestroy(stack* st);

void StackPush(stack* st, data x);

void StackPop(stack* st);

data StackTop(stack* st);

//空返回1，非空返回0
//int StackEmpty(stack* st);

bool StackEmpty(stack* st);

int StackSize(stack* st);


void StackInit(stack* st)
{
	assert(st);

	st->a = (data*)malloc(sizeof(stack)* 4);
	st->top = 0;
	st->capacity = 4;
}

void StackDestroy(stack* st)
{
	assert(st);
	free(st->a);
	st->a = NULL;
	st->capacity = 0;
	st->top = 0;
}

void StackPush(stack* st, data x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		data* tmp = (data*)realloc(st->a, sizeof(stack)* st->capacity * 2);

		if (tmp == NULL)
		{
			exit(-1);//结束整个程序
		}
		st->capacity *= 2;
		st->a = tmp;
	}
	st->a[st->top++] = x;
}

void StackPop(stack* st)
{
	assert(st);
	assert(!StackEmpty(st));

	st->top--;
}

data StackTop(stack* st)
{
	assert(st);
	assert(!StackEmpty(st));

	return st->a[st->top - 1];
}

//空返回true，非空返回false
bool StackEmpty(stack* st)
{
	assert(st);
	return (st->top == 0);
}

int StackSize(stack* st)
{
	assert(st);
	return st->top;
}

typedef struct
{
	stack en;
	stack de;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

	StackInit(&obj->en);
	StackInit(&obj->de);

	return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->en, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	if (!StackEmpty(&obj->de))
	{
		int temp = StackTop(&obj->de);
		StackPop(&obj->de);
		return temp;
	}
	else
	{
		while (!StackEmpty(&obj->en))
		{
			StackPush(&obj->de, StackTop(&obj->en));
			StackPop(&obj->en);
		}
		int temp = StackTop(&obj->de);
		StackPop(&obj->de);
		return temp;
	}
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (!StackEmpty(&obj->de))
		return StackTop(&obj->de);

	else
	{
		while (!StackEmpty(&obj->en))
		{
			StackPush(&obj->de, StackTop(&obj->en));
			StackPop(&obj->en);
		}
		return StackTop(&obj->de);
	}
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->en) && StackEmpty(&obj->de);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->en);
	StackDestroy(&obj->de);

	free(obj);
	obj = NULL;
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/

int main()
{

	return 0;
}