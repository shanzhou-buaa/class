#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>



 struct ListNode {
     int val;
     struct ListNode *next;
 };


typedef struct ListNode ln;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	//没有结点
	if (head == NULL)
		return NULL;
	ln* cur = head;
	ln* prev = head;
	//如果头结点是val，找到第一个不为val的结点
	while (cur != NULL && cur->val == val)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)//结点全是val
		return NULL;
	//处理正常情况
	head = cur;
	prev = cur;
	while (cur->next != NULL)
	{
		if (cur->val != val)
		{
			prev = cur;
			cur = cur->next;
		}
		else
		{
			ln* next = cur->next;
			free(cur);
			prev->next = next;
			cur = next;
		}
	}
	//最后一个结点是val
	if (cur->val == val)
	{
		free(cur);
		prev->next = NULL;
	}
	return head;
}

int main()
{

	return 0;
}