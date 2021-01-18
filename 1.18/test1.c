#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//void get_max(int a, int b, int c)
//{
//	int temp1, temp2, temp3;
//	if (b >= a)
//	{
//		temp1 = a;
//		a = b;
//		b = temp1;
//	}//a一定>b
//	if (c >= a)
//	{
//		temp2 = a;
//		a = c;
//		c = temp2;
//	}//a一定是最大值
//	if (c >= b)
//	{
//		temp3 = b;
//		b = c;
//		c = temp3;
//	}
//	printf("%d %d %d\n", a, b, c);
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	get_max(a, b, c);
//	return 0;
//}


//int main()
//{
//	int i = 3;
//	for (i = 3; i <= 100; i += 3)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//}


//int main()
//{
//	int a, b, temp;
//	scanf("%d%d", &a, &b);
//	if (b > a)
//	{
//		temp = b;
//		b = a;
//		a = temp;
//	}
//	while (b)
//	{
//		temp = a % b;
//		a = b;
//		b = temp;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//int main()
//{
//	int i;
//	for (i = 1000; i <= 2000; i += 4)
//	{
//		if ((((i % 4 == 0) && (i % 100) != 0)) || (i % 400) == 0)
//			printf("%d ", i);
//	}
//	printf("\n");
//	return 0;
//}

//int is_prime(int a)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(a); i++)
//	{
//		if (a % i == 0)
//			return 0;
//	}
//	if (i > sqrt(a))
//		return 1;
//}
//int main()
//{
//	int i;
//	for (i = 100; i <= 200; i++)
//	{
//		if (1 == is_prime(i))
//			printf("%d ", i);
//	}
//	printf("\n");
//	return 0;
//}


//int main()
//{
//	int i, count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);//9,19,29,39,49,59,69,79,89,90,91,92,93,94,95,96,97,98,99
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	double sum = 0.0, x = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		x = 1.0 / i;
//		if (i % 2 == 0)
//		{
//			sum -= x;
//		}
//		else
//		{
//			sum += x;
//		}
//	}
//	printf("%f\n", sum);
//	return 0;
//}

//void bubbleSort(int a[], int n)
//{
//	int i, j, hold, flag;
//	for (i = 0; i < n - 1; i++)
//	{
//		flag = 0;
//		for (j = 0; j < n - 1; j++)
//		{
//			if (a[j] > a[j - 1])
//			{
//				hold = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = hold;
//				flag = 1;
//			}
//			if (flag == 0)
//				break;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int a[20] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	bubbleSort(a, 10);
//	printf("%d\n", a[9]);
//	return 0;
//}


//int main()
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %-3d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
int main()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(a);
	int left = 0;
	int right = sz - 1;
	int k;
	scanf("%d", &k);
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] > a[k])
		{
			right = mid - 1;
		}
		else if (a[mid] < a[k])
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标是%d\n", k);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}
