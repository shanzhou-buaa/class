#include "sort.h"

int main()
{
	int a[] = { 5, 4, 3, 5, 2, 1, 5, 9, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	//HeapSort(a, n);
	//BubbleSort(a, n);
	QuickSort(a, 0, n - 1);
	PrintArray(a, n);
	return 0;
}