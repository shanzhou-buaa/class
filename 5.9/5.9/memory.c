//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef struct Memory
//{
//	struct Memory* prev;
//	struct Memory* next;
//	int pos;
//	int length;
//}memory;
//
//void ListInsert(memory** head, int pos, int len);
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	//��������
//	memory* head = NULL;
//	int i = 0, pos = 0, len = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d%d", &pos, &len);
//		ListInsert(&head, pos, len);
//	}
//
//	//��ȡ����
//	int op[105];
//	memset(op, 0, sizeof(op));
//	i = 0;
//	while (scanf("%d", &op[i]) != EOF)
//	{
//		if (op[i] == -1)
//			break;
//		i++;
//	}
//	int num = i;//�������ĸ���+1
//
//	memory* cur = head;
//	for (i = 0; i < num; i++)
//	{
//		int size = op[i];//����Ĵ�С
//		//��ǰ�ռ�С������ģ���������
//		memory* temp = cur;
//		memory* here = cur;
//
//		int flag = 0;//��1˵�������в����ڱ�����Ĵ��
//		if (cur->length < size)
//		{
//			cur = cur->next;
//			while (cur->length < size)
//			{
//				if (cur == temp)
//				{
//					flag = 1;
//					break;
//				}
//				cur = cur->next;
//			}
//		}
//		if (flag == 1)
//			continue;
//
//		//���ڱ���Ҫ��Ľ��
//		cur = here;
//		while (cur->length < size)
//			cur = cur->next;
//
//		//��ʱcur�Ŀռ���ڵ�����Ҫ��
//		if (cur->length == size)
//		{
//			memory* prev = cur->prev;
//			memory* next = cur->next;
//			prev->next = next;
//			next->prev = prev;
//			free(cur);
//			cur = next;
//		}
//		else
//		{
//			cur->length -= size;
//		}
//	}
//	
//	memory* newhead = cur;
//	printf("%d %d\n", newhead->pos, newhead->length);
//	if (cur != newhead->next)
//	{
//		cur = newhead->next;
//		while (cur != newhead)
//		{
//			printf("%d %d\n", cur->pos, cur->length);
//			cur = cur->next;
//		}
//	}
//	return 0;
//}
//
//void ListInsert(memory** head, int pos, int len)
//{
//	if ((*head) == NULL)
//	{
//		(*head) = (memory*)malloc(sizeof(memory));
//		(*head)->next = (*head);
//		(*head)->prev = (*head);
//		(*head)->pos = pos;
//		(*head)->length = len;
//	}
//	else
//	{
//		memory* tail = (*head)->prev;
//		memory* newnode = (memory*)malloc(sizeof(memory));
//		newnode->pos = pos;
//		newnode->length = len;
//
//		newnode->prev = tail;
//		newnode->next = (*head);
//		(*head)->prev = newnode;
//		tail->next = newnode;
//	}
//}