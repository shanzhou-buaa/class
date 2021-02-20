#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void _swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		int i;
		for (i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		_swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		_swap(&a[maxi], &a[end]);
		printf("[%d %d]", begin, end);
		Print(a, n);
		begin++;
		end--;
	}
}


void testSelectSort()
{
	int a[] = { 1, 1100, 2, 3, 5, 4, 6, 8, 8, 97, 7 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	Print(a, n);
}


//最坏是O(N*N)的排序
//插入排序	O(N)
//直接选择	O(N*N)
//冒泡		O(N)
//			最好



//向下调整算法的条件：左右子树都是小堆/大堆
void AdjustDown(int* a, int n, int root)//调成大堆
//n数组大小
//从root结点(下标)开始把下面调成大堆
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (a[child + 1] > a[child] && (child + 1 < n))
			child++;
		if (a[child] > a[parent])
		{
			_swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}


//排升序，建大堆
void HeapSort(int* a, int n)
{
	int i;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i);
	int end = n - 1;
	while (end > 0)
	{
		_swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}


void testHeapSort()
{
	int a[] = { 100, 2, 3, 4, 588, 956, 123, 45, 2,500,323232 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	Print(a, n);
}

void BubbleSort(int* a, int n)
{
	int i, j;
	int flag = 1;
	for (i = 0; i < n - 1; i++)
	{
		flag = 1;
		for (j = i; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				_swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}


void testBubbleSort()
{
	int a[] = { 100, 2, 3, 4, 588, 956, 123, 45, 2, 500, 323232 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	Print(a, n);
}

//快排在有序的情况下会很慢
//退化成O(N*N)的排序
//用三数取中法选key来优化

int GetMid(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])//end > mid > begin
			return mid;
		else//a[end] <= a[mid]
		{
			if (a[begin] > a[end])//mid > begin >end
				return begin;
			else//mid >= end >= begin
				return end;
		}
	}
	else//a[begin] >= a[mid] 
	{
		if (a[mid] > a[end])//begin > mid > end
			return mid;
		else//begin >= mid   end >= mid
		{
			if (begin > end)//begin > end > mid
				return end;
			else//end >= begin >= mid
				return begin;
		}
	}
}

//单次快排
//1.左右指针法
int PartSort1(int* a, int begin, int end)
{
	int key = a[begin];
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		_swap(&a[begin], &a[end]);
	}
	_swap(&a[begin], &a[keyi]);
	//返回相遇的位置
	return begin;
}


//2.挖坑法
int PartSort2(int* a, int begin, int end)
{
	int pos = end;
	int key = a[pos];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pos] = a[begin];//把值放到坑里
		pos = begin;//更新坑
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pos] = a[end];//把值放到坑里
		pos = end;//更新坑
	}
	//此时begin和end相等
	a[begin] = key;
	return begin;
}


//3.前后指针法
//建议选右边做key
int PartSort3(int* a, int begin, int end)
{
	int mid = GetMid(a, begin, end);//优化  
	_swap(&a[mid], &a[end]);//优化
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur < end)
	{
		if (a[cur] < key && ++prev != cur)
		{
			_swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	prev++;
	_swap(&a[prev], &a[end]);
	return prev;
}


void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	//int pos = PartSort1(a, begin, end);
	//int pos = PartSort2(a, begin, end);
	int pos = PartSort3(a, begin, end);
	QuickSort(a, begin, pos - 1);
	QuickSort(a, pos + 1, end);
}
 

void testQuickSort()
{
	int a[] = { 7,5,3,2,4,6,10,9,2,8,100, 560, 299 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, n - 1);
	Print(a, n);
}

//归并有O(N)的空间复杂度
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) >> 1;

	//把两段区间弄成有序的
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);


	//归并两段有序区间
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= mid && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
		{
			tmp[i] = a[begin2];
			begin2++;
		}
		else
		{
			tmp[i] = a[begin1];
			begin1++;
		}
		i++;
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	//将归并到tmp的数据拷贝回原数组
	memcpy(a + begin, tmp + begin, sizeof(int)* (end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}


void TestMergeSort()
{
	int a[] = { 1, 5, 3, 5, 50, 6, 889, 6, 99, 30, 50 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);
	Print(a, n);
}


void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* num = (int*)malloc(range* sizeof(int));
	/*for (i = 0; i < range; i++)
		num[i] = 0;*/
	memset(num, 0, sizeof(int)*range);

	for (i = 0; i < n; i++)
		num[a[i] - min]++;
	for (i = 0; i < range; i++)
	{
		while (num[i]--)
			a[j++] = i + min;
	}
}


void TestCountSort()
{
	int a[] = { 3, 3, 2, 5, 3, 9, 9, 6, 1, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	Print(a, n);
}

