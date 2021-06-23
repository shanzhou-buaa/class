#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int push = 0;

typedef struct station
{
	char name[20];
	int dis;
}station;

typedef struct train
{
	int index;
	char name[20];
	int state;
}train;

train stackA[55];
int sizeA = 0;
train stackB[55];
int sizeB = 0;
train stackC[55];
int sizeC = 0;

int GetDis(station* st, char* name, int station_num)
{
	int i;
	for (i = 0; i < station_num; i++)
	{
		if (strcmp(name, st[i].name) == 0)
			return st[i].dis;
	}
	return -1;
}
int main()
{
	station st[55];
	train tr[55];
	int station_num, train_num;
	scanf("%d", &station_num);
	int i, j;
	for (i = 0; i < station_num; i++)
		scanf("%s%d", st[i].name, &st[i].dis);
	scanf("%d", &train_num);
	for (i = 0; i < train_num; i++)
	{
		scanf("%d%s", &tr[i].index, tr[i].name);
		tr[i].state = 0;
		memcpy(&stackA[i], &tr[i], sizeof(train));
		sizeA++;
	}

	for (i = train_num - 1, j = 0; i >= 0; i--, j++)
	{
		memcpy(&stackB[j], &stackA[i], sizeof(train));
		sizeB++;
		sizeA--;
	}

	while (sizeB > 0)
	{
		int maxDis = 0, maxIndex = 0;
		//�ҵ���������Զ�ĳ������붥����ĳ���
		for (i = sizeB - 1; i >= 0; i--)
		{
			char name[20];
			strcpy(name, stackB[i].name);
			int temp = GetDis(st, name, station_num);
			if (temp > maxDis)
			{
				maxDis = temp;
				maxIndex = i;
			}
		}

		int init = sizeA;//��¼����֮ǰA�г������Ŀ
		int initB = sizeB;
		for (j = sizeB - 1; j >= maxIndex; j--)
		{
			//��B�е��Ƶ�Aȥ
			memcpy(&stackA[sizeA], &stackB[j], sizeof(train));
			sizeA++;
			sizeB--;
			push++;
		}

		if (initB - 1 == maxIndex)
			stackA[sizeA - 1].state = 1;
		else
		{
			//�ж�M����ͷ֮���Ƿ�ȫ����ɱ���
			int flag = 1;
			for (i = init - 1; i < sizeA; i++)
			{
				if (stackA[i].state == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0)
			{
				//�����һ�ڷŵ�C���м�ķŻ�B
				memcpy(&stackC[sizeC], &stackA[sizeA - 1], sizeof(train));
				sizeA--;
				sizeC++;

				//���м�ķŻ�B
				for (i = sizeA - 1; i >= init; i--)
				{
					memcpy(&stackB[sizeB], &stackA[i], sizeof(train));
					sizeB++;
					sizeA--;
				}

				//��C�еķŻ�A
				memcpy(&stackA[sizeA], &stackC[sizeC - 1], sizeof(train));
				stackA[sizeA].state = 1;
				push++;
				sizeA++;
				sizeC--;
			}
			if (flag == 1)
				stackA[sizeA - 1].state = 1;
		}
	}
	for (i = 0; i < train_num; i++)
		printf("%04d ", stackA[i].index);
	printf("\n%d\n", push);
	return 0;
}