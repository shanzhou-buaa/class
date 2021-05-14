#include "sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void AjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		AjustDown(a, n, i);

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AjustDown(a, end, 0);
		end--;
	}
}

//冒泡排序，插入排序
//接近有序，插入排序好
void BubbleSort(int* a, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 1;//flag是1说明本次冒泡没发生交换
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	int num1 = a[left];
	int num2 = a[mid];
	int num3 = a[right];

	if (num1 > num2)
	{
		if (num2 > num3)//num1 > num2 > num3
			return num3;
		else//num2 <= num3 && num2 < num1
		{
			if (num1 > num3)//num1 > num3 > num2
				return num3;
			else//num3 > num1 > num2
				return num1;
		}
	}
	else//num1 <= num2
	{
		if (num1 > num3)//num2 > num1 > num3
			return num1;
		else//num2 > num1 && num3 > num1
		{
			if (num2 > num3)
				return num3;
			else
				return num2;
		}
	}
}

//左右哨兵法
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key_i = left;
	while (left < right)
	{
		//right找小
		while (left < right && a[right] >= a[key_i])
			right--;

		//left找大
		while (left < right && a[left] <= a[key_i])
			left++;

		Swap(&a[left], &a[right]);
	}

	//left == right
	int meet_i = left;
	Swap(&a[key_i], &a[meet_i]);

	return meet_i;
}

//挖坑
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	//cur和prev开始一前一后
	int cur = left + 1, prev = left;
	int keyi = left;

	while (cur <= right && prev < right)
	{
		//cur找比keyi小的位置
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		
		cur++;
	}
	Swap(&a[keyi], &a[prev]);

	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int mid = PartSort3(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}

void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}