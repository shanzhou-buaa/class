#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//enum color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum color C = GREEN;
//    return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(20);
//	int i = 0;
//	if (p != NULL)//һ��Ҫ�Խ����Ƿ�Ϊ��ָ����ж�
//	{
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 5; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	int* ptr = (int*)realloc(p, 40);
//	if (ptr != NULL)//һ��Ҫ�Խ����Ƿ�Ϊ��ָ����ж�
//	{
//		p = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//
//	free(p);
//	p = NULL;
//	//���������д�ϱȽϰ�ȫ
//  //free�󲻻��p��ΪNULL
//	return 0;
//}
//realloc��ע������
//1.���pָ��Ŀռ�������㹻���ڴ�ռ��㹻׷��
//��ֱ��׷�ӣ���ɺ󷵻�p
//2.���pָ��Ŀռ����û���㹻���ڴ�ռ��㹻׷��
//��realloc��������һ���ڴ����򣬿���һ��������Ҫ���ڴ�ռ�
//����ԭ���ڴ�ռ��е����ݿ���������ͬʱ�ͷžɵ��ڴ�ռ�
//(ע���ʱpָ��Ŀռ��仯)
//3.������һ���µı���������realloc�����ķ���ֵ

//��̬�ڴ����ע������
//1.���ٿռ��һ��Ҫ��ָ������Ƿ�Ϊ��ָ����ж�
//2.ע��ǿ������ת��
//3.ע�ⲻҪԽ�����
//4.��Ҫfree�Ƕ�̬�����ڴ��ָ��


//5.free�ͷŶ�̬�����ڴ��һ����
//int main()
//{
//	int* p = malloc(40);
//	if (p != NULL)
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*p++ = i;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//6.���ܶ�ͬһ�鶯̬���ٵ��ڴ����ͷ�
//7.һ��Ҫfree
//int main()
//{
//	while (1)
//	{
//		malloc(20);
//		//�ڴ汻�������(�ڴ�й©)
//	}
//	return 0;
//}

//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//	int* p = (int*)calloc(10, sizeof(int));
//	//calloc���Զ���Ԫ��ȫ����ʼ��Ϊ0
//	if (p != NULL)
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	int arr[];
//	//����������������飬δ֪��С(�ɸı�)
//	//��Ҫ��malloc����calloc��ʼ����С
//  //��������ǰ��������ٰ���һ���ṹ���Ա
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	//							 ��������С������������
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps -> arr[i]);
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}


//typedef struct S
//{
//	int a;
//	int* arr;
//}S;
//int main()
//{
//	int i;
//	S* ps = (S*)malloc(sizeof(S));
//	ps->arr = malloc(5 * sizeof(int));
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	int* ptr = realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//}

