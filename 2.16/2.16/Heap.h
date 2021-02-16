#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



typedef int HDT;
//HeapDataType
typedef struct Heap
{
	HDT* a;
	size_t size;
	size_t capacity;
}Heap;
//一个结点下标为i
//这个结点的左孩子下标为2*i+1
//这个结点的右孩子下标为2*i+2
//这个结点的父结点下标为(i-1)/2
//大堆：父结点>=子节点
//小堆：父结点<=子节点

//向下调整算法的条件：左右子树都是小堆/大堆
void AdjustDown(HDT* a, int n, int root)//调成小堆
//n数组大小
//从root结点(下标)开始把下面调成小堆
{
	int p = root;//parent
	int c = 2 * root + 1;//child
	while (c < n)
	{
		if (c + 1 < n && a[c] > a[c + 1])
		//找出小的那个孩子
		{
			c++;
		}
		if (a[p] > a[c])
		//父亲大于孩子，交换
		{
			HDT tmp = a[p];
			a[p] = a[c];
			a[c] = tmp;
			p = c;
			c = 2 * p + 1;
		}
		else
		//父亲<=孩子
		{
			break;
		}
	}
}


void AdjustUp(HDT* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			HDT tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


Heap* HeapCreate(HDT* a, size_t n)
{
	//给结构体开辟空间
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	//给hp的a数组开辟空间
	hp->a = (HDT*)malloc(sizeof(n * sizeof(HDT)));
	//把传进来的数组a的内容拷贝到hp的a里面
	memcpy(hp->a, a, n * sizeof(HDT));
	hp->size = n;
	hp->capacity = n;
	int i = 0;
	//建小堆
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}
	return hp;
}


//要得到最大的x个数应该建小堆
void HeapSort(HDT* a, int n)
{
	int root;
	//建(小)堆
	//从最后一个结点的父结点开始调成小堆
	for (root = (n - 1 - 1) / 2; root >= 0; root--)
	{
		AdjustDown(a, n, root);
	}
	//从大往小排序
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		AdjustDown(a, end, 0);
		end--;
	}
	/*for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n"); */
}


void HeapPrint(Heap* hp)
{
	size_t i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}


void HeapPush(Heap* hp, HDT x)
{
	if (hp->size == hp->capacity)
	{
		size_t newcapacity = 2 * hp->capacity;
		hp->a = (HDT*)realloc(hp->a, newcapacity * sizeof(HDT));
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	//向上调整成堆
	AdjustUp(hp->a, hp->size - 1);
}


void HeapPop(Heap* hp)
{
	HDT tmp = hp->a[0];
	hp->a[0] = hp->a[hp->size - 1];
	hp->a[hp->size - 1] = tmp;
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}


HDT HeapTop(Heap* hp)
{
	return hp->a[0];
}


int HeapEmpty(Heap* hp)
{
	return hp->size == 0 ? 1 : 0;
}