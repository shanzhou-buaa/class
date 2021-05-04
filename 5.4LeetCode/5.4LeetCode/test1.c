#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int size = nums1Size + nums2Size;
	int* arr = (int*)malloc(sizeof(int)* size);

	int i1 = 0, i2 = 0, i = 0;
	while (i1 < nums1Size && i2 < nums2Size)
	{
		if (nums1[i1] < nums2[i2])
		{
			arr[i] = nums1[i1];
			i1++;
			i++;
		}
		else
		{
			arr[i] = nums2[i2];
			i2++;
			i++;
		}
	}
	while (i1 < nums1Size)
	{
		arr[i] = nums1[i1];
		i1++;
		i++;
	}
	while (i2 < nums2Size)
	{
		arr[i] = nums2[i2];
		i2++;
		i++;
	}

	if (size % 2 == 1)
	{
		size /= 2;
		return (double)arr[size];
	}
	else
	{
		int size1 = size / 2;
		int size2 = size1 - 1;
		return (arr[size1] + arr[size2]) / 2.0;
	}
}

int main()
{
	int arr1[] = { 0, 1 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = { 0 };
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	
	printf("%lf\n", findMedianSortedArrays(arr1, size1, arr2, size2));
	return 0;
}