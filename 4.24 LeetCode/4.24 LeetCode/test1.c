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

int main()
{

	return 0;
}