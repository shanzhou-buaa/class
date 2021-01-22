#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "add.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d\n", Add(a, b));
//    return 0;
//}

//void my_print1(int n)
//{
//	if (n > 9)
//	{
//		printf("%d ", n % 10);
//		return my_print(n / 10);
//	}
//	else
//	{
//		printf("%d ", n);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	my_print1(n);//打印下4 3 2 1
//	printf("\n");
//	return 0;
//}

//void my_print2(int n)
//{
//	if (n > 9)
//	{
//		my_print2(n / 10);
//		printf("%d ", n % 10);
//	}
//	else
//	{
//		printf("%d ", n);
//	}
//}
////my_print2(1234)
////my_print2(123) 4
////my_print2(12) 3 4
////my_print2(1) 2 3 4
////1 2 3 4
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	my_print2(n);//打印下1 2 3 4
//	printf("\n");
//	return 0;
//}


//int my_strlen1(char* p)
//{
//	int count = 0;
//	while (*p)
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//int my_strlen2(char* p)
//{
//	if (*p)
//	{
//		return 1 + my_strlen2(p + 1);
//	}
//	else
//		return 0;
//	
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int sum = my_strlen1(arr);
//	printf("%d\n", sum);
//	sum = my_strlen2(arr);
//	printf("%d\n", sum);
//	return 0;
//}


//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", fac(n));
//	return 0;
//}


//求斐波那契数列的第n个数
long long int fib(long long int n)
{
	long long int a = 1, b = 1, c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	long long int n, i;
	scanf("%lld", &n);
	printf("%lld\n", fib(n));
	return 0;
}


//int main()
//{
//	char ch[] = { 'b', 'i', 't' };
//	int sz = sizeof(ch) / sizeof(ch[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c ", ch[i]);
//	}
//	printf("\n");
//	return 0;
//}

//int fac1(int n)
//{
//	int i = 1, sum = 1;
//	if (i == 0)
//	{
//		return 1;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//int fac2(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac2(n - 1);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n%d\n", fac1(n), fac2(n));
//	return 0;
//}


//int my_strlen1(char* p)
//{
//	int count = 0;
//	while (*p)
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//void reverse_string(char* p1)
//{
//	char* p2 = p1 + my_strlen1(p1) - 1;
//	while (p1 <= p2)
//	{
//		char temp = *p2;
//		*p2 = *p1;
//		*p1 = temp;
//		p1++;
//		p2--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", DigitSum(n));
//	return 0;
//}


//int my_pow(int n, int k)
//{
//	if (k > 1)
//	{
//		return n * my_pow(n, k - 1);
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n, k;
//	scanf("%d%d", &n, &k);
//	printf("%d\n", my_pow(n, k));
//	return 0;
//}