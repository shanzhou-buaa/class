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
func ans[105];//�𰸣�ֻ����ɾ
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
			//��stack��ansջ
			strcpy(stack[stackTop].name, name);
			strcpy(ans[ansTop].name, name);

			//stackջ���Ѿ��к���
			//����stackջ��func��ջ
			if (stackTop != 0)
			{
				strcpy(stack[stackTop - 1].use[stack[stackTop - 1].useTop], name);//�ŵ�stackջ����func��useջ��
				stack[stackTop - 1].useTop++;//stackջ����func��use����++
				//strcpy(stack[stackTop - 1].ans[stack[stackTop - 1].ansTop], name);
				//strcpy(ans[ansTop - 1].use[stack[ansTop - 1].useTop], name);
				
				for (i = ansTop - 1; i >= 0; i--)
				{
					if (strcmp(ans[i].name, stack[stackTop - 1].name) == 0)
						break;
				}
				strcpy(ans[i].ans[ans[i].ansTop], name);//�ŵ�ansջ��func��ansջ��
				//stack[stackTop - 1].ansTop++;
				//ans[ansTop - 1].useTop++;
				ans[i].ansTop++;//ansջ��func��ans����++
			}
			//����ջ����++
			stackTop++;
			ansTop++;
		}
		//ɾ��
		else if (op == 0)
		{
			func* temp = &stack[stackTop - 1];//stackջ���ĺ�����Ҫ��ɾ��
			stackTop--;
			//��stackջ����ʼ�����ޱ�ɾ���ĺ���temp
			for (i = stackTop - 1; i >= 0; i--)
			{
				int flag = 1;//flag==1û��
				int num = stack[i].useTop;//ջ���������õĺ�������
				//��stackջ��ÿ��Ԫ�ص��ù��ĺ���
				for (j = num - 1; j >= 0; j--)
				{
					if (strcmp(stack[i].use[j], temp->name) == 0)
					{
						stack[i].useTop--;//�ҵ�����Ԫ�ص��õĺ���--
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
			if (strcmp(ans[i].name, ans[j].name) == 0)//��һ���ĺϲ�
			{
				//ǰ�����0��ֱ�ӻ�
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