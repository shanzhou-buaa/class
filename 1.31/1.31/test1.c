#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//int main()
//{
//	int i = 0, n, x;
//	scanf("%d", &n);
//	printf("奇数位：");
//	for (i = 30; i >= 0; i-=2)
//	{
//		x = (n >> i) & 1;
//		printf("%d ", x);
//	}
//	printf("\n");
//	printf("偶数位：");
//	for (i = 31; i > 0; i-=2)
//	{
//		x = (n >> i) & 1;
//		printf("%d ", x);
//	}
//	printf("\n");
//    return 0;
//}


//void my_up_qsort(int a[], int left, int right)
//{
//	if (left > right)
//	{
//		return;
//	}
//	int i = left, j = right, temp;
//	int std = a[left];
//	while (i != j)
//	{
//		while (a[j] >= std&&i < j)
//		{
//			j--;
//		}
//		while (a[i] <= std&&i < j)
//		{
//			i++;
//		}
//		if (i < j)
//		{
//			temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//		}
//	}
//	a[left] = a[i];
//	a[i] = std;
//	my_up_qsort(a, i + 1, right);
//	my_up_qsort(a, left, i - 1);
//}
//int main()
//{
//	int a[] = { 1, 2, 5, 3, 6, 4, 7, 0, 8, 9 };
//	int left = 0, i = 0;
//	int sz = sizeof(a) / sizeof(a[0]);
//	int right = sz - 1;
//	my_up_qsort(a, left, right);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}


//int main()
//{
//	int a[] = { 100, 5, 6, 99, 99, 65, 200, 1, 0, 500, 230 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int i, j, max, maxnum, temp;
//	for (i = sz - 1; i > 0; i--)
//	{
//		max = INT_MIN;
//		for (j = 0; j <= i; j++)
//		{
//			if (a[j] > max)
//			{
//				maxnum = j;
//				max = a[j];
//			}
//		}
//		temp = a[i];
//		a[i] = a[maxnum];
//		a[maxnum] = temp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


//int binary_search(int a[], int start, int end, int value)//数组升序
//{
//	int cur = start + (end - start) / 2;
//	if (start == end && a[cur] != value)
//		return -1;
//	if (a[cur] > value)
//		binary_search(a, start, cur - 1, value);
//	else if (a[cur] < value)
//		binary_search(a, cur + 1, end, value);
//	else
//		return cur;
//}
//int main()
//{
//	int a[] = { 10, 25, 34, 41, 56, 67, 70, 88, 95, 103 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int ret = binary_search(a, 0, sz - 1, 41);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	int m;
//	double x;
//	char format[32];
//	scanf("%lf%d", &x, &m);
//	sprintf(format, "%%.%df\n", m);
//	printf(format, sin(x));
//}


//int cal(char* s)
//{
//	int i, n, sign;
//	for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
//	{
//		;
//	}
//	for (i = 1; s[i] != '\0'; i++)
//	{
//		sign = 1;
//		if (s[i] == '+' || s[i] == '-')
//		{
//			sign = ((s[i] == '+') ? 1 : -1);
//			i++;
//		}
//	}
//}
//int main()
//{
//	char s[100] = { 0 };
//	scanf("%s", s);
//	printf("%d\n", cal(s));
//	return 0;
//}

//int check()
//{
//	int a = 1;
//	//char* p = (char*)&a;
//	//return *p;
//	return *(char*)&a;
//}
//int main()
//{
//	int x = check();
//	printf("%d\n", x);
//	return 0;
//}


//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a = %d\nb = %d\nc =%d\n", a, b, c);
//	return 0;
//}

//int main()
//{
//	int i, j;
//	int a[20][20] = { 0 };
//	a[0][0] = 1;
//	a[1][0] = 1;
//	a[1][1] = 1;
//	for (i = 2; i < 20; i++)
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	printf("1\n");
//	printf("1 1\n");
//	for (i = 2; i < 20; i++)
//	{
//		printf("1 ");
//		for (j = 1; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//			printf("%d ", a[i][j]);
//		}
//		printf("1\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	int murder[5] = { 0 };
//	int i;
//	for (i = 1; i <= 4; i++)
//	{
//		murder[i] = 1;//是凶手
//		if ((murder[1] != 1) + 
//			(murder[3] == 1) + 
//			(murder[4] == 1) + 
//			(murder[3] != 1) == 3)
//		{
//			break;
//		}
//		murder[i] = 0;
//	}
//	printf("%c\n", 'A' + i - 1);
//	return 0;
//}


