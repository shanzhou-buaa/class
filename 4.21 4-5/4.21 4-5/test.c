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
//	int num = 1;//������
//	int people[10000];
//	scanf("%d", &t);//������
//
//	for (i = 1; i <= t; i++)
//	{
//		scanf("%d", &people[i]);//2 5 13 11
//		for (j = num; j < num + people[i]; j++)
//		{
//			cus[j].num = j;//�������
//			cus[j].time = i;//��������
//		}
//		num += people[i];
//	}
//	
//	int remain = 0;
//	int windows = 3;
//	for (i = 1; i <= t; i++)
//	{
//		remain += people[i];//��ǰʣ������
//		rear += people[i];//��β
//		if (remain <= 3)//����remain����
//		{
//			windows = 3;
//			for (j = front; j < front + remain; j++)
//				cus[j].time = i - cus[j].time;
//			front += remain;//front���remain��
//			remain = 0;//����remain
//		}
//		else
//		{
//			if (remain > 3 && remain < 21)
//			{
//				windows = 3;
//				for (j = front; j < front + windows; j++)
//					cus[j].time = i - cus[j].time;
//				front += windows;//front���3��
//				remain -= windows;//����remain
//			}
//			else if (remain >= 21 && remain < 28)
//			{
//				windows = 4;
//				for (j = front; j < front + windows; j++)
//					cus[j].time = i - cus[j].time;
//				front += windows;//front���4��
//				remain -= windows;//����remain
//			}
//			else if (remain >= 28)
//			{
//				windows = 5;
//				for (j = front; j < front + windows; j++)
//					cus[j].time = i - cus[j].time;
//				front += windows;//front���5��
//				remain -= windows;//����remain
//			}
//		}
//	}
//	while (remain > 0)
//	{
//		if (remain <= 3)//����remain����
//		{
//			for (j = front; j < front + remain; j++)
//				cus[j].time = i - cus[j].time;
//			front += remain;//front���remain��
//			remain = 0;//����remain
//		}
//		else
//		{
//			if (remain < 28)
//			{
//				windows = 3;
//				for (j = front; j < front + windows; j++)
//					cus[j].time = i - cus[j].time;
//				front += windows;//front���3��
//				remain -= windows;//����remain
//			}
//			else if (remain >= 28 && remain < 35)
//			{
//				windows = 4;
//				for (j = front; j < front + windows; j++)
//					cus[j].time = i - cus[j].time;
//				front += windows;//front���4��
//				remain -= windows;//����remain
//			}
//			else if (remain >= 35)
//			{
//				windows = 5;
//				for (j = front; j < front + windows; j++)
//					cus[j].time = i - cus[j].time;
//				front += windows;//front���5��
//				remain -= windows;//����remain
//			}
//		}
//		i++;
//	}
//
//	for (i = 1; i < num; i++)
//		printf("%d : %d\n", cus[i].num, cus[i].time);
//	return 0;
//}