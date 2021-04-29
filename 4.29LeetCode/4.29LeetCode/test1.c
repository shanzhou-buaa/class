#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char data;
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

bool left(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return true;
	return false;
}

bool right(char c)
{
	if (c == ')' || c == ']' || c == '}')
		return true;
	return false;
}

bool match(char a, char b)
{
	if ((a == '(' && b == ')')
		|| (a == '[' && b == ']')
		|| (a == '{' && b == '}'))
		return true;

	return false;
}

bool isValid(char * s)
{
	if (s == NULL)
		return true;

	stack st;
	StackInit(&st);
	int len = strlen(s);
	if (len % 2 == 1)
		return false;

	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (left(s[i]))
			StackPush(&st, s[i]);
		if (right(s[i]))
		{
			if (StackEmpty(&st))
				return false;

			char temp = StackTop(&st);
			StackPop(&st);
			if (!match(temp, s[i]))
				return false;
		}
	}
	if (!StackEmpty(&st))
		return false;

	StackDestroy(&st);
	return true;
}

int main()
{

	return 0;
}