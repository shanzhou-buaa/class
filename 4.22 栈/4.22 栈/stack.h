#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//�������У������ջ������ͷ���Ҳ����
//���Ա�ֻ��β��βɾ��ͦ��
//˫��ѭ����ͷ����Ҳ����

//˫������̫����
//���Ա��������ʸ�

typedef int data;
typedef struct stack
{
	data* a;
	int top;//ջ��
	int capacity;//ջ������
}stack;

void StackInit(stack* st);

void StackDestroy(stack* st);

void StackPush(stack* st, data x);

void StackPop(stack* st);

data StackTop(stack* st);

//�շ���1���ǿշ���0
//int StackEmpty(stack* st);

bool StackEmpty(stack* st);

int StackSize(stack* st);