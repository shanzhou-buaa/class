#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Memory
{
	int begin;
	int end;
}Memory;

int comp(const void* a, const void* b)
{
	Memory* pa = (Memory*)a;
	Memory* pb = (Memory*)b;

	return pa->begin - pb->begin;
}

int main()
{
	Memory mem[105];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &mem[i].begin, &mem[i].end);

	qsort(mem, n, sizeof(mem[0]), comp);

	for (i = 1; i < n; i++)
	{
		if (mem[i].begin == mem[i - 1].end + 1)
		{
			mem[i - 1].end = mem[i].end;
			mem[i].begin = mem[i - 1].begin;
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		if (mem[i].begin != mem[i + 1].begin)
			printf("%d %d\n", mem[i].begin, mem[i].end);
	}
	printf("%d %d\n", mem[i].begin, mem[i].end);
	return 0;
}