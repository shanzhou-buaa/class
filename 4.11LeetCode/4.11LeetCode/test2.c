#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//把K放到数组里
	int k[5] = { 0 };
	int n = 0;
	while (K)
	{
		k[n] = K % 10;
		K /= 10;
		n++;
	}
	//多余的位用-1取代
	int i = n;
	for (; i < 5; i++)
		k[i] = -1;

	int sz = (ASize > 5) ? ASize : 5;//结果的位数
	int* ret = (int*)malloc(sizeof(int)* (sz + 1));
	int next = 0;//进位
	for (i = 0; i < sz; i++)
	{
		if (k[i] != -1 && i < 5)
			ret[i] = A[i] + k[i] + next;
		else
			ret[i] = A[i] + next;

		if (ret[i] > 10)
		{
			ret[i] -= 10;
			next = 1;
		}
		else
			next = 0;
	}
	if (next == 1)
	{
		sz++;
		ret[sz - 1] = 1;
	}

	*returnSize = sz;
	return ret;
}

int main()
{
	return 0;
}