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

		//�ҵ�λ��
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

		//���ӵ��µ�������
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