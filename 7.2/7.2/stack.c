#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct func
{
	char name[20];
	char use[105][20];
	char ans[105][20];
	int useTop;
	int ansTop;
}func;

int op;
char name[20];
func stack[105];
func ans[105];//答案，只增不删
int stackTop;
int ansTop;

int main()
{
	int i, j;

	do
	{
		scanf("%d", &op);
		if (op == 8)
		{
			scanf("%s", name);
			//入stack和ans栈
			strcpy(stack[stackTop].name, name);
			strcpy(ans[ansTop].name, name);

			//stack栈顶已经有函数
			//放入stack栈顶func的栈
			if (stackTop != 0)
			{
				strcpy(stack[stackTop - 1].use[stack[stackTop - 1].useTop], name);//放到stack栈顶的func的use栈顶
				stack[stackTop - 1].useTop++;//stack栈顶的func的use个数++
				//strcpy(stack[stackTop - 1].ans[stack[stackTop - 1].ansTop], name);
				//strcpy(ans[ansTop - 1].use[stack[ansTop - 1].useTop], name);
				
				for (i = ansTop - 1; i >= 0; i--)
				{
					if (strcmp(ans[i].name, stack[stackTop - 1].name) == 0)
						break;
				}
				strcpy(ans[i].ans[ans[i].ansTop], name);//放到ans栈顶func的ans栈顶
				//stack[stackTop - 1].ansTop++;
				//ans[ansTop - 1].useTop++;
				ans[i].ansTop++;//ans栈顶func的ans个数++
			}
			//两个栈个数++
			stackTop++;
			ansTop++;
		}
		//删除
		else if (op == 0)
		{
			func* temp = &stack[stackTop - 1];//stack栈顶的函数，要被删除
			stackTop--;
			//从stack栈顶开始找有无被删除的函数temp
			for (i = stackTop - 1; i >= 0; i--)
			{
				int flag = 1;//flag==1没有
				int num = stack[i].useTop;//栈顶函数调用的函数个数
				//找stack栈中每个元素调用过的函数
				for (j = num - 1; j >= 0; j--)
				{
					if (strcmp(stack[i].use[j], temp->name) == 0)
					{
						stack[i].useTop--;//找到，该元素调用的函数--
						flag = 0;
						break;
					}
				}
				if (flag == 0)
					break;
			}
		}
	} while (stackTop != 0);

	int m, n;
	for (i = 0; i < ansTop - 1; i++)
	{
		for (j = i + 1; j < ansTop; j++)
		{
			if (strcmp(ans[i].name, ans[j].name) == 0)//有一样的合并
			{
				//前面的是0，直接换
				if (ans[i].ansTop == 0)
				{
					func temp;
					memcpy(&temp, &ans[i], sizeof(func));
					memcpy(&ans[i], &ans[j], sizeof(func));
					memcpy(&ans[j], &temp, sizeof(func));
				}
				else if (ans[j].ansTop == 0)
					continue;
				else
				{
					for (m = 0; m < ans[i].ansTop; m++)
					{
						for (n = 0; n < ans[j].ansTop; n++)
						{
							if (strcmp(ans[i].ans[m], ans[j].ans[n]) == 0)
							{
								strcpy(ans[j].ans[n], "");
							}
							else if (strcmp("", ans[i].ans[m]) != 0 && strcmp(ans[i].ans[m], ans[j].ans[n]) != 0)
							{
								strcpy(ans[i].ans[ans[i].ansTop], ans[j].ans[n]);
								ans[i].ansTop++;
							}
						}
					}
					ans[j].ansTop = 0;
				}
			}
		}
	}

	for (i = 0; i < ansTop; i++)
	{
		for (j = 0; j < ans[i].ansTop; j++)
		{
			for (int k = j + 1; k < ans[i].ansTop; k++)
			{
				if (strcmp(ans[i].ans[j], ans[i].ans[k]) == 0)
					strcpy(ans[i].ans[k], "1");
			}
		}
	}

	for (i = 0; i < ansTop; i++)
	{
		int num = ans[i].ansTop;
		if (num > 0)
		{
			printf("%s:", ans[i].name);
			for (j = 0; j < num; j++)
			{
				if (j == num - 1 && strcmp(ans[i].ans[j], "1") == 0)
					printf("\n");
				else if (j != num - 1 && strcmp(ans[i].ans[j], "1") == 0)
					continue;
				else if (strcmp(ans[i].ans[j], "1") != 0 && strcmp(ans[i].ans[j + 1], "") != 0)
				{
					printf("%s", ans[i].ans[j]);
					if (j == num - 1)
						printf("\n");
					else
						printf(",");
				}
			}
		}
	}

	return 0;
}