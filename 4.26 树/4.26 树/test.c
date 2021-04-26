#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//向下调整算法
//条件：只能当根节点的左右子树均为小堆时使用(这个条件很重要)
//1.选出左右孩子中小的那一个c
//2.小的这个孩子c和父亲p比
//	a.若c比父亲p小，交换，继续向下调整直到p走到叶结点
//	b.若c比p大，不需要交换，处理完成，整个树已经变成小堆
void AdjustDown_recursive(int* a, int sz, int parent)//递归实现
{
	int child = parent * 2 + 1;//先设左孩子比较小
	if (child >= sz)
		return;
	if (child + 1 < sz && a[child] > a[child + 1])//右孩子小
		child++;

	//小的这个孩子和父亲比
	//孩子小，交换
	if (a[child] < a[parent])
	{
		Swap(&a[child], &a[parent]);
		AdjustDown_recursive(a, sz, child);
	}
	//父亲大，调整结束
	else
		return;
}

void AdjustDown(int* a, int sz, int parent)//循环实现
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		if (child + 1 < sz && a[child] > a[child + 1])//右孩子小
			child++;

		//小的这个孩子和父亲比
		//孩子小，交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//父亲大，调整结束
		else
			break;
	}
}
void Print(int* a, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//int main()
//{
//	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	int sz = sizeof(a) / sizeof(a[0]);
//
//	AdjustDown(a, sz, 0);
//	Print(a, sz);
//
//	return 0;
//}

//建堆时间复杂度O(N)
//排升序，建大堆
//排降序，建小堆
void HeapSort(int* a, int sz)
{
	int i;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, sz, i);
	}

	int end = sz - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

int main()
{
	int a[] = { 15, 18, 28, 34, 65, 9, 49, 25, 37, 27 };
	int sz = sizeof(a) / sizeof(a[0]);
	int i = 0;

	HeapSort(a, sz);
	Print(a, sz);

	return 0;
}