#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* swapNodes1(struct ListNode* head, int k){
	struct ListNode* cur = head;
	int n = 0;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	if (n == 1 || (n - k + 1 == k))
		return head;
	else if (n - k == k)
	{
		int i;
		cur = head;
		for (i = 1; i < k; i++)
		{
			cur = cur->next;
		}
		struct ListNode* next = cur->next;
		int tmp = cur->val;
		cur->val = next->val;
		next->val = tmp;
		return head;
	}
	else
	{
		int i;
		struct ListNode* first = head;
		for (i = 1; i < k; i++)
		{
			first = first->next;
		}

		struct ListNode* last = head;
		int k2 = n - k + 1;
		for (i = 1; i < k2; i++)
		{
			last = last->next;
		}

		int tmp = first->val;
		first->val = last->val;
		last->val = tmp;

		return head;
	}
}
struct ListNode* swapNodes2(struct ListNode* head, int k){
	struct ListNode* a = head;
	struct ListNode* b = head;
	struct ListNode* cur = head;
	int i = 0, n = 0;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	for (i = 1; i < k; i++)
	{
		a = a->next;
	}
	for (i = 1; i < n - k + 1; i++)
	{
		b = b->next;
	}
	int tmp = a->val;
	a->val = b->val;
	b->val = tmp;
	return head;
}