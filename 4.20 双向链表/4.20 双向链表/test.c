#include "dlist.h"

void test1()
{
	dln* phead = DListNodeInit();
	DListNodePushBack(phead, 1);
	DListNodePushBack(phead, 2);
	DListNodePushBack(phead, 3);
	DListNodePushBack(phead, 4);
	DListNodePushBack(phead, 5);

	DListNodePrint(phead);

	DListNodePopBack(phead);
	DListNodePrint(phead);

	DListNodePopBack(phead);
	DListNodePrint(phead);

	//DListNodePopBack(phead);
	//DListNodePrint(phead);
	//DListNodePopBack(phead);
	//DListNodePrint(phead);
	//DListNodePopBack(phead);
	//DListNodePrint(phead);
}

void test2()
{
	dln* phead = DListNodeInit();
	DListNodePushFront(phead, 1);
	DListNodePushFront(phead, 2);
	DListNodePushFront(phead, 3);
	DListNodePushFront(phead, 4);
	DListNodePushFront(phead, 5);

	DListNodePrint(phead);

	DListNodePopFront(phead);
	DListNodePrint(phead);

}


void test3()
{
	dln* phead = DListNodeInit();
	DListNodePushBack(phead, 1);
	DListNodePushBack(phead, 2);
	DListNodePushBack(phead, 3);
	DListNodePushBack(phead, 4);
	DListNodePushBack(phead, 5);
	DListNodePrint(phead);

	dln* find = DListNodeFind(phead, 3);
	//printf("%d\n", find->val);
	if (find)
	{
		DListNodeInsertBefore(find, 400);
		DListNodePrint(phead);
	}

	printf("%d\n", DListNodeEmpty(phead));
	printf("%d\n", DListNodeSize(phead));

	phead = NULL;
}

int main()
{
	test3();
	return 0;
}