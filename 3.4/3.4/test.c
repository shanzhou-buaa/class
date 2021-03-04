#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//int main()
//{
//	char s[1000];
//	gets(s);
//	int i = 0, k = 0;
//	int len = strlen(s);
//	for (i = 0; i < len; i++)
//	{
//		if (s[i] == '-')
//		{
//			if ((islower(s[i - 1]) && islower(s[i + 1]))
//				|| (isupper(s[i - 1]) && isupper(s[i + 1]))
//				|| (isdigit(s[i - 1]) && isdigit(s[i + 1])))
//			{
//				for (k = s[i - 1] + 1; k < s[i + 1]; k++)
//					printf("%c", k);
//			}
//		}
//		else
//			printf("%c", s[i]);
//	}
//	return 0;
//}

//void reverse(char s[])
//{
//	int temp, i, j;
//	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
//	{
//		temp = s[i];
//		s[i] = s[j];
//		s[j] = temp;
//	}
//}
//
//int main()
//{
//	char s[] = "abcdef";
//	reverse(s);
//	int i;
//	for (i = 0; i < strlen(s); i++)
//		printf("%c", s[i]);
//	return 0;
//}

//void inverp(char* a)
//{
//	if (*a == '\0')
//		return;
//	inverp(a + 1);
//	printf("%c", *a);
//}
//
//int main()
//{
//	char s[] = "hello!";
//	inverp(s);
//	return 0;
//}

//f(4)=2+4f(3)
//f3=2+3f(2)
//f2=2+2f(1)
//f1=1
//0 1 1 2 3 5 8

//int main()
//{
//	char a[] = "abcdef";
//	char b[] = "ABC";
//	strcpy(a, b);
//	printf("%c", a[1]);
//	return 0;
//}

//int main()
//{
//	/*char c[] = "\t\v\\\0will\n";
//	char* p = "\t\v\\\0will\n";
//
//	printf("%d\n", strlen(c));
//	printf("%s", p);*/
//	char* p = "\v\0";
//	printf("%s\n", p);
//	return 0;
//}

//int main()
//{
//	char a[5] = { "ABCDE" };
//	char b[] = "China";
//	//a = b;
//	char* s;
//	s = "ABCDE";
//	printf("%s", s);
//}

//int try(int n)
//{
//	if (n > 0)
//		return (n * try(n - 2));
//	else
//		return 1;
//}
//int main()
//{
//	printf("%d\n", try(5));
//	return 0;
//}