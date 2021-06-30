#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct file
{
	char name[20];
	char parent[200];
	int type;
	char date[20];
	struct file* child[200];//����
	int index;
	int num;//���ӵ�����
	int level;
}file;

file arr[1000];
file path[100];
int pathNum = 0;
file finalPath[100][100];
int finalPathNum = 0;

file* FindFather(file* root, char* s);
void TreeFind(int index, char * s);

int main()
{
	FILE* in = fopen("files.txt", "r");
	int n = 49, i, j, k;
	char find[20] = "test.c";
	//scanf("%d%s", &n, find);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%s%s%d%s", arr[i].name, arr[i].parent, &arr[i].type, arr[i].date);
		arr[i].index = i;
		//�ҵ������
		if (i == 0)
			arr[i].level = 1;
		for (k = 0; k < i; k++)
		{
			if (strcmp(arr[k].name, arr[i].parent) == 0)
				break;
		}
		file* parent = &arr[k];

		//���ӽ��Ž�������ָ������
		if (k != i)
		{
			for (j = 0; j <= parent->num; j++)
			{
				if (parent->child[j] == NULL)
				{
					parent->child[j] = &arr[i];
					arr[i].level = parent->level + 1;
					parent->num++;
					break;
				}
			}
		}
	}
	fprint()
	TreeFind(0, find);
	return 0;
}

void TreeFind(int index, char * s)
{
	if (strcmp(arr[index].name, s) == 0)
	{
		path[pathNum++] = arr[index];
		memcpy(finalPath[finalPathNum], path, sizeof(path));
		
		//for (int i = 0; i < pathNum; i++)
		//{
		//	printf("%s", path[i].name);
		//	if (i == 0)
		//		printf(":\\");
		//	else
		//		printf("\\");
		//}
		//printf("%s\n", s);
		return;
	}
	else
	{
		int i = 0;
		path[pathNum++] = arr[index];
		//�������к���
		for (i = 0; i < arr[index].num; i++)
		{
			TreeFind(arr[index].child[i]->index, s);
			pathNum--;
		}
	}
}