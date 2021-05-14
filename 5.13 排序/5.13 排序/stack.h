#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//单链表不行，如果把栈顶放在头结点也可以
//线性表只需尾插尾删，挺好
//双向循环带头链表也可以

//双向链表太复杂
//线性表缓存命中率高

typedef int STDataType;
typedef struct stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//栈的容量
}stack;

void StackInit(stack* st);

void StackDestroy(stack* st);

void StackPush(stack* st, STDataType x);

void StackPop(stack* st);

STDataType StackTop(stack* st);

//空返回1，非空返回0
//int StackEmpty(stack* st);

bool StackEmpty(stack* st);

int StackSize(stack* st);