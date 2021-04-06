//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//void PrintNum(char* num)
//{
//	int flag = 0, i = 0;
//	int len = strlen(num);
//	for (i = 0; i < len; i++)
//	{
//		if (num[i] != '0')
//			flag = 1;
//		if (flag)
//			printf("%c", num[i]);
//	}
//	printf("\n");
//}
//
//int Increment(char* num)
//{
//	int flag = 0;
//	int len = strlen(num);
//	num[len - 1]++;
//	int i = len - 1;
//	while (i >= 0)
//	{
//		if (i == 0)
//			flag = 1;
//		if (num[i] <= '9')
//			break;
//		if (num[i] > '9')
//		{
//			num[i] = '0';
//			num[--i]++;
//		}
//	}
//	return flag;
//}
//
//void Print1ToMaxOfNDigits(int n)
//{
//	if (n <= 0)
//		return;
//	char* num = (char*)malloc(n + 1);
//	memset(num, '0', n);
//	num[n] = '\0';
//	while (!Increment(num))
//	{
//		PrintNum(num);
//	}
//
//	free(num);
//	num = NULL;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	Print1ToMaxOfNDigits(n);
//	return 0;
//}