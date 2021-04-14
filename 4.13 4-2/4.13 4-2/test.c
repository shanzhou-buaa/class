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
	int capacity;//最大存放的数据个数
	int size;//当前的数据个数
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
	int line = 0, index = 0, flag = 1;//flag判断现在是否是在/* */中，1说明不在
	bracket b[100];
	int i = 0, j = 0;
	FILE* in = fopen("example.c", "r");

	//把字符串中的括号拿到b数组中
	//while (fgets(s, 1024, stdin) != NULL)
	while (fgets(s, 1024, in) != NULL)
	{
		line++;
		int len = strlen(s);

		//删除双引号中的内容
		for (i = 0; i < len - 1; i++)
		{
			if (s[i] == '"')
			{
				for (j = len - 1; j >= i + 1; j--)
				{
					if (s[j] == '"')
					{
						strcpy(s + i, s + j + 1);
						len = strlen(s);//更新len
						break;
					}
				}
			}
		}

		//strcpy时没考虑越界，可能有问题
		
		//删除注释
		//1.flag = 0说明当前内容在/*注释中，且/*不在该行
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
			if (flag == 1)//如果该行有*/
				strcpy(s, s + i + 2);//该行存储到s中的内容为非注释内容
		}
		if (flag == 0)
			continue;
		len = strlen(s);//更新len

		//2.某行中出现/*
		//没有/**/，pos1 = 0，sign = 0
		//有/*没*/， pos1 != 0, sign = 0
		// /**/都有，pos1 != 0, sign = 1
		int pos1 = -1, pos2 = 0, sign = 0;
		for (i = 0; i < len - 1; i++)
		{
			sign = 0;//sign是0说明没找到匹配的*/
			//sign是1说明找到匹配的*/
			if (s[i] == '/' && s[i + 1] == '*')
			{
				pos1 = i;//pos1是/*的起始位置
				flag = 0;
				for (j = i + 2; j < len - 1; j++)
				{
					//存在匹配的*/
					if (s[j] == '*' && s[j + 1] == '/')
					{
						pos2 = j;//pos2是*/的结束位置
						strcpy(s + pos1, s + pos2 + 2);
						len = strlen(s);//更新len
						flag = 1;
						sign = 1;
						break;
					}
				}
				//无匹配的*/
				if (sign == 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if (sign == 0 && pos1 != -1)//该行从pos1开始是/*的注释，且没有*/
			s[pos1] = '\0';
		len = strlen(s);//更新len
		//3.某行中存在//
		for (i = 0; i < len - 1; i++)
		{
			if (s[i] == '/' && s[i + 1] == '/')
				s[i] = '\0';
		}
		len = strlen(s);//更新len
		
		//把括号存起来
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
	
	//tmpb貌似多余
	bracket tmpb[100];
	memcpy(tmpb, b, sizeof(b));
	char tmp = 0;
	stack st;
	StackInit(&st);
	for (i = 0; i < index; i++)
	{
		if (isLeft(tmpb[i].c))
			StackPush(&st, tmpb[i]);//左括号入栈
		if (isRight(tmpb[i].c))
		{
			tmp = StackPop(&st).c;//碰到右括号找最近的（栈顶的）左括号和它匹配
			if (Match(tmp, tmpb[i].c))
				tmpb[i].line = -1;//可能没用
			else
			{
				printf("without maching '%c' at line %d", tmpb[i].c, tmpb[i].line);
				return 0;
			}
		}
	}
	if (GetSize(&st) == 0)//栈为空
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