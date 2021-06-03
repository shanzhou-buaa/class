#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX 9999
#define SIZE 200

int map[SIZE][SIZE];//ͼ��[i,j]��ʾ�������㣬map[i][j]��·���ĳ���
int id[SIZE][SIZE];//id��[i,j]��ʾ�������㣬id[i][j]��·����id
int book[SIZE];//��¼ĳһ�����Ƿ��Ѿ�������
int n, e;//��������·�ĸ���

int Weight, num, path[SIZE];
//��Ȩ�أ������С������
int Path[SIZE], Id[SIZE];
int size2, size1;
void Prim(int k);

int main()
{
	int i, j, k;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			map[i][j] = MAX;
		}
	}
	int d, w;
	scanf("%d%d", &n, &e);
	for (k = 0; k < e; k++)
	{
		scanf("%d%d%d%d", &d, &i, &j, &w);//id,i,j,weight
		map[i][j] = w;
		map[j][i] = w;
		id[i][j] = d;
		id[j][i] = d;
	}
	k = 0;
	Prim(k);
	printf("%d\n", Weight);
	for (i = 0; i < size2 - 1; i++)
	{
		for (j = 0; j < size2 - i - 1; j++)
		{
			if (Path[j] > Path[j + 1])
			{
				int temp = Path[j];
				Path[j] = Path[j + 1];
				Path[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < size2; i++)
		printf("%d ", Path[i]);

	return 0;
}

void Prim(int k)
{
	if (num == n)
		return;
	book[k] = 1;//���k�Ѿ���������
	Id[size1++] = k;//k����·������
	num++;

	//�����õ���k�������ӵ�·����Сֵ
	int min = MAX, i, index1 = 0, index2 = 0, j;
	for (j = 0; j < size1; j++)//��ǰ·���ϵ����е�
	{
		int x = Id[j];//һ���㣬�����������е�
		for (i = 0; i < n; i++)
		{
			//iû����������·����̵�
			if (book[i] == 0 && map[x][i] < min)
			{
				min = map[x][i];
				index1 = x;
				index2 = i;
			}
		}
	}
	if (num != n)
	{
		Weight += min;
		Path[size2++] = id[index1][index2];
	}
	Prim(index2);
}