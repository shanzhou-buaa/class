//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <ctype.h>
//
////考虑特殊情况
////1.NULL
////2.空字符串
////3.特殊符号 "!@#$%..."
////4."   123" 有前导空格
//enum State
//{
//	VALID,
//	INVALID
//};
//enum State state = INVALID;
//
//int my_atoi(const char* str)
//{
//	if (str == NULL)
//		return 0;
//	if (*str == '\0')
//		return 0;
//	int len = strlen(str);
//	int i = 0, flag = 1;
//	long long int ret = 0, sum = 0;
//	while (isspace(str[i]))//跳过空白字符
//	{
//		i++;
//	}
//
//	int x = 0;
//	for (; i < len; i++)
//	{
//		if (str[i] == '-')
//		{
//			flag = -1;
//			continue;
//		}
//		if (isdigit(str[i]))
//		{
//			int temp = str[i] - '0';
//			sum = sum * 10 + temp;
//
//		}
//		else
//			return 0;
//	}
//	ret = sum * flag;
//	if (ret > INT_MAX || ret < INT_MIN)
//		return 0;
//	state = VALID;
//	return (int)ret;
//}
//
//int main()
//{
//	int ret = my_atoi("-12345");
//	if (state == VALID)
//	{
//		printf("%d\n", ret);
//		printf("yes\n");
//	}
//	else
//		printf("no : 0\n");
//	return 0;
//}