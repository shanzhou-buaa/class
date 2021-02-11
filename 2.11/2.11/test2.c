#include "SList.h"

void test1()
{
	SLN* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 100);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 11);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListDestroy(&plist);
}


void test2()
{
	SLN* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 100);
	SListPushFront(&plist, 3);

	SListPrint(plist);

	SLN* ret = SListFind(plist, 100);
	//ret->data = 30;相当于修改某一个值
	SListInsertAfter(ret, 50);//在100的位置后面插入50
	SListInsertAfter(ret, 90);//在100的位置后面插入90

	ret = SListFind(plist, 1);
	SListInsertAfter(ret, 0);
	SListPrint(plist);

	SListDestroy(&plist);
}

void test3()
{
	SLN* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 100);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 11); 
	SListPrint(plist);
	
	/*SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);*/

	SLN* ret = SListFind(plist, 11);
	SListErase(ret);
	SListPrint(plist);

	ret = SListFind(plist, 3);
	SListErase(ret);
	SListPrint(plist);

	SListDestroy(&plist);
}
int main()
{
	test1();
	//test2();
	//test3();
    return 0;
}