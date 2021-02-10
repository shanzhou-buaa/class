#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int removeDuplicates(int* nums, int numsSize)
{
	int src = 0, dest = 0;
	while (src < numsSize - 1)
	{
		nums[dest] = nums[src];
		dest++;
		src++;
		if (nums[src] == nums[src + 1])
		{
			src++;
		}
		else
		{
			nums[dest] = nums[src + 1];
			dest++;
			src++;
		}
	}
	return dest;
}
//int main()
//{
//	int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	int len = removeDuplicates(nums, 10);
//	for (int i = 0; i < len; i++) 
//	{
//		printf("%d ", nums[i]);
//	}
//
//    return 0;
//}