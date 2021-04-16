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
	//���A��B����
	if (curA != curB)//���A��B�н��㣬���һ��һ��һ��
		curA = NULL;
	else
	{
		//�ó�������abs(nA - nB)������ͬʱ��ʼ��
		//һ��ͬʱ�ߵ�����
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