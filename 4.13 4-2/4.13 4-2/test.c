#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct bracket
{
	char c;
	int line;
}bracket;

typedef struct Stack
{
	bracket* a;
	int capacity;//����ŵ����ݸ���
	int size;//��ǰ�����ݸ���
}stack;

void StackInit(stack* s)
{
	s->a = (bracket*)malloc(sizeof(bracket)* 1000);
	s->capacity = 1000;
	s->size = 0;
}

void StackPush(stack* s, bracket x)
{
	s->a[s->size].c = x.c;
	s->a[s->size].line = x.line;
	s->size++;
}

bracket StackPop(stack* s)
{
	int tail = s->size;
	s->size--;
	return s->a[tail - 1];
}

int GetSize(stack* s)
{
	return s->size;
}

int isBracket(char c)
{
	if (c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']')
		return 1;
	return 0;
}

int isLeft(char c)
{
	if (c == '{' || c == '(' || c == '[')
		return 1;
	return 0;
}

int isRight(char c)
{
	if (c == '}' || c == ')' || c == ']')
		return 1;
	return 0;
}

int Match(char a, char b)
{
	if ((a == '(' && b == ')') ||
		(a == '[' && b == ']') ||
		(a == '{' && b == '}'))
	{
		return 1;
	}
	return 0;
}

int main()
{
	char s[100] = { 0 };
	int line = 0, index = 0, flag = 1;//flag�ж������Ƿ�����/* */�У�1˵������
	bracket b[100];
	int i = 0, j = 0;
	FILE* in = fopen("example.c", "r");

	//���ַ����е������õ�b������
	//while (fgets(s, 1024, stdin) != NULL)
	while (fgets(s, 1024, in) != NULL)
	{
		line++;
		int len = strlen(s);

		//ɾ��˫�����е�����
		for (i = 0; i < len - 1; i++)
		{
			if (s[i] == '"')
			{
				for (j = len - 1; j >= i + 1; j--)
				{
					if (s[j] == '"')
					{
						strcpy(s + i, s + j + 1);
						len = strlen(s);//����len
						break;
					}
				}
			}
		}

		//strcpyʱû����Խ�磬����������
		
		//ɾ��ע��
		//1.flag = 0˵����ǰ������/*ע���У���/*���ڸ���
		if (flag == 0)
		{
			for (i = 0; i < len - 1; i++)
			{
				if (s[i] == '*' && s[i + 1] == '/')
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)//���������*/
				strcpy(s, s + i + 2);//���д洢��s�е�����Ϊ��ע������
		}
		if (flag == 0)
			continue;
		len = strlen(s);//����len

		//2.ĳ���г���/*
		//û��/**/��pos1 = 0��sign = 0
		//��/*û*/�� pos1 != 0, sign = 0
		// /**/���У�pos1 != 0, sign = 1
		int pos1 = -1, pos2 = 0, sign = 0;
		for (i = 0; i < len - 1; i++)
		{
			sign = 0;//sign��0˵��û�ҵ�ƥ���*/
			//sign��1˵���ҵ�ƥ���*/
			if (s[i] == '/' && s[i + 1] == '*')
			{
				pos1 = i;//pos1��/*����ʼλ��
				flag = 0;
				for (j = i + 2; j < len - 1; j++)
				{
					//����ƥ���*/
					if (s[j] == '*' && s[j + 1] == '/')
					{
						pos2 = j;//pos2��*/�Ľ���λ��
						strcpy(s + pos1, s + pos2 + 2);
						len = strlen(s);//����len
						flag = 1;
						sign = 1;
						break;
					}
				}
				//��ƥ���*/
				if (sign == 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if (sign == 0 && pos1 != -1)//���д�pos1��ʼ��/*��ע�ͣ���û��*/
			s[pos1] = '\0';
		len = strlen(s);//����len
		//3.ĳ���д���//
		for (i = 0; i < len - 1; i++)
		{
			if (s[i] == '/' && s[i + 1] == '/')
				s[i] = '\0';
		}
		len = strlen(s);//����len
		
		//�����Ŵ�����
		for (i = 0; i < len; i++)
		{
			if (isBracket(s[i]))
			{
				b[index].c = s[i];
				b[index].line = line;
				index++;
			}
		}
	}
	
	//tmpbò�ƶ���
	bracket tmpb[100];
	memcpy(tmpb, b, sizeof(b));
	char tmp = 0;
	stack st;
	StackInit(&st);
	for (i = 0; i < index; i++)
	{
		if (isLeft(tmpb[i].c))
			StackPush(&st, tmpb[i]);//��������ջ
		if (isRight(tmpb[i].c))
		{
			tmp = StackPop(&st).c;//����������������ģ�ջ���ģ������ź���ƥ��
			if (Match(tmp, tmpb[i].c))
				tmpb[i].line = -1;//����û��
			else
			{
				printf("without maching '%c' at line %d", tmpb[i].c, tmpb[i].line);
				return 0;
			}
		}
	}
	if (GetSize(&st) == 0)//ջΪ��
	{
		for (i = 0; i < index; i++)
			printf("%c", b[i].c);
	}
	else
	{
		bracket temp = StackPop(&st);
		printf("without maching '%c' at line %d", temp.c, temp.line);
	}
	fclose(in);
	return 0;
}