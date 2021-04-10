#include "ListNode.h"

void test1()
{
	ln* plist = NULL;
	ListNodePushBack(&plist, 1);
	ListNodePushBack(&plist, 2);
	ListNodePushBack(&plist, 3);

	ListNodePrint(plist);

	ListNodePushFront(&plist, -1);
	ListNodePushFront(&plist, -2);

	ListNodePrint(plist);

	ListNodePopBack(&plist);
	ListNodePrint(plist);

}

void test2()
{
	ln* plist = NULL;
	ListNodePushBack(&plist, 3);
	ListNodePushBack(&plist, 4);
	ListNodePushBack(&plist, 5);
	ListNodePushFront(&plist, 2);
	ListNodePushFront(&plist, 1);

	ListNodePrint(plist);

	ListNodePopFront(&plist);
	ListNodePopFront(&plist);
	ListNodePopFront(&plist);
	ListNodePopBack(&plist);
	//ListNodePopFront(&plist);
	//ListNodePopFront(&plist);
	//ListNodePopFront(&plist);

	ListNodePrint(plist);
}

void test3()
{
	ln* plist = NULL;
	ListNodePushBack(&plist, 3);
	ListNodePushBack(&plist, 4);
	ListNodePushBack(&plist, 5);
	ListNodePushFront(&plist, 2);
	ListNodePushFront(&plist, 1);

	ln* find = ListNodeFind(plist, 2);
	if (find == NULL)
	{
		printf("no\n");
		ListNodePrint(plist);
	}
	else
	{
		printf("%d\n", find->a);
		//find->a = 30;//查找完可以修改链表
		//ListNodeInsertAfter(find, 30);
		ListNodeEraseAfter(find);
		ListNodePrint(plist);
	}
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}