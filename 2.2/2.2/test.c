#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//void print(int(*p)[5], int row, int col)
//{
//	int i, j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	print(arr, 3, 5);
//	//二维数组首元素地址是第一行的地址
//    return 0;
//}


//int main()
//{
//	int data[3][4];
//	int(*pd)[4] = data;
//	int(*p2)[3][4] = &data;
//	return 0;
//}


//函数指针
//指向函数的指针
int ADD(int x, int y)
{
	return x + y;
}
//void test(char x, char* y)
//{
//	;
//}
//int main()
//{
//	int (*pf)(int, int) = &add;//可省略&
//	//函数返回类型 (*函数指针变量名)(函数参数类型) = &函数名
//	void(*pt)(char, char*) = &test;//可省略&
//	printf("%p\n%p\n", add, &add);
//	//两个地址完全一样，没有区别
//	printf("%d\n", (*pf)(2, 3));
//	printf("%d\n", (pf)(2, 3));
//	printf("%d\n", (*********pf)(2, 3));
//	//pf前面的*没有用，0个或者1万个都一样
//	return 0;
//}


//int myStrlen(const char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int(*p)(const char*) = myStrlen;
//	printf("%d\n", p("bit"));
//	printf("%d\n", p("hello"));
//	printf("%d\n", p("world"));
//	return 0;
//}

//函数指针数组 - 存放函数指针的数组
int SUB(int x, int y)
{
	return x - y;
}
//int main()
//{
//	int(*pf1)(int, int) = add;
//	int(*pf2)(int, int) = sub;
//	int(*pfarr1[2])(int, int) = { add, sub };
//	int(*pfarr2[2])(int, int) = { pf1, pf2 };
//	return 0;
//}
int MUL(int x, int y)
{
	return x * y;
}
int DIV(int x, int y)
{
	return x / y;
}
int main()
{
	int x, y, input, ret;
	int(*pfArr[])(int, int) = { 0, ADD,SUB, MUL, DIV };
	do
	{
		printf("0.退出\n1.加\n2.减\n3.乘\n4.除\n");
		scanf("%d", &input);
		if (0 == input)
		{
			printf("输入错误\n");
		}
		else if (input >= 1 && input <= 4)
		{
			printf("请输入两个数");
			scanf("%d%d", &x, &y);
			printf("%d\n", (pfArr[input](x, y)));
		}
		else
		{
			printf("重新输入\n");
		}
	} while (input);
}

