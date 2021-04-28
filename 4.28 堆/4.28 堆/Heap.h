#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��ѣ���ǰx�����
typedef int data;

typedef struct Heap
{
	data* a;
	int size;//��ǰ�������ݸ���
	int capacity;//�������
}HP;

void AdjustUp(int* a, int child);

void AdjustDown(int* a, int n, int parent);

void Swap(int* a, int* b);

void HeapInit(HP* php, data* a, int n);

void HeapDestroy(HP* php);

void HeapPush(HP* php, data x);

//ɾ���Ѷ����ݣ����Ļ���С�ģ�
void HeapPop(HP* php);

//�õ��Ѷ�����
data HeapTop(HP* php);

int HeapSize(HP* php);

bool HeapEmpty(HP* php);

void HeapPrint(HP* php);