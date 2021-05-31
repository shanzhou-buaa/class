#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct edge
{
	int path;//路径序号
	int ver;//另一个点
	struct edge* next;
}edge;

typedef struct vertex
{
	int ver;//顶点序号
	struct edge* next;
}vertex;

vertex v[5000];//存顶点
int book[5000];//该点是否被遍历过
int vBegin, vEnd;
edge* VertexInsert(edge* node, int end, int id);
void dfs(int n, int depth);
int path[5000];
int n;

int main()
{
	int i, e, id;
	scanf("%d%d", &n, &e);

	int v1, v2;//输入的两个结点
	for (i = 0; i < e; i++)
	{
		scanf("%d%d%d", &id, &v1, &v2);

		//把两个结点及其之间的路径输入邻接表
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
	//创建新结点
	edge* newnode = (edge*)malloc(sizeof(edge));
	newnode->ver = end;
	newnode->path = id;
	newnode->next = NULL;
	
	//第一个结点
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

	//遍历全部
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
		//node结点未被访问过
		if (book[node->ver] == 0)
		{
			path[depth] = node->path;//node的path加入path[]中
			book[node->ver] = 1;//node结点被访问
			dfs(node->ver, depth + 1);//递归
			book[node->ver] = 0;//重置
		}
		node = node->next;//node向后查找是否有未被访问的结点
	}
}