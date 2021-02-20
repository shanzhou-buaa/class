#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


void Print(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


void InsertSort(int* a, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				a[end] = tmp;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}


void testInsertSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	Print(a, n);
}


void ShellSort(int* a, int n)
{
	//间隔为gap的预排序
	int gap = n;
	int i;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1保证最后一次一定是1
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}


void testShellSort()
{
	int a[] = { 5, 6, 4, 7, 8, 9, 52, 1, 3, 5, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	Print(a, n);
}



void _swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void SelectSort(int* a, int n)
{
	int i, j;
	int min, max;
	int minNum = 0, maxNum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			min = a[i];
			max = a[i];
			if (a[j] < min)
				minNum = j;
			if (a[j] > max)
				maxNum = j;
			_swap(&a[i], &a[minNum]);
			if (i == maxNum)
				maxNum = minNum;
			_swap(&a[n - i - 1], &a[maxNum]);
		}
		printf("%d:", i);
		Print(a, n);
	}
}


void testSelectSort()
{
	int a[] = { 5, 6, 4, 7, 1, 3, 2, 5, 6, 44 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	Print(a, n);
}