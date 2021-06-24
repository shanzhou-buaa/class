#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 50

int book[MAX];
int n;
int num[MAX];

void dfs(int i, int size)
{
	int j;
	num[size] = i;
	book[i] = 1;
	if (size == n)
	{
		for (j = 1; j <= n; j++)
			printf("%d ", num[j]);
		printf("\n");
		return;
	}
	for (j = 1; j <= n; j++)
	{
		if (book[j] == 0)
		{
			dfs(j, size + 1);
			book[j] = 0;
		}
	}
}

int main()
{
	
	while (scanf("%d", &n) != EOF)
	{
		int i;
		for (i = 1; i <= n; i++)
		{
			int size = 1;
			dfs(i, size);
			memset(book, 0, sizeof(int)* MAX);
		}
		
	}
	return 0;
}