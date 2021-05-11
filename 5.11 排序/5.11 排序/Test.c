#include "sort.h"

int main()
{
	int a[] = { 4, 3, 7, 1, 9, 8, 4, 3, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, n);
	//ShellSort(a, n);
	SelectSort(a, n);
	PrintArray(a, n);
	return 0;
}