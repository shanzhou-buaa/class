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
//	// �������˼·һ�£���ͬ����ֻ����һ����������ǰ��
//	while (src2 < numsSize)
//	{
//		nums[dst] = nums[src1];
//		++dst;
//		//�������ָ��ָ���Ԫ�ز��ظ�����ָ��ͬʱ����ƶ�
//		if (nums[src1] != nums[src2])
//		{
//			++src1;
//			++src2;
//		}
//		else
//		{
//			//����ظ����ҵ���һ�����ظ���Ԫ��
//			while (src2 < numsSize && nums[src1] == nums[src2])
//			{
//				++src2;
//			}
//			//����ָ��
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