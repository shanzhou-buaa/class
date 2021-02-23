#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//void print(int* a, int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//}
//
//
//void quicksort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int key = a[end];
//	int i = end;
//
//	while (begin < end)
//	{
//		while (begin < end && a[begin] <= key)
//			begin++;
//		while (begin < end && a[end] >= key)
//			end--;
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[begin], &a[i]);
//
//	quicksort(a, 0, begin - 1);
//	quicksort(a, begin + 1, i);
//}
//
//
//int main()
//{
//	int a[] = { 99, 56, 56, 23, 21, 2, 0, 1, 4, 5, 6, 7, 9, 6 };
//	int n = sizeof(a) / sizeof(a[0]);
//	quicksort(a, 0, n - 1);
//	print(a, n);
//	return 0;
//}