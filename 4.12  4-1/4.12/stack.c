#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Stack
{
	int* a;
	int capacity;//最大存放的数据个数
	int size;//当前的数据个数
}stack;

void StackInit(stack* s)
{
	s->a = (int*)malloc(sizeof(int) * 100);
	s->capacity = 100;
	s->size = 0;
}

//void Check(stack* s)
//{
//	if (s->capacity == s->size)
//	{
//		int newcapacity = (s->capacity == 0) ? (4) : (2 * (s->capacity));
//		s->a = (int*)realloc(s->a, sizeof(stack)* newcapacity);
//		s->capacity = newcapacity;
//	}
//}

void StackPush(stack* s, int x)
{
	s->a[s->size] = x;
	s->size++;
}

int StackPop(stack* s)
{
	int tail = s->size;
	s->size--;
	return s->a[tail - 1];
}

int GetSize(stack* s)
{
	return s->size;
}

int main()
{
	stack s;
	StackInit(&s);
	int a[300] = { 0 };
	int n = 0, i = 0;//cur当前栈中的元素个数
	while (scanf("%d", &a[n]) != EOF)
	{
		n++;
		if (getchar() == '\n')
			break;
	}

	for (i = 0; i <= n; i++)
	{
		int prev = a[i];
		int next = -2;
		if (prev == -1)
			break;
		else if (prev == 1)
		{
			i++;
			next = a[i];
		}

		if ((prev == 1 && (GetSize(&s) == 100)) || (prev == 0 && (GetSize(&s) == 0)))
		{
			printf("error ");
			continue;
		}
		if (prev == 1)
		{
			StackPush(&s, next);
		}
		else if (prev == 0)
		{
			printf("%d ", StackPop(&s));
		}
	}
	return 0;
}