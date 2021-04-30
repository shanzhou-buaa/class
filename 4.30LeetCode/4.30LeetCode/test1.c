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

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ln;
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ln* cur = head;
	ln* next = head->next;
	ln* prev = NULL;

	while (next)
	{
		if (cur->val != next->val)
		{
			prev = cur;
			cur = cur->next;
			next = next->next;
		}
		else
		{
			while (next && cur->val == next->val)
			{
				next = next->next;
			}
			cur = next;
			if (prev == NULL)
			{
				head = cur;
			}
			else
			{
				prev->next = cur;
			}
			if (next)
				next = next->next;
		}
	}
	return head;
}

int main()
{

	return 0;
}