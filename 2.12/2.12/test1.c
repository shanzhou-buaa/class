#include "ListNode.h"

void test1()
{
	LN* list = ListCreate();
	//list头链表没有数据
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3); 
	ListPushBack(list, 4);

	ListPrint(list);

	ListPopBack(list);
	ListPrint(list);
	/*ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);*/
}

void test2()
{
	LN* list = ListCreate();
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPrint(list);

	ListPopFront(list);
	ListPrint(list);

	/*ListPopFront(list);
	ListPrint(list);

	ListPopFront(list);
	ListPrint(list);

	ListPopFront(list);
	ListPrint(list);*/
}

void test3()
{
	LN* list = ListCreate();
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPushFront(list, 5);
	ListPushFront(list, 6);
	ListPushFront(list, 7);
	ListPrint(list);
	 
	LN* ret = ListFind(list, 3);
	ListInsert(ret, 100);
	ListPrint(list);

	ret = ListFind(list, 3);
	ListErase(ret);
	ListPrint(list);

}

int main()
{
	test1();
	test2();
	test3();
    return 0;
}