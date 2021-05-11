#include "sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//void InsertSort(int* a, int n)
//{
//	int i = 0, j = 0;
//	for (i = 1; i < n; i++)
//	{
//		int temp = a[i];
//		for (j = i; j >= 1; j--)
//		{
//			if (a[j - 1] > a[j])
//				Swap(&a[j - 1], &a[j]);
//			else
//				break;
//		}
//		a[j] = temp;
//	}
//}

void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = temp;
	}
}

//gap越小，大的和小的数可以更快的挪到对应的方向，但越不接近有序
//gap越大，大的和小的数可以更慢的挪到对应的方向，但越接近有序
void ShellSort(int* a, int n)
{
	int i = 0;
	int gap = n;
	while (gap > 1)
	{
		//如果gap < 3，gap最后是0,+1保证最后一次是1
		gap = gap / 3 + 1;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = temp;
		}
	}
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int i = 0;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = right;
		for (i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i] > a[maxIndex])
				maxIndex = i;
		}
		Swap(&a[minIndex], &a[left]);
		//如果left和maxIndex重叠，left被换走，maxIndex的位置就不对了，要修正
		if (left == maxIndex)
			maxIndex = minIndex;
		Swap(&a[maxIndex], &a[right]); 
		
		left++;
		right--;
	}
}

void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}