#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>


//we are happy.
//int main()
//{
//	char s[100];
//	gets(s);
//	int len = strlen(s);
//	int n = 0, i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (s[i] == ' ')
//			n++;
//	}
//	int len1 = len + n * 2;
//	char* p1 = s + len;
//	char* p2 = s + len1;
//	while (p1 != p2)
//	{
//		if ((*p1) != ' ')
//			*p2 = *p1;
//		else
//		{
//			p2 -= 2;
//			*p2 = '%';
//			*(p2 + 1) = '2';
//			*(p2 + 2) = '0';
//		}
//		p1--;
//		p2--;
//	}
//	printf("%s", s);
//
//	return 0;
//}


//0 1 2 3 4 5 6 7  8
//0 1 1 2 3 5 8 13 21
//fib1 fib2 sum
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			printf("sum : 0\n");
		else if (n == 1)
			printf("sum : 1\n");
		else
		{
			long long fib1 = 0;
			long long fib2 = 1;
			long long sum = 1;
			int i = 0;
			for (i = 2; i <= n; i++)
			{
				sum = fib1 + fib2;
				fib1 = fib2;
				fib2 = sum;
			}
			printf("sum : %lld\n", sum);
		}
	}
	
	return 0;
}
