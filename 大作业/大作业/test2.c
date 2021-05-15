//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef struct sen_num
//{
//	int index;
//	int times;
//}sen_num;
//
//void PrintArray(sen_num* a, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d %d\n", a[i].index, a[i].times);
//	}
//	printf("\n");
//}
//
//void MergeArr(sen_num* a, int begin1, int end1, int begin2, int end2, sen_num* tmp)
//{
//	int left = begin1, right = end2;
//	int index = begin1;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1].times >= a[begin2].times)
//		{
//			tmp[index].index = a[begin1].index;
//			tmp[index].times = a[begin1].times;
//			index++;
//			begin1++;
//		}
//		else
//		{
//			tmp[index].index = a[begin2].index;
//			tmp[index].times = a[begin2].times;
//			index++;
//			begin2++;
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[index].index = a[begin1].index;
//		tmp[index].times = a[begin1].times;
//		index++;
//		begin1++;
//	}
//	while (begin2 <= end2)
//	{
//		tmp[index].index = a[begin2].index;
//		tmp[index].times = a[begin2].times;
//		index++;
//		begin2++;
//	}
//	int i = 0;
//	for (i = left; i <= right; i++)
//	{
//		a[i].index = tmp[i].index;
//		a[i].times = tmp[i].times;
//	}
//}
//
//void MergeSort(sen_num* a, int n)
//{
//	sen_num* tmp = (sen_num*)malloc(sizeof(sen_num) * n);
//	int gap = 1, i = 0;
//	while (gap < n)
//	{
//		for (i = 0; i < n; i += 2 * gap)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//
//			if (begin2 >= n)
//				break;
//
//			if (end2 >= n)
//				end2 = n - 1;
//
//			MergeArr(a, begin1, end1, begin2, end2, tmp);
//		}
//		PrintArray(a, n);
//		gap *= 2;
//	}
//	free(tmp);
//}
//
//int comp(const void* a, const void* b)
//{
//	sen_num pa = *(sen_num*)a;
//	sen_num pb = *(sen_num*)b;
//
//	return (pb.times - pa.times);
//}
//
//int main()
//{
//	sen_num sn[] = { { 1, 10 }, { 5, 30 }, { 4, 35 }, { 6, 90 }, { 53, 36 }, { 5, 30000 } };
//	int n = sizeof(sn) / sizeof(sn[0]);
//	//MergeSort(sn, n);
//	qsort(sn, n, sizeof(sn[0]), comp);
//
//	PrintArray(sn, n);
//	return 0;
//}
//
//
