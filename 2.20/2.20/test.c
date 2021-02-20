#include "sort.h"

//int main()
//{
//
//	//testInsertSort();
//	//testShellSort();
//	//testSelectSort();
//	int a[] = { 5, 6, 4, 7, 1, 3, 2, 5, 6, 44 };
//	int n = sizeof(a) / sizeof(a[0]);
//	Print(a, n);
//	int i, j;
//	int min, max;
//	int minNum = 0, maxNum = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//
//		min = a[i];
//		max = a[i];
//		for (j = i; j < n - i; j++)
//		{
//			if (a[j] < min)
//			{
//				min = a[j];
//				minNum = j;
//			}
//			if (a[j] > max)
//			{
//				max = a[j];
//				maxNum = j;
//			}
//		}
//		_swap(&a[i], &a[minNum]);
//		if (i == maxNum)
//			maxNum = minNum;
//		_swap(&a[n - i - 1], &a[maxNum]);
//		printf("%d:", i);
//		Print(a, n);
//	}
//	Print(a, n);
//
//    return 0;
//}


int main()
{
	//testInsertSort();
	testShellSort();
	return 0;
}