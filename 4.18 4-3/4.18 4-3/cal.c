#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NumStack
{
	int n[10000];//数字数据
	int size;//当前栈中数据个数
}nstack;

void NumStackInit(nstack* ns)
{
	ns->size = 0;
}

void NumStackPush(nstack* ns, int num)
{
	ns->n[ns->size] = num;
	ns->size++;
}

void NumStackPop(nstack* ns)
{
	ns->size--;
}

int NumStackEmpty(nstack* ns)
{
	return ns->size;
}

int NumStackTop(nstack* ns)
{
	return ns->n[ns->size - 1];
}

typedef struct OpStack
{
	char s[10000];//计算符号
	int size;//当前栈中数据个数
}ostack;

void OpStackInit(ostack* os)
{
	os->size = 0;
}

void OpStackPush(ostack* os, char op)
{
	os->s[os->size] = op;
	os->size++;
}

void OpStackPop(ostack* os)
{
	os->size--;
}

int OpStackEmpty(ostack* os)
{
	return os->size;
}

char OpStackTop(ostack* os)
{
	return os->s[os->size - 1];
}

int cal(int x, int y, char op)
{
	if (op == '+')
		return x + y;
	else if (op == '-')
		return x - y;
	else if (op == '*')
		return x * y;
	else if (op == '/')
		return x / y;
	else
		return x % y;
}

void squeez(char* s, char c)
{
	int i, j;
	for (i = 0, j = 0; i < strlen(s); i++)
	{
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

int priority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/' || c == '%')
		return 2;
	else
		return 3;
}

int main()
{
	char s[1000] = { 0 };
	nstack ns;//数字栈
	NumStackInit(&ns);
	ostack os;//符号栈
	OpStackInit(&os);
	gets(s);
	squeez(s, ' ');//删空格
	int i = 0, len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (isdigit(s[i]))//把数字字符串转化为int类型的数字
		{
			int temp = s[i] - '0';
			while (isdigit(s[i + 1]))
			{
				i++;
				temp = temp * 10 + s[i] - '0';
			}
			NumStackPush(&ns, temp);//把数据压入数据栈
		}
		else if (s[i] == '=')//计算结束
			break;
		else if (s[i] == ')')//遇到')'一直出栈直到找到'('
		{
			while (1)
			{
				char op = OpStackTop(&os);
				OpStackPop(&os);
				if (op == '(')
					break;
				int num1 = NumStackTop(&ns);//拿出栈顶两个元素参与计算
				NumStackPop(&ns);
				int num2 = NumStackTop(&ns);
				NumStackPop(&ns);
				int num3 = cal(num2, num1, op);
				NumStackPush(&ns, num3);//计算结果入栈
			}
		}
		else//运算符号
		{
			if (OpStackEmpty(&os) == 0)//空栈，运算符号直接入符号栈
			{
				OpStackPush(&os, s[i]);
				continue;
			}
			char top = OpStackTop(&os);
			while (priority(top) >= priority(s[i]))//如果符号栈顶的符号优先级高，则计算这个符号的结果再入栈
			//直到符号栈顶的优先级比当前字符串中的运算符优先级低，即优先级高的运算符的运算全部完成并把结果刚入数据栈顶
			{
				if (top == '(')
					break;
				char op = OpStackTop(&os);
				OpStackPop(&os);
				int num1 = NumStackTop(&ns);
				NumStackPop(&ns);
				int num2 = NumStackTop(&ns);
				NumStackPop(&ns);
				int num3 = cal(num2, num1, op);
				NumStackPush(&ns, num3);
				if (OpStackEmpty(&os) == 0)//符号栈空
					break;
				top = OpStackTop(&os);
			}
			OpStackPush(&os, s[i]);
		}
	}
	while (OpStackEmpty(&os) != 0)//进行剩余的运算
	{
		char op = OpStackTop(&os);
		OpStackPop(&os);
		int num1 = NumStackTop(&ns);
		NumStackPop(&ns);
		int num2 = NumStackTop(&ns);
		NumStackPop(&ns);
		int num3 = cal(num2, num1, op);
		NumStackPush(&ns, num3);
	}
	//符号栈空，数据栈中剩一个元素
	int ret = NumStackTop(&ns);
	printf("%d", ret);
	return 0;
}