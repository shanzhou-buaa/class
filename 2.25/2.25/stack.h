#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef int std;
//stack data

typedef struct stack
{
	std* a;
	int _top;
	int _capacity;
}st;


void StackInit(st* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}


void StackPush(st* ps, std x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = (ps->_capacity == 0) ? 4 : (2 * ps->_capacity);
		ps->a = (std*)realloc(ps->a, sizeof(std)* newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->a[ps->_top] = x;
	ps->_top++;
}



void StackPop(st* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}


std StackTop(st* ps)
{
	assert(ps);
	return ps->a[ps->_top - 1];
}


int StackSize(st* ps)
{
	assert(ps);
	return ps->_top;
}

//0Îª¿Õ
//·Ç0²»¿Õ
int StackEmpty(st* ps)
{
	return StackSize(ps);
}


void StackDestroy(st* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}


void StackPrint(st* ps)
{
	int i = 0;
	for (i = 0; i < ps->_top; i++)
		printf("%d ", ps->a[i]);
	printf("\n");
}