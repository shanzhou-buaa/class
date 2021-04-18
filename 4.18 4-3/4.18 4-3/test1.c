//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
//typedef struct Stack
//{
//	int* a;
//	int capacity;//最大存放的数据个数
//	int size;//当前的数据个数
//}stack;
//
//void StackInit(stack* s)
//{
//	s->a = (int*)malloc(sizeof(int)* 100);
//	s->capacity = 100;
//	s->size = 0;
//}
//
//void StackPush(stack* s, int x)
//{
//	s->a[s->size] = x;
//	s->size++;
//}
//
//int StackPop(stack* s)
//{
//	int tail = s->size;
//	s->size--;
//	return s->a[tail - 1];
//}
//
//int GetSize(stack* s)
//{
//	return s->size;
//}
//
//int cal(int x, int y, char op)
//{
//	if (op == '+')
//		return x + y;
//	else if (op == '-')
//		return x - y;
//	else if (op == '*')
//		return x * y;
//	else if (op == '/')
//		return x / y;
//	else
//		return x % y;
//}
//
////42* 43+ 45- 47/ 37%
//void squeez(char* s, char c)
//{
//	int i, j;
//	for (i = 0, j = 0; i < strlen(s); i++)
//	{
//		if (s[i] != c)
//			s[j++] = s[i];
//	}
//	s[j] = '\0';
//}
//
//int priority(char c)
//{
//	if (c == '+' || c == '-')
//		return 1;
//	else if (c == '*' || c == '/' || c == '%')
//		return 2;
//	//else if (c == '=')
//	//	return 
//}
//
//int isop(char c)
//{
//	if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%')
//		return 1;
//	return 0;
//}
//
//void StackPrint(stack* s)
//{
//	int i = 0;
//	for (i = 0; i < s->size; i++)
//		printf("%d ", s->a[i]);
//	printf("\n");
//}
//
//int main()
//{
//	char s[1000] = { 0 };
//	stack st;
//	StackInit(&st);
//	gets(s);
//	squeez(s, ' ');
//	int len = strlen(s);
//	int i = 0, j = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (isdigit(s[i]))
//		{
//			int temp = s[i] - '0';
//			while (isdigit(s[i + 1]))
//			{
//				i++;
//				temp = temp * 10 + s[i] - '0';
//			}
//			StackPush(&st, temp);
//			continue;
//		}
//		else if (s[i] == '=')
//			break;
//		else if (isop(s[i]))
//		{
//			//该符号和下一个或下面多个优先级相同
//			while (priority(s[i]) == priority(s[i + 2]) || s[i + 2] == '=')
//			{
//				int op = s[i];
//				i++;
//				int temp = s[i] - '0';
//				while (isdigit(s[i + 1]))
//				{
//					i++;
//					temp = temp * 10 + s[i] - '0';
//				}
//				StackPush(&st, temp);
//				StackPush(&st, op);
//				i++;
//			}
//			if (1);
//		}
//	}
//	StackPrint(&st);
//	return 0;
//}