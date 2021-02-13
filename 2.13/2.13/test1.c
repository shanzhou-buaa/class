#include "queue.h"
#include "stack.h"

//struct ListNode {
//	int val;
//	struct ListNode *next;
//	
//};
//
//struct ListNode *detectCycle(struct ListNode *head) {
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	int sum = 0, n = 0;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (fast == slow)
//		{
//			struct ListNode* meet = slow;
//			struct ListNode* cur = head;
//			while (cur != meet)
//			{
//				cur = cur->next;
//				meet = meet->next;
//			}
//			return cur;
//		}
//	}
//	return NULL;
//}


void test1()
{
	ST s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackDestroy(&s);
}
int main()
{
	test1();
    return 0;
}