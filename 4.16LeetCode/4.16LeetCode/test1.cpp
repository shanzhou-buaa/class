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
class Partition
{
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		if (!pHead)
			return NULL;
		ln* lessHead = (ln*)malloc(sizeof(ln));
		ln* lessTail = lessHead;
		ln* greaterHead = (ln*)malloc(sizeof(ln));
		ln* greaterTail = greaterHead;
		lessTail->next = NULL;
		greaterTail->next = NULL;
		ln* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
			}
			cur = cur->next;
		}
		lessTail->next = greaterHead->next;
		greaterTail->next = NULL;

		pHead = lessHead->next;
		free(lessHead);
		free(greaterHead);
		return pHead;
	}
};

int main()
{

	return 0;
}