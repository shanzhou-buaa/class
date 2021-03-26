#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int i = 1, j = 0;
//	int sum = 0, n;
//	while (scanf("%d", &n) != EOF)
//	{
//		sum = 0;
//		i = 1;
//		j = 0;
//		while (i + j <= n)
//		{
//			if (i > j)
//			{
//				j++;
//				sum++;
//			}
//			else
//				i++;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

typedef struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
}line;
int main()
{
	int n;
	line arr[1000];
	int i = 0, j = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
		arr[i].len = 1;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j || arr[j].len == 0)
				continue;
			if (arr[i].x1 == arr[j].x2 && arr[i].y1 == arr[j].y2)
			{
				arr[i].len += arr[j].len;
				arr[j].len = 0;
				arr[i].x1 = arr[j].x1;
				arr[i].y1 = arr[j].y1;
				i--;
				break;
			}
		}
	}
	int max = 0;
	for (i = 1; i <= n; i++)
	{
		if (arr[i].len > max)
		{
			max = arr[i].len;
			j = i;
		}
	}
	printf("%d %d %d", arr[j].len, arr[j].x1, arr[j].y1);
	return 0;
}

