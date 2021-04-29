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
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (!head || head->next == NULL)
		return head;

	ln* cur = head->next;

	ln* newHead = head;
	newHead->next = NULL;

	while (cur)
	{
		ln* next = cur->next;
		ln* newCur = newHead;
		ln* newPrev = NULL;

		//找到位置
		while (newCur)
		{
			if (newCur->val > cur->val)
			{
				break;
			}
			else
			{
				newPrev = newCur;
				newCur = newCur->next;
			}
		}

		//连接到新的链表中
		if (newPrev == NULL)
		{
			cur->next = newHead;
			newHead = cur;
		}
		else
		{
			newPrev->next = cur;
			cur->next = newCur;
		}

		cur = next;
	}

	return newHead;
}

int main()
{

	return 0;
}