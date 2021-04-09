#define _CRT_SECURE_NO_WARNINGS 1

int missingNumber(int* nums, int numsSize)
{
	// int *p = (int*)malloc(sizeof(int) * (numsSize + 1));
	// int i = 0;
	// for(i = 0; i <= numsSize; i++)
	//     p[i] = 1;
	// for(i = 0; i < numsSize; i++)
	//     p[nums[i]] = 0;
	// for(i = 0; i <= numsSize; i++)
	// {
	//     if(p[i] == 1)
	//         break;
	// }
	// return i;
	int sum = 0, i = 0;
	for (i = 0; i <= numsSize; i++)
		sum ^= i;//sum += i;
	for (i = 0; i < numsSize; i++)
		sum ^= nums[i];//sum -= nums[i];
	return sum;
}