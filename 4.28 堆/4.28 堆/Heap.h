#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//大堆，找前x个大的
typedef int data;

typedef struct Heap
{
	data* a;
	int size;//当前堆中数据个数
	int capacity;//最大容量
}HP;

void AdjustUp(int* a, int child);

void AdjustDown(int* a, int n, int parent);

void Swap(int* a, int* b);

void HeapInit(HP* php, data* a, int n);

void HeapDestroy(HP* php);

void HeapPush(HP* php, data x);

//删除堆顶数据（最大的或最小的）
void HeapPop(HP* php);

//得到堆顶数据
data HeapTop(HP* php);

int HeapSize(HP* php);

bool HeapEmpty(HP* php);

void HeapPrint(HP* php);