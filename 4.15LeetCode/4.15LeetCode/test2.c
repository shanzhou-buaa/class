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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	// int n1 = 0, n2 = 0;
	// ln* cur = l1;
	// while(cur)
	// {
	//     n1++;
	//     cur = cur->next;
	// }
	// cur = l2;
	// while(cur)
	// {
	//     n2++;
	//     cur = cur->next;
	// }
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	ln* newnode = (ln*)malloc(sizeof(ln));
	ln* cur = newnode;
	ln* cur1 = l1;
	ln* cur2 = l2;
	while (cur1 && cur2)
	{
		if (cur1->val > cur2->val)
		{
			newnode->next = cur2;
			//newnode->val = cur2->val;
			newnode = newnode->next;
			cur2 = cur2->next;
		}
		else
		{
			newnode->next = cur1;
			//newnode->val = cur1->val;
			newnode = newnode->next;
			cur1 = cur1->next;
		}
	}
	while (cur1)
	{
		newnode->next = cur1;
		//newnode->val = cur1->val;
		newnode = newnode->next;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		newnode->next = cur2;
		//newnode->val = cur2->val;
		newnode = newnode->next;
		cur2 = cur2->next;
	}
	ln* head = cur->next;
	free(cur);
	return head;
}

int main()
{

	return 0;
}