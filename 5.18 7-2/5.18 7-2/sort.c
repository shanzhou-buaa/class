#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}tn;

void Swap(int* a, int* b);
int SelectSort(int* a, int n, int* times);
int BubbleSort(int* a, int n, int* times);
int AdjustDown(int* a, int n, int parent, int* times);
int HeapSort(int* a, int n, int* times);
void Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp, int* times);
void _MergeSort(int* a, int left, int right, int* tmp, int* times);
void MergeSort(int* a, int n, int* times);
//void QuickSort(int* a, int left, int right, int* times);
void quickSort(int k[], int left, int right, int* times);
void PrintArray(int* a, int n);

int main()
{
	//输入
	int a[105];
	memset(a, 0, sizeof(int)* 105);
	int n, sign, i;
	scanf("%d%d", &n, &sign);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int times = 0;

	if (sign == 1)
		times = SelectSort(a, n, &times);
	else if (sign == 2)
		times = BubbleSort(a, n, &times);
	else if (sign == 3)
		times = HeapSort(a, n, &times);
	else if (sign == 4)
		MergeSort(a, n, &times);
	else if (sign == 5)
		quickSort(a, 0, n - 1, &times);
	PrintArray(a, n);
	printf("%d\n", times);
	return 0;
}

//选择排序，比较次数是指选择未排序部分的最小元素时的比较次数
int SelectSort(int* a, int n, int* times)
{
	int i = 0;
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int minIndex = left;
		for (i = left + 1; i <= right; i++)
		{
			(*times)++;
			if (a[i] < a[minIndex])
				minIndex = i;
		}
		Swap(&a[minIndex], &a[left]);
		left++;
	}
	return (*times);
}

//冒泡排序，比较次数是指相邻元素的比较次数，若某趟排序中没有进行数据交换，就认为排序结束。
int BubbleSort(int* a, int n, int* times)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			(*times)++;
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
	return (*times);
}

//堆排序，比较次数是指根元素调整过程中根元素与子树根结点的比较次数
int AdjustDown(int* a, int n, int parent, int* times)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
			(*times)++;
		}
		else
		{
			(*times)++;
			break;
		}
	}
	return (*times);
}

//升序，建大堆
int HeapSort(int* a, int n, int* times)
{
	int i = 0;
	//建堆
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i, times);
	for (i = n - 1; i >= 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0, times);
	}
	return (*times);
}

void Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp, int* times)
{
	int i = begin1, begin = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		(*times)++;
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	for (i = begin; i <= end2; i++)
		a[i] = tmp[i];

	//return (*times);
}

void _MergeSort(int* a, int left, int right, int* tmp, int* times)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	_MergeSort(a, begin1, end1, tmp, times);
	_MergeSort(a, begin2, end2, tmp, times);

	Merge(a, begin1, end1, begin2, end2, tmp, times);

	//return (*times);
}

void MergeSort(int* a, int n, int* times)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	_MergeSort(a, 0, n - 1, tmp, times);
	free(tmp);
	//return (*times);
}

//int PartSort(int* a, int left, int right, int* times)
//{
//	int key_i = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[key_i])
//			right--;
//		while (left < right && a[left] <= a[key_i])
//			left++;
//
//		Swap(&a[left], &a[right]);
//	}
//	int 
//}
//
//void QuickSort(int* a, int left, int right, int* times)
//{
//	if (left >= right)
//		return;
//
//	int mid = PartSort(a, left, right, times);
//	QuickSort(a, left, mid, times);
//	QuickSort(a, mid + 1, right, times);
//}

void quickSort(int k[], int left, int right, int* times)
{
	int i, last;
	if (left<right){
		last = left;
		for (i = left + 1; i <= right; i++)
		{
			(*times)++;
			if (k[i] < k[left])
			{
				Swap(&k[++last], &k[i]);
			}
		}
		Swap(&k[left], &k[last]);
		quickSort(k, left, last - 1, times);
		quickSort(k, last + 1, right, times);
	}
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}