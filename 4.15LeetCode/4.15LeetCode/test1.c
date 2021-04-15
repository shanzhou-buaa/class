#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

typedef struct ListNode ln;
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	int n = 0;
	ln* cur = head;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	ln* slow = head;
	ln* fast = head;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{

	return 0;
}