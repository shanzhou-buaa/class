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
	//û�н��
	if (head == NULL)
		return NULL;
	ln* cur = head;
	ln* prev = head;
	//���ͷ�����val���ҵ���һ����Ϊval�Ľ��
	while (cur != NULL && cur->val == val)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)//���ȫ��val
		return NULL;
	//�����������
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
	//���һ�������val
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