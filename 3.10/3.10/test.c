#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void print(int a[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	int key = right;
	int begin = left;
	int end = right;
	while (left < right)
	{
		while (a[left] <= a[key] && left < right)
			left++;
		while (a[right] >= a[key] && left < right)
			right--;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	QuickSort(a, begin, left - 1);
	QuickSort(a, right + 1, end);
}

//int main()
//{
//	int a[] = { 1, 5, 3, 68, 9, 8, 7, 4, 56, 56, 5 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	print(a, sz);
//	QuickSort(a, 0, sz - 1);
//	print(a, sz);
//	return 0;
//}


//void Find(int* a, int rows, int cols, int num)
//{
//	if (a == NULL || rows < 0 || cols < 0)
//		printf("error\n");
//	else
//	{
//		int row = 0;
//		int col = cols - 1;
//		while (row < rows && col >= 0)
//		{
//			if (a[row * rows + col] == num)
//			{
//				printf("row:%d col:%d\n", row, col);
//				return;
//			}
//			else if (a[row * rows + col] > num)
//				col--;
//			else
//				row++;
//		}
//	}
//	printf("not found\n");
//	return;
//}
//
//int main()
//{
//	int a[16]= { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
//	Find(a, 4, 4, 15);
//	return 0;
//}

