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
//		int mid = (left + right) / 2;//left+right�������������
//		//�Ľ�:int mid = left + (right - left) / 2;�������������
//		//����д��a/2+b/2����a=3��b=5  a/2=1��b/2=2 �����һ��
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
//			printf("�ҵ��ˣ��±���%d\n", k);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
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
//	printf("**********    1��play    **********\n");
//	printf("**********    0��exit    **********\n");
//	printf("***********************************\n");
//	printf("������������ѡ��\n");
//}
//void game()
//{
//	printf("��������µ����֣�1 - 100��\n");
//	int ret = rand() % 100 + 1;//rand���������
//	int count = 0;
//	while (1)
//	{
//		int guess = 0;
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n");
//			count++;
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//			count++;
//		}
//		else
//		{
//			printf("�¶���\n");
//			count++;
//			break;
//		}
//	}
//	printf("һ������%d��\n", count);
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//time()��������ʱ���
//	//srand��������rand����㣬��������Ҫһ�����ֵ���������һֱ�仯
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1: printf("��Ϸ��ʼ\n"); game(); break;
//			case 0: printf("�˳���Ϸ\n"); break;
//			default:printf("ѡ�����\n"); break;
//		}
//	} while (input);
//	return 0;
//}


//int main()
//{
//	char input[20] = " ";
//	system("shutdown -s -t 60");//-s��-tǰ�����пո� 60�ĵ�λ����
//	printf("��ĵ��Խ���60���ػ������롰��������ȡ���ػ�\n");
//again:
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");//ȡ���ػ�
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//int main()
//{
//	system("shutdown - s - t 60");//-s��-tǰ�����пո� 60�ĵ�λ����
//	printf("��ĵ��Խ���60���ػ������롰��������ȡ���ػ�\n");
//	while (1)
//	{
//		char input[20] = "";
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
//		{
//			system("shutdown -a");//ȡ���ػ�
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