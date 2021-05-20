#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Student
{
	char id[10];
	char name[25];
	int seat;
}student;

void Swap(student* a, student* b);
void MergeSort(student* a, int n);
void _MergeSort(student* a, int left, int right, student* tmp);

int main()
{
	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("out.txt", "w");
	student t1[105];
	memset(t1, 0, sizeof(student));
	int n, i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		fscanf(in, "%s%s%d", t1[i].id, t1[i].name, &t1[i].seat);

	student t2[105];
	memcpy(t2, t1, sizeof(student)* 105);
	MergeSort(t2, n);
	
	fclose(in);
	fclose(out);
	return 0;
}

void Swap(student* a, student* b)
{
	student* temp;
	memset(temp, 0, sizeof(student));
	memcpy(temp, a, sizeof(student));
	memcpy(a, b, sizeof(student));
	memcpy(b, temp, sizeof(student));
}

void MergeSort(student* a, int n)
{
	student* tmp = (student*)malloc(sizeof(student)* n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void _MergeSort(student* a, int left, int right, student* tmp)
{
	int mid = (left + mid) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1].seat < a[begin2].seat)
		{
			memcpy(&tmp[i], &a[begin1], sizeof(student));
			i++;
			begin1++;
		}
		else
		{
			memcpy(&tmp[i], &a[begin2], sizeof(student));
			i++;
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		memcpy(&tmp[i], &a[begin1], sizeof(student));
		i++;
		begin1++;
	}
	while (begin2 <= end2)
	{
		memcpy(&tmp[i], &a[begin2], sizeof(student));
		i++;
		begin2++;
	}
	for (i = left; i <= right; i++)
		memcpy(&a[i], &tmp[i], sizeof(student));
}