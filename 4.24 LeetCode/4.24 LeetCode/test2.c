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
	if (hasCycle(head) == false || head->next == NULL)//û�л���ֻ��һ�����
		return NULL;

	ln* slow = head;
	ln* fast = head;
	ln* meet = NULL;//������

	//�������е����˵��һ��Ҫ�л�����������
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
	if (slow == meet)//�����жϣ�ͷ�����ǻ������
		return meet;
	//���ݹ�ʽ��slow��ͷ��ʼ�ߣ�meet�������㿪ʼ�ߣ����ǻ��ڻ�����ڵ�����
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