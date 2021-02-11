#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//a  2  2  1  7  10 5  9  72  2
//[] 0  1  2  3  4  5  6   7  8
//sz 1  2  3  4  5  6  7   8  9
//sz = 9
//
//int my_remove1(int a[], int sz, int x)
//{
//	int dest = 0, src = 0;
//	while (src < sz)
//	{
//		if (a[src] != x)
//		{
//			a[dest] = a[src];
//			dest++;
//		}
//		src++;
//	}
//	return dest;
//}
//int main()
//{
//	int a[] = { 2, 2, 1, 7, 10, 5, 9, 72, 2 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int ret = my_remove1(a, sz, 7);
//	int i;
//	for (i = 0; i < ret; i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//    return 0;
//}


//int my_remove2(int* a, int sz)
//{
//	if (sz == 0)
//		return 0;
//	int s1 = 0, s2 = 1;
//	int dst = 0;
//	while (s2 < sz)
//	{
//		if (a[s1] != a[s2])
//		{
//			a[dst] = a[s1];
//			dst++;
//		}
//		s1++;
//		s2++;
//	}
//	a[dst] = a[s1];
//	dst++;
//	return dst;
//}
//
//int main()
//{
//	//int a[] = { 1, 1, 1, 1, 1, 1, 1 };
//	//int a[] = {1,1,2,3,4,4,5,6,7,7,7,8};
//	int a[] = {1,1,1,2,2,2,2};
//	int sz = sizeof(a) / sizeof(a[0]);
//	int ret = my_remove2(a, sz);
//	int i;
//	for (i = 0; i < ret; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//struct ListNode
//{
//	struct ListNode* next;
//	int a;
//};
//struct ListNode* middleNode(struct ListNode* head){
//	int n = 1, i = 0;
//	while (head->next != NULL)
//	{
//		n++;
//		head = head->next;
//	}
//	if (n == 1)
//		return head;
//	else
//	{
//		if (n % 2 == 1)//奇数
//		{
//			n /= 2;
//			while (n--)
//			{
//				head = head->next;
//			}
//		}
//		if (n % 2 == 0)
//		{
//			n = n / 2 + 1;
//			while (n--)
//			{
//				head = head->next;
//			}
//		}
//	}
//	return head;
//}

//struct ListNode* middleNode(struct ListNode* head){
//	int len = 0;
//	struct ListNode* pNode = head;
//
//	//  获取单链表长度
//	while (pNode != NULL) {
//		len++;
//		pNode = pNode->next;
//	}
//
//	struct ListNode* Node = head;
//	//  获取中间结点位置
//	int k = (len % 2) ? (len + 1) / 2 : ((len / 2) + 1);
//	for (int i = 1; i < k; ++i) {
//		Node = Node->next;
//	}
//	return Node;
//}
//
//int main()
//{
//
//	return 0;
//}