#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//计算空间复杂度不考虑输入的空间
//只考虑算法运行时额外的空间
//如冒泡排序的空间复杂度是O(1)

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		unsigned long long* fiba = (unsigned long long*)malloc((n + 1) * sizeof(unsigned long long));
		fiba[0] = 0;
		fiba[1] = 1;
		int i;
		for (i = 2; i <= n; i++)
			fiba[i] = fiba[i - 1] + fiba[i - 2];
		for (i = 0; i <= n; i++)
			printf("%d\n", fiba[i]);
		i = 5;
		i = 7;
	}
	return 0;
}