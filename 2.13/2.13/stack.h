#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef int STD;
typedef struct Stack
{
	STD* a;
	int top;
	int capacity;
}ST;


void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}


void StackPush(ST* ps, STD x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = (ps->capacity == 0) ? 4 : (ps->capacity * 2);
		ps->a = (STD*)realloc(ps->a, newcapacity * sizeof(ST));
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps && ps->top > 0);
	ps->top--;
}


STD StackTop(ST* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];
}

//获取栈中有效元素个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//空返回1，不空返回0
int StackEmpty(ST* ps)
{
	assert(ps);
	return (ps->top == 0) ? 1 : 0;
}


void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}