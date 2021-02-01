#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//判断回文串
//int main()
//{
//	char s[100];
//	while (scanf("%s", s) != EOF)
//	{
//		int i, top, next;
//		int len = strlen(s);
//		int mid = len / 2 - 1;
//		int flag = 1;
//		top = mid;
//		//"abccba"
//		//len = 6   mid = 2
//		//s[mid] = 'c'
//		if (len % 2 == 0)
//		{
//			next = mid + 1;
//		}
//		//"abcdcba"
//		//len = 7  mid = 2
//		//s[mid] = 'c'
//		else
//		{
//			next = mid + 2;
//		}
//		for (i = next; s[i] != '\0'; i++)
//		{
//			if (s[i] != s[top])
//			{
//				flag = 0;
//				break;
//			}
//			top--;
//		}
//		if (flag == 1)
//		{
//			printf("是\n");
//		}
//		else
//		{
//			printf("否\n");
//		}
//	}
//    return 0;
//}


//拉火车
////typedef struct queue
//{
//	int data[100];
//	int head;
//	int tail;
//}q;

//typedef struct stack
//{
//	int data[100];
//	int top;
//}s;

//int main()
//{
//	q q1, q2;
//	s st;
//	q1.head = 1;
//	q1.tail = 1;
//	q2.head = 1;
//	q2.tail = 1;
//	st.top = 0;
//	int i, tmp;
//	int book[20] = { 0 };
//	for (i = 1; i <= 9; i++)
//	{
//		book[i] = 0;
//	}
//	for (i = 0; i < 6; i++)
//	{
//		scanf("%d", &q1.data[q1.tail]);
//		q1.tail++;
//	}
//	for (i = 0; i < 6; i++)
//	{
//		scanf("%d", &q2.data[q2.tail]);
//		q2.tail++;
//	}
//	while (q1.head<q1.tail&&q2.head<q2.tail)
//	{
//		tmp = q1.data[q1.head];
//		if (book[tmp] == 0)
//		{
//			q1.head++;
//			st.top++;
//			st.data[st.top] = tmp;
//			book[tmp] = 1;
//		}
//		else
//		{
//			q1.head++;
//			q1.data[q1.tail] = tmp;
//			q1.tail++;
//			while (st.data[st.top] != tmp)
//			{
//				book[st.data[st.top]] = 0;
//				q1.data[q1.tail] = st.data[st.top];
//				q1.tail++;
//				st.top--;
//			}
//		}
//		tmp = q2.data[q2.head];
//		if (book[tmp] == 0)
//		{
//			q2.head++;
//			st.top++;
//			st.data[st.top] = tmp;
//			book[tmp] = 1;
//		}
//		else
//		{
//			q2.head++;
//			q2.data[q2.tail] = tmp;
//			q2.tail++;
//			while (st.data[st.top] != tmp)
//			{
//				book[st.data[st.top]] = 0;
//				q2.data[q2.tail] = st.data[st.top];
//				q2.tail++;
//				st.top--;
//			}
//		}
//	}
//	if (q2.head == q2.tail)
//	{
//		printf("玩家1赢\n");
//		printf("玩家1当前手牌：");
//		for (i = q1.head; i < q1.tail; i++)
//		{
//			printf("%d ", q1.data[i]);
//		}
//		printf("\n");
//		if (st.top > 0)
//		{
//			printf("桌上的牌：");
//			for (i = 1; i <= st.top; i++)
//			{
//				printf("%d ", st.data[i]);
//			}
//			printf("\n");
//		}
//		else
//		{
//			printf("桌上无牌\n");
//		}
//	}
//	if (q1.head == q1.tail)
//	{
//		printf("玩家2赢\n");
//		printf("玩家2当前手牌：");
//		for (i = q2.head; i <= q2.tail; i++)
//		{
//			printf("%d ", q2.data[i]);
//		}
//		printf("\n");
//		if (st.top > 0)
//		{
//			printf("桌上的牌：");
//			for (i = 1; i <= st.top; i++)
//			{
//				printf("%d ", st.data[i]);
//			}
//			printf("\n");
//		}
//		else
//		{
//			printf("桌上无牌\n");
//		}
//	}
//}


//int main()
//{
//	float a = 10.5f;
//	//1010.1
//	//1.0101 * 2 ^ 3
//	//S = 0
//	//E = 10000010
//	//01010000000000000000000
//	//0100 0001 0010 1000 0000 0000 0000 0000
//	//41 28 00 00
//	printf("%p", &a);
//}


//指针数组
//本质是数组
//存放指针的数组
//int* a[10]

//int main()
//{
//	//数组指针
//	//本质是指针
//	//是指向数组的指针
//	int arr[10] = { 0 };
//	//指针*
//	//数组的类型是int[10]
//	int(*p)[10] = &arr;
//	printf("%p\n", p);
//	printf("%p\n", p + 1);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int(*p)[10] = &arr;
//	//*p = arr
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);
//		//            *((*p)+i)也行
//	}
//	return 0;
//}


