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
//	//n = 13
//	//00000000 00000000 00000000 00001101
//	printf("奇数位：");
//	for (i = 0; i < 32; i+=2)
//	{
//		x = (n >> i) & 1;
//		printf("%d ", x);
//	}
//	printf("\n");
//	printf("偶数位：");
//	for (i = 1; i < 32; i += 2)
//	{
//		x = (n >> i) & 1;
//		printf("%d ", x);
//	}
//	printf("\n");
//    return 0;
//}


//char* solve(char* str)
//{
//	int len = 0;
//	char* p = str;
//	char* left = str;
//	while (*str != '\0')
//	{
//		len++;
//		str++;
//	}
//	char* right = left + len - 1;
//	while (left <= right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//	return p;
//}
//int main()
//{
//	char arr[] = "abcd";
//	solve(arr);
//	printf("%s", arr);
//	return 0;
//}


//int solve(int* a, int aLen) {
//	int i = 0;
//	int max = 0;
//	int p = 0;
//	for (i = 1; i < aLen - 1; i++)
//	{
//		if (a[i] > a[i - 1] && a[i] > a[i + 1])
//		{
//			p = i;
//		}
//	}
//	return p;
//}
//int main()
//{
//	int a[7] = { 2, 4, 1, 2, 7, 8, 4 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int x = solve(a, sz);
//	printf("%d\n", x);
//	return 0;
//}


//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//}


//void reverse(char* p, int len)
//{
//	char* left = p;
//	char* right = left + len - 1;
//	while (left <= right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char str[200];
//	gets(str);
//	int len = strlen(str);
//	reverse(str, len);
//	puts(str);
//	return 0;
//}


//int main()
//{
//	int n, a;
//	scanf("%d%d", &n, &a);
//	int i = 0, sum = 0, temp = 0;
//	for (i = 0; i < n; i++)
//	{
//		temp = temp * 10 + a;
//		sum += temp;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//int main()
//{
//	int cnt = 0, i = 0, sum = 0, x = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		int temp = i;
//		sum = 0;
//		cnt = 1;
//		while (temp / 10)
//		{
//			cnt++;
//			temp /= 10;
//		}
//		temp = i;
//		while (temp)
//		{
//			x = temp % 10;
//			sum += pow(x, cnt);
//			temp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//1 ~ 13, 13 ~ 1
//int main()
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 7; i++)
//	{
//		for (j = 1; j <= 14 - 2 * i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	for (i = 1; i <= 6; i++)
//	{
//		for (j = 1; j <= 2 * i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 13 - 2 * i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int sum = 0;
//	scanf("%d", &n);
//	sum = n / 1;
//	int cnt = sum;
//	while (sum > 1)
//	{
//		cnt += sum / 2;
//		sum = sum / 2 + sum % 2;
//	}
//	printf("%d\n", cnt);
//	return 0;
//}

 
//int main()
//{
//	int a = 0x11223344;
//	char* p= &a;
//	*p = 0;
//	printf("%d\n", a);
//	return 0;
//}


//int main()
//{
//	int arr[5] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;//循环结束后p指向arr数组的最后一个元素
//	}
//	p = arr;//重置
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d\n", *p++);
//	}
//	return 0;
//}

//1.递归
//int my_strlen(char* p)
//{
//	if (*p)
//		return 1 + my_strlen(p + 1);
//	else
//		return 0;
//}

//2.计数器
//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p)
//	{
//		count++;
//		p++;
//	}
//	return count;
//}

//3.指针-指针
//int my_strlen(char* p)
//{
//	char* start = p;
//	while (*p)
//	{
//		p++;
//	}
//	return p - start;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//}


int main()
{
	int a = 10;
	int* p = &a;
	int** pp = &p;
	printf("&a = %d\n", &a);
	printf("p = %d\n", p);
	printf("\n");
	printf("&p = %d\n", &p);
	printf("pp = %d\n", pp);
	return 0;
}


//int main()
//{
//	char* arr[3] = { "abc", "def", "ghi" };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	char str1[4] = "abc";
//	char str2[4] = "def";
//	char str3[4];
//	printf("%s\n", str1);
//	printf("%s\n", str2);
//	strcpy(str3, str1);
//	strcpy(str1, str2);
//	strcpy(str2, str3);
//	printf("%s\n", str1);
//	printf("%s\n", str2);
//}