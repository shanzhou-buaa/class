#include "stack.h"

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