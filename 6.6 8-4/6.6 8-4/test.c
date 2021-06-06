#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX_NUM 1000//站的最多个数
#define MAX 99999
typedef struct station
{
	char name[50];//站名
	int change;//1为换乘站，0不是换乘站
}station;

typedef struct vertex
{
	int line;//第几号线
	int weight;//权重
}vertex;

//一条地铁线的站的个数，站的总个数，是否为换乘站
int station_num, station_total, change;
int line_total, line_index;//共多少条线，第几号线
vertex map[MAX_NUM][MAX_NUM];//图

station st[MAX_NUM];//存所有站的信息
int size;

int path[MAX_NUM][MAX_NUM];//路径
int FinalPath[MAX_NUM];//最后的路径数组
int size2;//FinalPath的大小

void Map();
int StationSearch(char* name);
void Floyd();

int main()
{
	char beginStation[50];
	char endStation[50];//起始站，终点站
	scanf("%s%s", beginStation, endStation);

	int i, j;
	for (i = 0; i < MAX_NUM; i++)
	{
		for (j = 0; j < MAX_NUM; j++)
		{
			map[i][j].line = 0;
			/*if (i == j)
				map[i][j].weight = 0;
			else*/
				map[i][j].weight = MAX;
		}
	}

	Map();//建图
	Floyd();

	int begin_index = StationSearch(beginStation);
	int end_index = StationSearch(endStation);
	//begin_index站经过path[begin_index][i]到达i站
	for (i = end_index; i != begin_index; i = path[begin_index][i])
		FinalPath[size2++] = i;
	
	//			起点          路径长度		终点
	int start = begin_index, len = 1, end = FinalPath[size2 - 1];
	int lineId = map[start][end].line;//起点的第一条线
	printf("%s-%d", st[start].name, lineId);//打印起始站和线路
	start = end;//打印起点站的下一站
	for (i = size2 - 2; i >= 0; i--)
	{
		end = FinalPath[i];
		//当前的线路和从当前的起点到下一站的线路不同，换乘
		if (lineId != map[start][end].line)
		{
			lineId = map[start][end].line;
			printf("(%d)-%s-%d", len, st[start].name, lineId);
			len = 0;
		}
		//不换乘
		len++;
		start = end;//迭代
	}
	printf("(%d)-%s\n", len, st[end_index].name);
	return 0;
}

void Map()
{
	FILE* read = fopen("bgstations.txt", "r");
	fscanf(read, "%d", &line_total);
	int i, j;
	for (i = 0; i < line_total; i++)
	{
		fscanf(read, "%d%d", &line_index, &station_num);
		int link = -1;//与上一站相连
		for (j = 0; j < station_num; j++)//遍历该号线的所有站
		{
			char name[50];
			int change;
			fscanf(read, "%s%d", name, &change);
			int flag = StationSearch(name);
			if (flag == -1)//没有这一站
			{
				//放进所有站的数组中
				strcpy(st[size].name, name);
				st[size].change = change;

				//前面有站与该站相连，放进图中
				if (link != -1)
				{
					map[link][size].line = map[size][link].line = line_index;
					map[link][size].weight = map[size][link].weight = 1;
				}
				link = size;//当前站成为下一站的起点
				size++;//站的总数++
			}
			//之前已经有过该站
			else
			{
				//link已经是一个站，把当前站link引出来连接新的站flag
				if (link != -1)
				{
					map[link][flag].line = map[flag][link].line = line_index;
					map[link][flag].weight = map[flag][link].weight = 1;
				}
				link = flag;//当前站成为下一站的起点
			}
		}
	}
	fclose(read);
}

int StationSearch(char* name)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(name, st[i].name) == 0)
			return i;
	}
	return -1;
}

void Floyd()
{
	int i, j, k;
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i != j && map[i][j].weight < MAX)
				path[i][j] = i;//从i到j走的是i
		}
	}
	//Floyd
	for (k = 0; k < size; k++)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (map[i][j].weight > map[i][k].weight + map[k][j].weight)
				{
					map[i][j].weight = map[i][k].weight + map[k][j].weight;
					path[i][j] = path[k][j];//从i到j走k中转
				}
			}
		}
	}
}