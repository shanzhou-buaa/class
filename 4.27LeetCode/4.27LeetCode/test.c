#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
	int val;
	struct Node *next;
	struct Node *random;
	
};

typedef struct Node node;
struct Node* copyRandomList(struct Node* head)
{
	//空链表直接返回
	if (head == NULL)
		return NULL;

	node* cur = head;
	node* copy = NULL;
	node* copyNext = NULL;
	while (cur)
	{
		//复制一个当前结点
		copy = (node*)malloc(sizeof(node));
		copy->val = cur->val;
		copy->next = cur->next;
		cur->next = copy;
		cur = copy->next;//迭代
	}

	// node* cur = head;
	// while(cur)
	// {
	//     node* next = cur->next;
	//     node* copy = (node*)malloc(sizeof(node));
	//     copy->val = cur->val;
	//     cur->next = copy;
	//     copy->next = next;

	//     cur = next;
	// }

	//调整复制出来的结点的random
	cur = head;
	while (cur)
	{
		copy = cur->next;

		if (cur->random != NULL)
			copy->random = cur->random->next;
		else
			copy->random = NULL;

		if (cur->next != NULL)
			cur = cur->next->next;
		else
			break;

		cur = copy->next;
	}



	//删除原来的结点
	cur = head;
	node* copyHead = (node*)malloc(sizeof(node));
	node* copyTail = copyHead;
	while (cur)
	{
		copy = cur->next;
		node *next = copy->next;

		copyTail->next = copy;
		copyTail = copyTail->next;

		cur->next = next;
		cur = next;
	}

	node* guard = copyHead;
	copyHead = guard->next;
	free(guard);
	return copyHead;
}

int main()
{

	return 0;
}