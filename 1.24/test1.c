#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#define ROW 3
//#define COL 3
////三子棋
////   |   |
////---|---|---
////   |   |
////---|---|---
////   |   |
//void printBoard(int row, int col)
//{
//	int i, j;
//	for (i = 0; i < 2 * row - 1; i++)
//	{
//		if (i % 2 == 0)
//		{
//			for (j = 1; j <= 4 * row - 1; j++)
//			{
//				if (j % 4 == 0)
//					printf("|");
//				else
//					printf("-");
//			}
//		}
//		else
//		{
//			for (j = 1; j <= 4 * row - 1; j++)
//			{
//				if (j % 4 == 0)
//					printf("|");
//				else
//					printf(" ");
//			}
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	printBoard(ROW, COL);
//	printf("请输入下棋的坐标（x,y）\n");
//	printf("1 <= x <= %d, 1 <= y <= %d\n", ROW, COL);
//	while (1)
//	{
//		int x, y;
//		scanf("%d%d", &x, &y);
//	}
//	return 0;
//}
//二维数组初始化不能省去列
//数组初始化只能省略第一个【】内的值
//int main()
//{
//	int arr[3][4] = { 0 };
//	int i, j;
//	int* p = arr;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%p\n", &arr[i][j]);
//		}
//	}
//	printf("\n\n");
//	for (i = 0; i < 12; i++)
//	{
//		printf("%x\n", p + i); 
//	}
//	for (i = 0; i < 12; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//    return 0;
//}

//void BubbleSort(int arr[], int sz)
//{
//	int i, j, flag, temp;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			flag = 1;
//			if (arr[j] > arr[j + 1]);
//			{
//				temp = arr[j];
//				arr[j] = arr[j+ 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//			if (flag)
//				break;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int i;
//	BubbleSort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}