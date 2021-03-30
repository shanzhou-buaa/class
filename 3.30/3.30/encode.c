#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define range1 97
#define range2 122
//#define range1 32
//#define range2 126


typedef struct listnode
{
	char c;
	struct listnode* next;
}listnode;

int main()
{
	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("in_crpyt.txt", "w");
	char secret[40] = { 0 };
	gets(secret);
	int len = strlen(secret);
	int i = 0, j = 0, k = 0;

	//删除重复字符
	//C Programming(Second Edition)
	//C Progamin(SecdEt)
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (secret[i] == secret[j])
			{
				for (k = j; k < len - 1; k++)
				{
					secret[k] = secret[k + 1];
				}
				secret[k] = '\0';
				len--;
			}
		}
	}

	//创建循环链表
	listnode* head = NULL;
	listnode* cur = NULL;
	listnode* next = NULL;
	for (i = 0; i < len; i++)
	{
		next = (listnode*)malloc(sizeof(listnode));
		next->c = secret[i];
		if (head == NULL)
		{
			head = next;
			cur = next;
		}
		else
		{
			cur->next = next;
			cur = cur->next;
		}
	}
	//cur,next都指向最后一个字符
	//cur->next和next->next都为随机值

	//生成密钥环
	char ch = range1;
	for (; ch <= range2; ch++)
	{
		int flag = 1;
		for (i = 0; i < len; i++)
		{
			if (secret[i] == ch)
			{
				flag = 0;
			}
		}
		if (flag)
		{
			next = (listnode*)malloc(sizeof(listnode));
			next->c = ch;
			cur->next = next;
			cur = cur->next;
		}
	}
	int len2 = range2 - range1 + 1;
	listnode* tail = cur;
	tail->next = head;

	char secret1[200] = { 0 };
	for (cur = head, i = 0; cur->next != head; cur = cur->next, i++)
		secret1[i] = cur->c;
	secret[i] = cur->c;
	char secret2[200] = { 0 };

	//生成密钥
	cur = head;
	listnode* prev = tail;
	while (len2 > 0)
	{
		i = 0;
		char a = cur->c;

		//删除结点
		prev->next = cur->next;
		prev = cur;
		prev->c = 0;
		cur = cur->next;
		len2--;

		int step = 0;
		if (len2 != 0)
			step = a % len2 - 1;
		else
			step = len2 - 1;
		while (step--)
		{
			if (cur->c != 0)
			{
				prev = prev->next;
				cur = cur->next;
			}
		}
		secret2[a - range1] = cur->c;
	}
	j = 1;
	fclose(in);
	fclose(out);
	return 0;
}

//char news1[100] = { 0 };
//for (i = 0; i <= range2 - range1; i++)
//news1[i] = i + range1;
//char news2[100] = { 0 };
//for (cur = head, next = head; len2 > 0;)
//{
//	int step = next->c, pos = 0;
//	len2--;
//	for (i = 0; i <= range2 - range1; i++)
//	{
//		if (news1[i] == step)
//		{
//			pos = i;
//			break;
//		}
//	}
//	if (next == head)
//	{
//		tail->next = next->next;
//		next = next->next;
//	}
//	else
//	{
//		listnode* f = next;
//		if (cur == head)
//			tail->next = next->next;
//		else
//			cur->next = next->next;
//		next = next->next;
//		cur = cur->next;
//	}
//	listnode* temp = next;
//	if (len2 != 0)
//	{
//		step %= len2;
//		for (i = 0; i < step - 1; i++)
//			temp = temp->next;
//	}
//	news2[pos] = temp->c;
//}