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
	//1.����A,B�ĳ���
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
	if (cur1 != cur2)//�ж��ཻ�����ཻ��βһ����ͬ
		return NULL;

	//2.�̵���������abs(nA - nB)��
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

	//3.�ҽ���
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