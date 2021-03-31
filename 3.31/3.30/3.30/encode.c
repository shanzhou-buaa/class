#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//#define range1 97
//#define range2 122
#define range1 32
#define range2 126


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

	//ɾ���ظ��ַ�
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

	//����ѭ������
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
	//cur,next��ָ�����һ���ַ�
	//cur->next��next->next��Ϊ���ֵ

	//������Կ��
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
	secret1[i] = cur->c;
	char secret2[200] = { 0 };

	//for (cur = head; cur->next != head; cur = cur->next)
	//	printf("%c ", cur->c);
	//printf("%c\n", cur->c);

	//������Կ
	cur = head;
	listnode* prev = tail;
	char a = 0;
	while (len2 > 0)
	{
		a = cur->c;//�õ��ַ�
		if (len2 == 1)
			break;

		cur->c = 0;//ɾ���ýڵ㣨��Ϊ0��
		len2--;//����-1

		//Ų����������һ����Ϊ0�Ľ��
		//ֻҪû��break��һ������һ��
		while (cur->c == 0)
			cur = cur->next;
		prev->next = cur;//��prev��cur������

		
		int step = a - 1;
		while (step--)//��cur������
		{
			//�ҵ���Ϊ0�Ľ��Ϊһ��
			if (cur->c == 0)
			{
				while (cur->c == 0)
				{
					prev = prev->next;
					cur = cur->next;
				}
			}
			//�������ֱ�����Ųһ��
			else
			{
				prev = prev->next;
				cur = cur->next;
			}
		}
		secret2[a - range1] = cur->c;
	}

	//break;ʱprevָ�����һ����������ַ�
	//cur��next��ָ��cur
	secret2[a - range1] = prev->c;

	char s[1024] = { 0 };
	while (fgets(s, 1000, in) != NULL)
	{
		int len3 = strlen(s);
		for (i = 0; i < len3; i++)
		{
			if (s[i] >= 32 && s[i] <= 126)
				fputc(secret2[s[i] - range1], out);
			else
				fputc(s[i], out);
		}
	}

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

//i = 0;
//while (cur->c == 0)//���ַ���Ϊ0�Ľ��
//cur = cur->next;
//a = cur->c;
//
////ɾ�����
//if (cur->next->c == 0)
//{
//	listnode* temp = cur;
//	while (temp->next->c == 0)
//		temp = temp->next;
//	prev = temp;
//	cur = temp->next;
//}
//else
//{
//	prev->next = cur->next;
//	prev = cur;
//}
//cur->c = 0;
//cur = cur->next;
//len2--;
//
//if (len2 == 0)
//break;
//
////ǰ������
//int step = 0;
//if (len2 != 0)
//step = a % len2 - 1;
//else
//step = len2 - 1;
//if (step < 0)
//	step += len2;
//
////�ҵ���Ӧ����ĸ
//while (step--)
//{
//	while (cur->next->c == 0)
//		cur = cur->next;
//	while (prev->next->c == 0)
//		prev = prev->next;
//	//while (cur->c == 0)
//	prev = prev->next;
//	cur = cur->next;
//}
//secret2[a - range1] = cur->c;