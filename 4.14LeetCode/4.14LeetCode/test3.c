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

//法一：遍历链表，计数n个
//n为奇数，找第n/2个
//n为偶数，找第1 + n/2个


// struct ListNode* middleNode(struct ListNode* head){
//     int n = 1;
//     struct ListNode* LN = head;
//     while(LN->next != NULL)
//     {
//         n++;
//         LN = LN->next;
//     }
//     int len = (n % 2 == 1) ?(n / 2):(1 + n / 2) - 1;
//     while(len--)
//     {
//         head = head->next;
//     }
//     return head;
// }


//法二：快慢指针
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main()
{

	return 0;
}