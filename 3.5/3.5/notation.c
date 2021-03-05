//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char s[200] = { 0 };
//	gets(s);
//	if (s[1] == '.' && s[0] == '0')
//	{
//		int n1 = 0, i = 2;
//		while (s[i] == '0')
//		{
//			n1++;
//			i++;
//		}
//		n1++;
//		printf("%c", s[i]);
//		int j = i + 1;
//		for (i = j; i < strlen(s); i++)
//		{
//			if (j == i)
//				printf(".");
//			printf("%c", s[i]);
//		}
//		printf("e-%d\n", n1);
//	}
//	else if (s[1] == '.' && s[0] != '0')
//	{
//		int i;
//		for (i = 0; i < strlen(s); i++)
//			printf("%c", s[i]);
//		printf("e0\n");
//	}
//	else
//	{
//		int n3 = 0;
//		int i = 0;
//		while (s[i] != '.')
//		{
//			i++;
//			n3++;
//		}
//		n3--;
//		printf("%c.", s[0]);
//		i = 1;
//		while (i < strlen(s))
//		{
//			if (s[i] != '.')
//				printf("%c", s[i]);
//			i++;
//		}
//		printf("e%d\n", n3);
//	}
//	return 0;
//}