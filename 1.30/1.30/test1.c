#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//int minDifference(int* a, int aLen) {
//	long long int min = 2147483647 * 2, x;
//	int i = 0, j = 0;
//	for (i = 0; i < aLen; i++)
//	{
//		for (j = i + 1; j < aLen; j++)
//		{
//			x = abs(a[i] - a[j]);
//			if (x < min)
//			{
//				min = x;
//			}
//		}
//	}
//	return min;
//}
//int main()
//{
//	int a[] = { 2147483647, 1, -2147483648 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	printf("%d\n", minDifference(a, sz));
//    return 0;
//}


//int findNumber(int a, int b) {
//	int i = 0;
//	if (a == 1)
//	{
//		return b * 2;
//	}
//	if (b == 1)
//	{
//		return a + 1;
//	}
//	if (b > a)
//	{
//		return b;
//	}
//	for (i = a + 1; i <= a * b; i++)
//	{
//		if (i % b == 0)
//		{
//			return i;
//		}
//	}
//	return 500000000;
//}
//int main()
//{
//	int a, b;
//	while (scanf("%d%d", &a, &b) != EOF)
//	{
//		printf("%d\n", findNumber(a, b));
//	}
//	return 0;
//}


//桶排序
//如把若干个0~100的数从大到小排序打印
//int main()
//{
//	int a[105] = { 0 };
//	int i, j, t;
//	/*for (i = 0; i <= 100; i++)
//	{
//		a[i] = 0;
//	}*/
//	while (scanf("%d", &t) != EOF)
//	{
//		a[t]++;
//	}
//	for (i = 100; i >= 0; i--)
//	{
//		for (j = a[i]; j > 0; j--)		
//		{
//			printf("%d ", i);
//		}
//	}
//}

//对0~1000的若干个数字从小到大排序
//int main()
//{
//	int a[1005] = { 0 };
//	int i, j, t;
//	/*for (i = 0; i <= 1000; i++)
//	{
//		a[i] = 0;
//	}*/
//	while (scanf("%d", &t) != EOF)
//	{
//		a[t]++;
//	}
//	for (i = 0; i <= 1000; i++)
//	{
//		for (j = a[i]; j > 0; j--)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}