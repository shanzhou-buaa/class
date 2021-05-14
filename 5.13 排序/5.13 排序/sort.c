#include "sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void AjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		AjustDown(a, n, i);

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AjustDown(a, end, 0);
		end--;
	}
}

//ð�����򣬲�������
//�ӽ����򣬲��������
void BubbleSort(int* a, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 1;//flag��1˵������ð��û��������
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}

//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	int num1 = a[left];
	int num2 = a[mid];
	int num3 = a[right];

	if (num1 > num2)
	{
		if (num2 > num3)//num1 > num2 > num3
			return num3;
		else//num2 <= num3 && num2 < num1
		{
			if (num1 > num3)//num1 > num3 > num2
				return num3;
			else//num3 > num1 > num2
				return num1;
		}
	}
	else//num1 <= num2
	{
		if (num1 > num3)//num2 > num1 > num3
			return num1;
		else//num2 > num1 && num3 > num1
		{
			if (num2 > num3)
				return num3;
			else
				return num2;
		}
	}
}

//�����ڱ���
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key_i = left;
	while (left < right)
	{
		//right��С
		while (left < right && a[right] >= a[key_i])
			right--;

		//left�Ҵ�
		while (left < right && a[left] <= a[key_i])
			left++;

		Swap(&a[left], &a[right]);
	}

	//left == right
	int meet_i = left;
	Swap(&a[key_i], &a[meet_i]);

	return meet_i;
}

//�ڿ�
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	//cur��prev��ʼһǰһ��
	int cur = left + 1, prev = left;
	int keyi = left;

	while (cur <= right && prev < right)
	{
		//cur�ұ�keyiС��λ��
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		
		cur++;
	}
	Swap(&a[keyi], &a[prev]);

	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int mid = PartSort3(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}

#include "stack.h"
void QuickSortNonR(int* a, int begin, int end)
{
	stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

		if (right > keyi + 1)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}

void _Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int begin = begin1;
	int i = begin1;

	//��������������С��ֵβ��
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}

	//��ʣ������ݿ�����tmp�У���������ѭ��ֻ��һ��
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	//�鲢��������tmp�ж�Ӧλ�õ�����ȫ��������ȥ
	for (i = begin; i <= end2; i++)
		a[i] = tmp[i];
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	//�ݹ�ʹ����������������
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�������������Ѿ���������ʹ������������
	_Merge(a, left, mid, mid + 1, right, tmp);
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	int i = 0, gap = 1;
	while (gap < n)
	{
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			
			//�ڶ���С�鳬�����鷶Χ��˵��������ֻ�е�һ��С�飬����һ��С���Ѿ����ź���ģ�ֱ���˳�
			if (begin2 >= n)
				break;
			
			//�ڶ���С��ĩβ�������鷶Χ����������ĩβ��֤��Խ��
			if (end2 >= n)
				end2 = n - 1;
			_Merge(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
}

void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}