#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct edge
{
	int path;//·�����
	int ver;//��һ����
	struct edge* next;
}edge;

typedef struct vertex
{
	int ver;//�������
	struct edge* next;
}vertex;

vertex v[5000];//�涥��
int book[5000];//�õ��Ƿ񱻱�����
int vBegin, vEnd;
edge* VertexInsert(edge* node, int end, int id);
void dfs(int n, int depth);
int path[5000];
int n;

int main()
{
	int i, e, id;
	scanf("%d%d", &n, &e);

	int v1, v2;//������������
	for (i = 0; i < e; i++)
	{
		scanf("%d%d%d", &id, &v1, &v2);

		//��������㼰��֮���·�������ڽӱ�
		v[v1].ver = v1;
		v[v1].next = VertexInsert(v[v1].next, v2, id);
		v[v2].ver = v2;
		v[v2].next = VertexInsert(v[v2].next, v1, id);
	}
	book[0] = 1;
	int depth = 0;
	dfs(0, depth);
	return 0;
}

edge* VertexInsert(edge* node, int end, int id)
{
	//�����½��
	edge* newnode = (edge*)malloc(sizeof(edge));
	newnode->ver = end;
	newnode->path = id;
	newnode->next = NULL;
	
	//��һ�����
	if (node == NULL)
		node = newnode;
	else
	{
		edge* cur = node;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = newnode;
	}
	return node;
}

void dfs(int ver, int depth)
{
	int i = 0;

	//����ȫ��
	if (ver == n - 1)
	{
		for (i = 0; i < depth; i++)
			printf("%d ", path[i]);
		printf("\n");
		return;
	}

	edge* node = v[ver].next;
	while (node != NULL)
	{
		//node���δ�����ʹ�
		if (book[node->ver] == 0)
		{
			path[depth] = node->path;//node��path����path[]��
			book[node->ver] = 1;//node��㱻����
			dfs(node->ver, depth + 1);//�ݹ�
			book[node->ver] = 0;//����
		}
		node = node->next;//node�������Ƿ���δ�����ʵĽ��
	}
}