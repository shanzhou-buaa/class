#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

//一个数组中只有两个数字出现一次，其余所有数字都出现了 两次
//找到这两个数字

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 1, 5, 3, 4, 6 };
	int i = 0, n = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < sz; i++)
		n ^= a[i];
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
	for (i = 0; i < sz; i++)
	{
		if (((a[i] >> pos) & 1) == 1)
			n1 ^= a[i];
		else
			n2 ^= a[i];
	}
	printf("%d %d\n", n1, n2);
	return 0;
}