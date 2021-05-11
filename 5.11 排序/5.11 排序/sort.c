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

//gapԽС����ĺ�С�������Ը����Ų����Ӧ�ķ��򣬵�Խ���ӽ�����
//gapԽ�󣬴�ĺ�С�������Ը�����Ų����Ӧ�ķ��򣬵�Խ�ӽ�����
void ShellSort(int* a, int n)
{
	int i = 0;
	int gap = n;
	while (gap > 1)
	{
		//���gap < 3��gap�����0,+1��֤���һ����1
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
		//���left��maxIndex�ص���left�����ߣ�maxIndex��λ�þͲ����ˣ�Ҫ����
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