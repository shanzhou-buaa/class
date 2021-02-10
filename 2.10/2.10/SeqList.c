#include "Seqlist.h"


void SLInit(SL* ps)
{
	ps->a = (SLData*)malloc(sizeof(SL) * 4);
	if (ps->a == NULL)
	{
		printf("…Í«Îƒ⁄¥Ê ß∞‹\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//Œ≤≤Â
void SLPushBack(SL* ps, SLData x)
{
	assert(ps);
	SLCheck(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//Œ≤…æ
void SLPopBack(SL* ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}

//Õ∑≤Â
void SLPushFront(SL* ps, SLData x)
{
	assert(ps);
	SLCheck(ps);
	int i = 0;
	for (i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

//Õ∑…æ
void SLPopFront(SL* ps)
{
	int start = 0;
	while (start <= ps->size - 2)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

//»Œ“‚Œª÷√≤Â»Î
void SLInsert(SL* ps, int pos, SLData x)
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	SLCheck(ps);
	int i = pos;
	for (i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

//»Œ“‚Œª÷√…æ≥˝
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	SLCheck(ps);
	while (pos < ps->size - 1)
	{
		ps->a[pos] = ps->a[pos + 1];
		pos++;
	}
	ps->size--;
}

void SLPrint(SL* ps)
{
	assert(ps);
	int i;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


void SLCheck(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLData*)realloc(ps->a, sizeof(SL)* (ps->capacity));
		if (ps->a == NULL)
		{
			printf("¿©»› ß∞‹\n");
			exit(-1);
		}
	}
}


void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
}


void SLBubbleSort(SL* ps)
{
	int i = 0, j = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->a[j] > ps->a[j + 1])
			{
				SLData tmp = ps->a[j];
				ps->a[j] = ps->a[j + 1];
				ps->a[j + 1] = tmp;
				flag = 1;
			}
		}
			if (flag == 0)
			{
				return;
			}
	}
}


int SLBinarySearch(SL* ps, SLData x, int left, int right)
{
	int mid = left + (right - left) / 2;
	while (left <= right)
	{
		if (ps->a[mid] < x)
		{
			return SLBinarySearch(ps, x, mid + 1, right);
		}
		else if (ps->a[mid] > x)
		{
			return SLBinarySearch(ps, x, left, mid - 1);
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
