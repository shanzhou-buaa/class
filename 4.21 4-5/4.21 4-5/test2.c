//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
//typedef struct customer
//{
//	int num;
//	int time;
//}customer;
//
//int main()
//{
//	customer cus[10000];
//	int t, i = 0, j = 0;
//	int front = 1, rear = 0;
//	int num = 1;//总人数
//	int people[10000];
//	scanf("%d", &t);//周期数
//
//	for (i = 1; i <= t; i++)
//	{
//		scanf("%d", &people[i]);//2 5 13 11
//		for (j = num; j < num + people[i]; j++)
//		{
//			cus[j].num = j;//设置序号
//			cus[j].time = i;//设置周期
//		}
//		num += people[i];
//	}
//
//	int remain = 0;
//	for (i = 1; i <= t; i++)
//	{
//		remain += people[i];//当前剩几个人
//		rear += people[i];//队尾
//		if (remain <= 3)//处理remain个人
//		{
//			for (j = front; j < front + remain; j++)
//				cus[j].time = i - cus[j].time;
//			front += remain;//front向后remain个
//			remain = 0;//更新remain
//		}
//		else
//		{
//			if (remain > 3 && remain < 21)
//			{
//				for (j = front; j < front + 3; j++)
//				{
//					cus[j].time = i - cus[j].time;
//					remain--;
//				}
//				front += 3;//front向后3个
//			}
//			else if (remain >= 21 && remain < 28)
//			{
//				int flag = 1;//判断在进行过程中窗口是否变化
//				//1说明没变化
//				for (j = front; j < front + 4; j++)
//				{
//					cus[j].time = i - cus[j].time;
//					remain--;
//					if (remain < 21)
//					{
//						flag = 0;
//						for (; j < front + 3; j++)
//						{
//							cus[j].time = i - cus[j].time;
//							remain--;
//						}
//					}
//					if (flag == 0)
//						break;
//				}
//				if (flag == 1)
//					front += 4;//front向后4个
//				else
//					front += 3;
//			}
//			else if (remain >= 28)
//			{
//				int flag = 1;//判断在进行过程中窗口是否变化
//				for (j = front; j < front + 5; j++)
//				{
//					cus[j].time = i - cus[j].time;
//					remain--;
//					if (remain < 28)
//					{
//						flag = 0;
//						for (; j < front + 4; j++)
//						{
//							cus[j].time = i - cus[j].time;
//							remain--;
//						}
//					}
//					if (flag == 0)
//						break;
//				}
//				if (flag == 1)
//					front += 5;//front向后4个
//				else
//					front += 4;
//			}
//		}
//	}
//	while (remain > 0)
//	{
//		if (remain <= 3)//处理remain个人
//		{
//			for (j = front; j < front + remain; j++)
//				cus[j].time = i - cus[j].time;
//			front += remain;//front向后remain个
//			remain = 0;//更新remain
//		}
//		else
//		{
//			if (remain > 3 && remain < 21)
//			{
//				for (j = front; j < front + 3; j++)
//				{
//					cus[j].time = i - cus[j].time;
//					remain--;
//				}
//				front += 3;//front向后3个
//			}
//			else if (remain >= 21 && remain < 28)
//			{
//				int flag = 1;//判断在进行过程中窗口是否变化
//				//1说明没变化
//				for (j = front; j < front + 4; j++)
//				{
//					cus[j].time = i - cus[j].time;
//					remain--;
//					if (remain < 21)
//					{
//						flag = 0;
//						for (; j < front + 3; j++)
//						{
//							cus[j].time = i - cus[j].time;
//							remain--;
//						}
//					}
//					if (flag == 0)
//						break;
//				}
//				if (flag == 1)
//					front += 4;//front向后4个
//				else
//					front += 3;
//			}
//			else if (remain >= 28)
//			{
//				int flag = 1;//判断在进行过程中窗口是否变化
//				for (j = front; j < front + 5; j++)
//				{
//					cus[j].time = i - cus[j].time;
//					remain--;
//					if (remain < 28)
//					{
//						flag = 0;
//						for (; j < front + 4; j++)
//						{
//							cus[j].time = i - cus[j].time;
//							remain--;
//						}
//					}
//					if (flag == 0)
//						break;
//				}
//				if (flag == 1)
//					front += 5;//front向后4个
//				else
//					front += 4;
//			}
//		}
//		i++;
//	}
//
//	for (i = 1; i < num; i++)
//		printf("%d : %d\n", cus[i].num, cus[i].time);
//	return 0;
//}