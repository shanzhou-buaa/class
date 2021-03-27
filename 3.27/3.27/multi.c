#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num
{
	int data;
	int pow;
}num;

int main()
{
	num n1[100];
	num n2[100];
	num n3[10000];
	memset(n1, 0, sizeof(n1));
	memset(n2, 0, sizeof(n2));
	memset(n3, 0, sizeof(n3));

	int sz1 = 0, sz2 = 0;
	int i = 0, j = 0, k = 0, n = 0;
	while (scanf("%d%d", &n1[sz1].data, &n1[sz1].pow) != EOF && getchar() != '\n')
		sz1++;
	sz1++;
	while (scanf("%d%d", &n2[sz2].data, &n2[sz2].pow) != EOF && getchar() != '\n')
		sz2++;
	sz2++;
	for (i = 0; i < sz1; i++)
	{
		for (j = 0; j < sz2; j++)
		{
			n3[k].data = n1[i].data * n2[j].data;
			n3[k].pow = n1[i].pow + n2[j].pow;
			k++;
		}
	}
	i = 0;
	j = 0;
	n = k;
	int max = 0, pos = 0;
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (n3[j].pow == -1 || n3[i].pow == -1)
				continue;
			if (n3[i].pow == n3[j].pow)
			{
				n3[i].data += n3[j].data;
				n3[j].pow = -1;
				n--;
			}
		}
	}
	//k:n3的数据个数
	//n:有效数据个数
	for (j = 0; j < n; j++)
	{
		max = 0;
		pos = 0;
		for (i = 0; i < k; i++)
		{
			if (n3[i].pow == -1)
				continue;
			if (n3[i].pow >= max)
			{
				max = n3[i].pow;
				pos = i;
			}
		}
		printf("%d %d ", n3[pos].data, n3[pos].pow);
		n3[pos].pow = -1;
	}

	return 0;
}