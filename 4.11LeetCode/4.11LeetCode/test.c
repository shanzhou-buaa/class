//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int removeDuplicates1(int nums[], int numsSize)
//{
//	int prev = 0;
//	int behind = 0;
//	int sz = 1;
//	for (; prev < numsSize; prev++)
//	{
//		if (nums[prev] != nums[behind])
//		{
//			behind++;
//			nums[behind] = nums[prev];
//			sz++;
//		}
//	}
//	return sz;
//}
//
//int removeDuplicates2(int* nums, int numsSize){
//	int src1 = 0, src2 = 1;
//	int dst = 0;
//	// 跟上题的思路一致，相同的数只保留一个，依次往前放
//	while (src2 < numsSize)
//	{
//		nums[dst] = nums[src1];
//		++dst;
//		//如果两个指针指向的元素不重复，则指针同时向后移动
//		if (nums[src1] != nums[src2])
//		{
//			++src1;
//			++src2;
//		}
//		else
//		{
//			//如果重复，找到第一个不重复的元素
//			while (src2 < numsSize && nums[src1] == nums[src2])
//			{
//				++src2;
//			}
//			//更新指针
//			src1 = src2;
//			++src2;
//		}
//	}
//
//	if (src1 < numsSize)
//	{
//		nums[dst] = nums[src1];
//		++dst;
//	}
//
//
//	return dst;
//}
//
//int main()
//{
//	int a[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	int size = sizeof(a) / sizeof(a[0]);
//	size = removeDuplicates2(a, size);
//	int i = 0;
//	for (i = 0; i < size; i++)
//		printf("%d ", a[i]);
//	return 0;
//}