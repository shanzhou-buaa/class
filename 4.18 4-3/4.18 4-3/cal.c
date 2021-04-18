#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NumStack
{
	int n[10000];//��������
	int size;//��ǰջ�����ݸ���
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
	char s[10000];//�������
	int size;//��ǰջ�����ݸ���
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
	nstack ns;//����ջ
	NumStackInit(&ns);
	ostack os;//����ջ
	OpStackInit(&os);
	gets(s);
	squeez(s, ' ');//ɾ�ո�
	int i = 0, len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (isdigit(s[i]))//�������ַ���ת��Ϊint���͵�����
		{
			int temp = s[i] - '0';
			while (isdigit(s[i + 1]))
			{
				i++;
				temp = temp * 10 + s[i] - '0';
			}
			NumStackPush(&ns, temp);//������ѹ������ջ
		}
		else if (s[i] == '=')//�������
			break;
		else if (s[i] == ')')//����')'һֱ��ջֱ���ҵ�'('
		{
			while (1)
			{
				char op = OpStackTop(&os);
				OpStackPop(&os);
				if (op == '(')
					break;
				int num1 = NumStackTop(&ns);//�ó�ջ������Ԫ�ز������
				NumStackPop(&ns);
				int num2 = NumStackTop(&ns);
				NumStackPop(&ns);
				int num3 = cal(num2, num1, op);
				NumStackPush(&ns, num3);//��������ջ
			}
		}
		else//�������
		{
			if (OpStackEmpty(&os) == 0)//��ջ���������ֱ�������ջ
			{
				OpStackPush(&os, s[i]);
				continue;
			}
			char top = OpStackTop(&os);
			while (priority(top) >= priority(s[i]))//�������ջ���ķ������ȼ��ߣ������������ŵĽ������ջ
			//ֱ������ջ�������ȼ��ȵ�ǰ�ַ����е���������ȼ��ͣ������ȼ��ߵ������������ȫ����ɲ��ѽ����������ջ��
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
				if (OpStackEmpty(&os) == 0)//����ջ��
					break;
				top = OpStackTop(&os);
			}
			OpStackPush(&os, s[i]);
		}
	}
	while (OpStackEmpty(&os) != 0)//����ʣ�������
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
	//����ջ�գ�����ջ��ʣһ��Ԫ��
	int ret = NumStackTop(&ns);
	printf("%d", ret);
	return 0;
}