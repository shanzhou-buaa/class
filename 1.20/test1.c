#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>
//int main()
//{
//	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(a);
//	int left = 0;
//	int right = sz - 1;
//	int k;
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//left+right可能溢出，不好
//		//改进:int mid = left + (right - left) / 2;这样不存在溢出
//		//不能写成a/2+b/2，如a=3，b=5  a/2=1，b/2=2 结果不一样
//		if (a[mid] > a[k])
//		{
//			right = mid - 1;
//		}
//		else if (a[mid] < a[k])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d\n", k);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//int main()
//{
//	char arr1[] = "hello world!";
//	char arr2[] = "############";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//void menu()
//{
//	printf("***********************************\n");
//	printf("**********    1、play    **********\n");
//	printf("**********    0、exit    **********\n");
//	printf("***********************************\n");
//	printf("请输入数字以选择\n");
//}
//void game()
//{
//	printf("请输入你猜的数字（1 - 100）\n");
//	int ret = rand() % 100 + 1;//rand生成随机数
//	int count = 0;
//	while (1)
//	{
//		int guess = 0;
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//			count++;
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//			count++;
//		}
//		else
//		{
//			printf("猜对了\n");
//			count++;
//			break;
//		}
//	}
//	printf("一共猜了%d次\n", count);
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//time()函数返回时间戳
//	//srand（）设置rand的起点，括号内需要一个随机值才能让起点一直变化
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1: printf("游戏开始\n"); game(); break;
//			case 0: printf("退出游戏\n"); break;
//			default:printf("选择错误\n"); break;
//		}
//	} while (input);
//	return 0;
//}


//int main()
//{
//	char input[20] = " ";
//	system("shutdown -s -t 60");//-s、-t前必须有空格 60的单位是秒
//	printf("你的电脑将在60秒后关机，输入“我是猪”来取消关机\n");
//again:
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");//取消关机
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//int main()
//{
//	system("shutdown - s - t 60");//-s、-t前必须有空格 60的单位是秒
//	printf("你的电脑将在60秒后关机，输入“我是猪”来取消关机\n");
//	while (1)
//	{
//		char input[20] = "";
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");//取消关机
//			break;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int a, b, c;
//	int max = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	max = a > b ? a : c;
//	max = max > c ? max : c;
//	printf("%d\n", max);
//}