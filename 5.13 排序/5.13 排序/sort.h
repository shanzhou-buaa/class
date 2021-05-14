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

int PartSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

int GetMidIndex(int* a, int left, int right);

void QuickSortNonR(int* a, int begin, int end);

void _MergeSort(int* a, int left, int right, int* tmp);

void MergeSort(int* a, int n);

void _Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp);

void MergeSortNonR(int* a, int n);