#include "Seqlist.h"

void TestSL(SL* ps)
{
	SLPushBack(ps, 3);
	SLPushBack(ps, 1);
	SLPushBack(ps, 2);
	SLPushBack(ps, 4);
	SLPushBack(ps, 5);
	SLPushBack(ps, 8);
	SLPushBack(ps, 7);
	SLPushBack(ps, 6);
	//SLPushBack(ps, 9);
	SLPrint(ps);

	/*SLPopBack(ps);
	SLPopBack(ps);
	SLPrint(ps);

	SLPushFront(ps, 0);
	SLPushFront(ps, -1);
	SLPushFront(ps, -2);
	SLPushFront(ps, -3);
	SLPrint(ps);

	SLPopFront(ps);
	SLPopFront(ps);
	SLPrint(ps);

	SLInsert(ps, 2, 1000);
	SLInsert(ps, 5, 2000);*/
	//printf("%d\n", ps->size);
	SLBubbleSort(ps);
	SLPrint(ps);

	/*SLErase(ps, 7);
	SLErase(ps, 3);
	SLBubbleSort(ps);
	SLPrint(ps);*/
	
	int ret = SLBinarySearch(ps, 6, 0, ps->size - 1);
	printf("%d\n", ret);

	SLDestroy(ps);
}
int main()
{
	SL s;
	SLInit(&s);
	TestSL(&s);
	return 0;
}