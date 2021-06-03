#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX 9999
#define SIZE 200

int map[SIZE][SIZE];//图，[i,j]表示两个顶点，map[i][j]是路径的长度
int id[SIZE][SIZE];//id，[i,j]表示两个顶点，id[i][j]是路径的id
int book[SIZE];//记录某一个点是否已经遍历过
int n, e;//顶点数，路的个数

int Weight, num, path[SIZE];
//总权重，数组大小，顶点
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
	book[k] = 1;//标记k已经被遍历过
	Id[size1++] = k;//k加入路径数组
	num++;

	//遍历得到第k个点连接的路的最小值
	int min = MAX, i, index1 = 0, index2 = 0, j;
	for (j = 0; j < size1; j++)//当前路径上的所有点
	{
		int x = Id[j];//一个点，遍历它的所有点
		for (i = 0; i < n; i++)
		{
			//i没被遍历过且路是最短的
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