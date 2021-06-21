#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void QuickSort(int a[], int left, int right);
int _QuickSort(int a[], int left, int right);
int BinarySearch(int a[], int left, int right, int key);

int main()
{
	int a[] = { 4, 2, 1, 7, 6, 5, 3, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, n - 1);
	int pos = BinarySearch(a, 0, n - 1, 5);
	if (pos != -1)
		printf("%d\n", pos);
	else
		printf("’“≤ªµΩ\n");
	return 0;
}

int _QuickSort(int a[], int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
			right--;
		while (left < right && a[left] <= a[key])
			left++;

		int temp = a[left];
		a[left] = a[right];
		a[right] = temp;
	}
	int temp = a[left];
	a[left] = a[key];
	a[key] = temp;

	return left;
}

void QuickSort(int a[], int left, int right)
{
	if (left >= right)
		return;

	int mid = _QuickSort(a, left, right);

	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}

int BinarySearch(int a[], int left, int right, int key)
{
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (a[mid] < key)
			left = mid + 1;
		else if (a[mid] > key)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}