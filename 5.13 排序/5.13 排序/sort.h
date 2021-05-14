#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void Swap(int* a, int* b);

void PrintArray(int* a, int n);

//ÉýÐò£¬½¨´ó¶Ñ
void AjustDown(int* a, int n, int root);

void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);

int PartSort(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

int GetMidIndex(int* a, int left, int right);