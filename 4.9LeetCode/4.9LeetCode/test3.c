#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val)
{
	int prev = 0;
	int behind = 0;
	int sz = numsSize;
	for (prev = 0; prev < numsSize; prev++)
	{
		if (nums[prev] != val)
		{
			nums[behind] = nums[prev];
			behind++;
		}
		else
			sz--;
	}
	return sz;
}


int main()
{
	int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int size = sizeof(nums) / sizeof(nums[0]);
	size = removeElement(nums, size, 2);
	int i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", nums[i]);
	return 0;
}