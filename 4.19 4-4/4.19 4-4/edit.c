#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Stack
{
	char a[20][600];
	int size;
}stack;

void StackInit(stack* s)
{
	memset(s->a, 0, sizeof(s->a));
	s->size = 0;
}

void StackPush(stack* s, char* str)
{
	strcpy(s->a[s->size], str);
	s->size++;
}

void StackPop(stack* s)
{
	s->size--;
}

char* StackTop(stack* s)
{
	return s->a[s->size - 1];
}

//�շ���0
int isEmpty(stack* s)
{
	return s->size;
}

void Insert(char* text, int pos, char* s)//��s�����ݲ��뵽text��posλ��
{
	int len1 = strlen(text);
	int len2 = strlen(s);
	int newlen = len1 + len2;
	*(text + newlen) = '\0';
	memmove(text + pos + len2, text + pos, len1 - pos);//��pos�Ժ�ԭ��������������
	memcpy(text + pos, s, len2);//��s���Ƶ�pos
}

void Erase(char* text, int pos, int num, char* del)
{
	int len = strlen(text);
	int i = 0;
	if (del != NULL)
	{
		if (num > len - pos)
			num = len - pos;
		for (i = pos; i < num + pos; i++)
			del[i - pos] = text[i];
	}
	memmove(text + pos, text + pos + num, len - pos - num);
	*(text + len - num) = '\0';
}

int main()
{
	stack st;//�洦������еĲ���������������һ��ջ
	StackInit(&st);
	char next[100][600];//�洦��֮��Ĳ���
	char text[600] = { 0 };
	gets(text);
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	getchar();//�̵�n����Ļس�
	char tmps[600];
	for (i = 0; i < n; i++)
	{
		gets(tmps);
		StackPush(&st, tmps);
	}
	i = 0;
	getchar();//�̵�����
	while (gets(next[i]) != NULL)
		i++;
	//int size1 = n;
	int size2 = i;
	
	char option = 0;
	int pos = 0;
	for (i = 0; i < size2; i++)
	{
		option = next[i][0];//�õ�������
		if (option == '1')//�����ַ���
		{
			StackPush(&st, next[i]);
			j = 2;//����
			pos = 0;
			while (isdigit(next[i][j]))
			{
				pos = pos * 10 + next[i][j] - '0';
				j++;
			}
			Insert(text, pos, next[i] + j + 1);
		}
		else if (option == '2')
		{
			j = 2;//����
			pos = 0;
			while (isdigit(next[i][j]))
			{
				pos = pos * 10 + next[i][j] - '0';
				j++;
			}

			j++;//�����ո�
			int pos2 = j;//��ű�ɾ���ַ�����λ��
			char del[600] = { 0 };//��ű�ɾ�����ַ���
			int num = 0;
			while (isdigit(next[i][j]))
			{
				num = num * 10 + next[i][j] - '0';
				j++;
			}
			Erase(text, pos, num, del);
			strcpy(next[i] + pos2, del);
			StackPush(&st, next[i]);
		}
		else if (option == '-')
		{
			printf("%s", text);
			return 0;
		}
		else if(option == '3')
		{
			if (isEmpty(&st) == 0)
				continue;
			else
			{
				//�ó�ջ��Ԫ��
				char* tmpc = StackTop(&st);
				char str[600];
				strcpy(str, tmpc);
				StackPop(&st);
				option = str[0];


				if (option == '1')
				{
					j = 2;//����
					pos = 0;
					while (isdigit(str[j]))
					{
						pos = pos * 10 + str[j] - '0';
						j++;
					}
					j++;
					int len = strlen(str + j);
					Erase(text, pos, len, NULL);//�����е�ɾ���������ü�¼��ɾ��������
				}
				else if (option == '2')
				{
					j = 2;//����
					pos = 0;
					while (isdigit(str[j]))
					{
						pos = pos * 10 + str[j] - '0';
						j++;
					}

					j++;//�����ո�
					Insert(text, pos, str + j);
				}
			}
		}
	}
	return 0;
}