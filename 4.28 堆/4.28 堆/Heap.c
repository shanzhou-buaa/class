#include "Heap.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustUp(int* a, int child)
{
	if (child <= 0)
		return;

	int parent = (child - 1) / 2;
	if (parent >= 0 && a[parent] < a[child])
	{
		Swap(&a[parent], &a[child]);
		child = parent;
		AdjustUp(a, child);
	}
	else
		return;
}

//建大堆
void AdjustDown(data* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;

		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapInit(HP* php, data* a, int n)
{
	assert(php);

	php->a = (data*)malloc(sizeof(data)*n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	php->size = n;
	php->capacity = n;

	memcpy(php->a, a, sizeof(data)*n);

	int i = 0;
	for (i = (php->size - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(php->a, php->size, i);

}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HeapPush(HP* php, data x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		data* tmp = (data*)realloc(php->a, php->capacity * 2 * sizeof(data));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;

	//向上调整变成堆
	AdjustUp(php->a, php->size - 1);
}

//删除堆顶数据（最大的或最小的）
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

//得到堆顶数据
data HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return (php->size == 0);
}

void HeapPrint(HP* php)
{
	int i = 0;
	for (i = 0; i < php->size; i++)
		printf("%d ", php->a[i]);
	printf("\n\n");

	i = 0;
	int levelSize = 1, j = 0;
	while (levelSize < php->size)
	{
		for (j = 0; j < levelSize && i < php->size; j++)
			printf("%d ", php->a[i++]);
		levelSize *= 2;
		printf("\n");
	}
	printf("\n");
}