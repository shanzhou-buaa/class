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
bool isPalindrome(struct ListNode* head)
{
	if (head == NULL)
		return true;
	//1.�ҵ��м���
	ln* slow = head;
	ln* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//slowָ���м���

	//2.��ת����
	ln* cur = slow;
	ln* newhead = NULL;
	ln* next = slow;
	while (cur)
	{
		next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}

	// while(newhead)
	// {
	//     printf("%d ", newhead->val);
	//     newhead = newhead->next;
	// }  

	//3.�Ƚ����ν��
	while (newhead && head)
	{
		if (newhead->val != head->val)
			return false;
		newhead = newhead->next;
		head = head->next;
	}

	return true;
}

int main()
{

	return 0;
}