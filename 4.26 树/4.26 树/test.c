#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//���µ����㷨
//������ֻ�ܵ����ڵ������������ΪС��ʱʹ��(�����������Ҫ)
//1.ѡ�����Һ�����С����һ��c
//2.С���������c�͸���p��
//	a.��c�ȸ���pС���������������µ���ֱ��p�ߵ�Ҷ���
//	b.��c��p�󣬲���Ҫ������������ɣ��������Ѿ����С��
void AdjustDown_recursive(int* a, int sz, int parent)//�ݹ�ʵ��
{
	int child = parent * 2 + 1;//�������ӱȽ�С
	if (child >= sz)
		return;
	if (child + 1 < sz && a[child] > a[child + 1])//�Һ���С
		child++;

	//С��������Ӻ͸��ױ�
	//����С������
	if (a[child] < a[parent])
	{
		Swap(&a[child], &a[parent]);
		AdjustDown_recursive(a, sz, child);
	}
	//���״󣬵�������
	else
		return;
}

void AdjustDown(int* a, int sz, int parent)//ѭ��ʵ��
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		if (child + 1 < sz && a[child] > a[child + 1])//�Һ���С
			child++;

		//С��������Ӻ͸��ױ�
		//����С������
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//���״󣬵�������
		else
			break;
	}
}
void Print(int* a, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//int main()
//{
//	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	int sz = sizeof(a) / sizeof(a[0]);
//
//	AdjustDown(a, sz, 0);
//	Print(a, sz);
//
//	return 0;
//}

//����ʱ�临�Ӷ�O(N)
//�����򣬽����
//�Ž��򣬽�С��
void HeapSort(int* a, int sz)
{
	int i;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, sz, i);
	}

	int end = sz - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

int main()
{
	int a[] = { 15, 18, 28, 34, 65, 9, 49, 25, 37, 27 };
	int sz = sizeof(a) / sizeof(a[0]);
	int i = 0;

	HeapSort(a, sz);
	Print(a, sz);

	return 0;
}