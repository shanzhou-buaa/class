#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct ListNode
{
	int val;
	struct ListNode *next
};

typedef struct ListNode ln;
bool hasCycle(struct ListNode *head)
{
	ln* slow = head;
	ln* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

struct ListNode *detectCycle(struct ListNode *head)
{
	if (hasCycle(head) == false || head->next == NULL)//没有环或只有一个结点
		return NULL;

	ln* slow = head;
	ln* fast = head;
	ln* meet = NULL;//相遇点

	//代码运行到这里，说明一定要有环，找相遇点
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			meet = slow;
			break;
		}
	}
	slow = head;
	if (slow == meet)//特殊判断：头结点就是环的起点
		return meet;
	//根据公式，slow从头开始走，meet从相遇点开始走，他们会在环的入口点相遇
	else
	{
		while (1)
		{
			slow = slow->next;
			meet = meet->next;
			if (meet == slow)
				return meet;
		}
	}
}

int main()
{

	return 0;
}