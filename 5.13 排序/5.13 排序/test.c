#include "sort.h"

int main()
{
	int a[] = { 5, 4, 3, 5, 2, 1, 5, 9, 8, 1, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	//HeapSort(a, n);
	//BubbleSort(a, n);
	//QuickSort(a, 0, n - 1);
	//QuickSortNonR(a, 0, n - 1);
	//MergeSort(a, n);
	MergeSortNonR(a, n);
	PrintArray(a, n);
	return 0;
}