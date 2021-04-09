#define _CRT_SECURE_NO_WARNINGS 1

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int* p = (int*)malloc(sizeof(int)* 2);
	*returnSize = 2;
	int i = 0, n = 0;
	for (i = 0; i < numsSize; i++)
		n ^= nums[i];
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	int n1 = 0, n2 = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
			n1 ^= nums[i];
		else if (((nums[i] >> pos) & 1) == 0)
			n2 ^= nums[i];
	}
	p[0] = n1;
	p[1] = n2;
	return p;
}