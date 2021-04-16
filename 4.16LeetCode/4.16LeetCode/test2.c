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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	int nA = 0, nB = 0;
	while (curA != NULL)
	{
		nA++;
		curA = curA->next;
	}
	while (curB != NULL)
	{
		nB++;
		curB = curB->next;
	}
	//算出A、B长度
	if (curA != curB)//如果A、B有交点，最后一个一定一样
		curA = NULL;
	else
	{
		//让长的先走abs(nA - nB)步，再同时开始走
		//一定同时走到交点
		curA = headA;
		curB = headB;
		if (nA > nB)
		{
			int n = nA - nB;
			while (n--)
			{
				curA = curA->next;
			}
			while (curA != NULL)
			{
				if (curA == curB)
				{
					break;
				}
				else
				{
					curA = curA->next;
					curB = curB->next;
				}
			}
		}
		else
		{
			int n = nB - nA;
			while (n--)
			{
				curB = curB->next;
			}
			while (curA != NULL)
			{
				if (curA == curB)
				{
					break;
				}
				else
				{
					curA = curA->next;
					curB = curB->next;
				}
			}
		}
	}
	return curA;
}

int main()
{

	return 0;
}