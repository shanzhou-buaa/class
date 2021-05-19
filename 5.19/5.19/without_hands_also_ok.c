#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_NUM 10000

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ln;

void Sort1(int* l1, int num1, int* l2, int num2);
void Sort2(int* l1, int num1, int* l2, int num2);

int main()
{
	int l1[MAX_NUM], l2[MAX_NUM];
	memset(l1, 0, sizeof(int)* MAX_NUM);
	memset(l2, 0, sizeof(int)* MAX_NUM);
	int i1 = 0, i2 = 0;
	while (scanf("%d", &l1[i1]) != EOF)
		i1++;
	int num1 = i1;
	while (scanf("%d", &l2[i2]) != EOF)
		i2++;
	int num2 = i2;
	Sort1(l1, num1, l2, num2);//链表
	Sort2(l1, num1, l2, num2);//线性表
	return 0;
}

void Sort1(int* l1, int num1, int* l2, int num2)
{
	ln* head = (ln*)malloc(sizeof(ln));
	int i1 = 0, i2 = 0;
	
	//确定链表头结点
	if (l1[0] < l2[0])
	{
		head->data = l1[0];
		i1++;
	}
	else
	{
		head->data = l2[0];
		i2++;
	}

	//链接其余结点
	ln* cur = head;
	while (i1 < num1 && i2 < num2)
	{
		ln* newnode = (ln*)malloc(sizeof(ln));
		if (l1[i1] < l2[i2])
		{
			newnode->data = l1[i1];
			i1++;
			cur->next = newnode;
			cur = newnode;
		}
		else
		{
			newnode->data = l2[i2];
			i2++;
			cur->next = newnode;
			cur = newnode;
		}
	}
	while (i1 < num1)
	{
		ln* newnode = (ln*)malloc(sizeof(ln));
		newnode->data = l1[i1];
		i1++;
		cur->next = newnode;
		cur = newnode;
	}
	while (i2 < num2)
	{
		ln* newnode = (ln*)malloc(sizeof(ln));
		newnode->data = l2[i2];
		i2++;
		cur->next = newnode;
		cur = newnode;
	}
	cur->next = NULL;

	//打印
	cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void Sort2(int* l1, int num1, int* l2, int num2)
{
	int* ret = (int*)malloc(sizeof(int)*(num1 + num2));
	int i = 0, i1 = 0, i2 = 0;
	while (i1 < num1 && i2 < num2)
	{
		if (l1[i1] < l2[i2])
			ret[i++] = l1[i1++];
		else
			ret[i++] = l2[i2++];
	}
	while (i1 < num1)
		ret[i++] = l1[i1++];
	while (i2 < num2)
		ret[i++] = l2[i2++];
	int num = i;
	for (i = 0; i < num; i++)
		printf("%d ", ret[i]);
	printf("\n");
}