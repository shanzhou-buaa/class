#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX_NUM 1000//վ��������
#define MAX 99999
typedef struct station
{
	char name[50];//վ��
	int change;//1Ϊ����վ��0���ǻ���վ
}station;

typedef struct vertex
{
	int line;//�ڼ�����
	int weight;//Ȩ��
}vertex;

//һ�������ߵ�վ�ĸ�����վ���ܸ������Ƿ�Ϊ����վ
int station_num, station_total, change;
int line_total, line_index;//���������ߣ��ڼ�����
vertex map[MAX_NUM][MAX_NUM];//ͼ

station st[MAX_NUM];//������վ����Ϣ
int size;

int path[MAX_NUM][MAX_NUM];//·��
int FinalPath[MAX_NUM];//����·������
int size2;//FinalPath�Ĵ�С

void Map();
int StationSearch(char* name);
void Floyd();

int main()
{
	char beginStation[50];
	char endStation[50];//��ʼվ���յ�վ
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

	Map();//��ͼ
	Floyd();

	int begin_index = StationSearch(beginStation);
	int end_index = StationSearch(endStation);
	//begin_indexվ����path[begin_index][i]����iվ
	for (i = end_index; i != begin_index; i = path[begin_index][i])
		FinalPath[size2++] = i;
	
	//			���          ·������		�յ�
	int start = begin_index, len = 1, end = FinalPath[size2 - 1];
	int lineId = map[start][end].line;//���ĵ�һ����
	printf("%s-%d", st[start].name, lineId);//��ӡ��ʼվ����·
	start = end;//��ӡ���վ����һվ
	for (i = size2 - 2; i >= 0; i--)
	{
		end = FinalPath[i];
		//��ǰ����·�ʹӵ�ǰ����㵽��һվ����·��ͬ������
		if (lineId != map[start][end].line)
		{
			lineId = map[start][end].line;
			printf("(%d)-%s-%d", len, st[start].name, lineId);
			len = 0;
		}
		//������
		len++;
		start = end;//����
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
		int link = -1;//����һվ����
		for (j = 0; j < station_num; j++)//�����ú��ߵ�����վ
		{
			char name[50];
			int change;
			fscanf(read, "%s%d", name, &change);
			int flag = StationSearch(name);
			if (flag == -1)//û����һվ
			{
				//�Ž�����վ��������
				strcpy(st[size].name, name);
				st[size].change = change;

				//ǰ����վ���վ�������Ž�ͼ��
				if (link != -1)
				{
					map[link][size].line = map[size][link].line = line_index;
					map[link][size].weight = map[size][link].weight = 1;
				}
				link = size;//��ǰվ��Ϊ��һվ�����
				size++;//վ������++
			}
			//֮ǰ�Ѿ��й���վ
			else
			{
				//link�Ѿ���һ��վ���ѵ�ǰվlink�����������µ�վflag
				if (link != -1)
				{
					map[link][flag].line = map[flag][link].line = line_index;
					map[link][flag].weight = map[flag][link].weight = 1;
				}
				link = flag;//��ǰվ��Ϊ��һվ�����
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
				path[i][j] = i;//��i��j�ߵ���i
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
					path[i][j] = path[k][j];//��i��j��k��ת
				}
			}
		}
	}
}