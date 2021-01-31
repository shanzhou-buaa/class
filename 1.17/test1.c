#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



//switch后面的括号里必须是整型表达式
//case后面必须是整型常量表达式（整型、常量）
//字符型本质是整型，也可以放

 
int main()
{
	int i = 1;
	int sum = 0;
	int mul = 1;
	for (i = 1; i <= 10; i++)
	{
		mul *= i;
		sum += mul;
	}
	printf("%d", sum);
	return 0;
}


//int main()
//{
//	char password[50];
//	printf("输入密码:");
//	scanf("%s", password);
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("请确认(Y/N):");
//	ch = getchar();
//	if ('Y' == ch)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//	return 0;
//}


//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			continue;//跳过本次循环continue后面的代码，直接返回循环入口进行下一次循环入口的判断
//		}
//		printf("%d ", i);//打印1 2 3 4 然后死循环
//		i++;
//	}
//}


//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("工作日\n");
//			break;
//	    case 6:
//	    case 7:
//			printf("休息日\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//	}
//}


//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)//i+=2效率高
//	{
//		if (1 == i % 2)
//		{
//			printf("%d ", i);
//		}
//		if (99 == i)
//		{
//			printf("\n");
//		}
//	}
//    return 0;
//}