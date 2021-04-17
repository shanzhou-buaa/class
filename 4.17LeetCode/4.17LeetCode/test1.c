#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode 
{
	int val;
	struct ListNode *next;	
};

typedef struct ListNode ln;
struct ListNode *getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	int nA = 0, nB = 0;
	ln* cur1 = headA;
	ln* cur2 = headB;
	//1.计算A,B的长度
	while (cur1)
	{
		nA++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		nB++;
		cur2 = cur2->next;
	}
	if (cur1 != cur2)//判断相交，若相交，尾一定相同
		return NULL;

	//2.短的链表先走abs(nA - nB)步
	cur1 = headA;
	cur2 = headB;
	int tmp = 0;
	if (nA > nB)
	{
		tmp = nA - nB;
		while (tmp--)
			cur1 = cur1->next;
	}
	else
	{
		tmp = nB - nA;
		while (tmp--)
			cur2 = cur2->next;
	}

	//3.找交点
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

int main()
{

	return 0;
}