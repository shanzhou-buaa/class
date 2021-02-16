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
//һ������±�Ϊi
//������������±�Ϊ2*i+1
//��������Һ����±�Ϊ2*i+2
//������ĸ�����±�Ϊ(i-1)/2
//��ѣ������>=�ӽڵ�
//С�ѣ������<=�ӽڵ�

//���µ����㷨��������������������С��/���
void AdjustDown(HDT* a, int n, int root)//����С��
//n�����С
//��root���(�±�)��ʼ���������С��
{
	int p = root;//parent
	int c = 2 * root + 1;//child
	while (c < n)
	{
		if (c + 1 < n && a[c] > a[c + 1])
		//�ҳ�С���Ǹ�����
		{
			c++;
		}
		if (a[p] > a[c])
		//���״��ں��ӣ�����
		{
			HDT tmp = a[p];
			a[p] = a[c];
			a[c] = tmp;
			p = c;
			c = 2 * p + 1;
		}
		else
		//����<=����
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
	//���ṹ�忪�ٿռ�
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	//��hp��a���鿪�ٿռ�
	hp->a = (HDT*)malloc(sizeof(n * sizeof(HDT)));
	//�Ѵ�����������a�����ݿ�����hp��a����
	memcpy(hp->a, a, n * sizeof(HDT));
	hp->size = n;
	hp->capacity = n;
	int i = 0;
	//��С��
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}
	return hp;
}


//Ҫ�õ�����x����Ӧ�ý�С��
void HeapSort(HDT* a, int n)
{
	int root;
	//��(С)��
	//�����һ�����ĸ���㿪ʼ����С��
	for (root = (n - 1 - 1) / 2; root >= 0; root--)
	{
		AdjustDown(a, n, root);
	}
	//�Ӵ���С����
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
	//���ϵ����ɶ�
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