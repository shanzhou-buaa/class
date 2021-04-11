#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//��K�ŵ�������
	int k[5] = { 0 };
	int n = 0;
	while (K)
	{
		k[n] = K % 10;
		K /= 10;
		n++;
	}
	//�����λ��-1ȡ��
	int i = n;
	for (; i < 5; i++)
		k[i] = -1;

	int sz = (ASize > 5) ? ASize : 5;//�����λ��
	int* ret = (int*)malloc(sizeof(int)* (sz + 1));
	int next = 0;//��λ
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