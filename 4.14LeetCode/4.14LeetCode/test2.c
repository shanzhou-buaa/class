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
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ln* prev = NULL;
	ln* cur = head;
	ln* next = head->next;


	while (cur->next != NULL)
	{
		cur->next = prev;
		if (cur == head)
			cur->next = NULL;
		prev = cur;
		cur = next;
		next = cur->next;
	}


	cur->next = prev;
	return cur;
}


//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	ln* cur = head;
//	ln* newHead = NULL;
//	ln* next = cur->next;
//
//
//	while (cur->next)
//	{
//		cur->next = newHead;
//		newHead = cur;
//		cur = next;
//		next = cur->next;
//	}
//	cur->next = newHead;
//	newHead = cur;
//	return newHead;
//}

int main()
{

	return 0;
}