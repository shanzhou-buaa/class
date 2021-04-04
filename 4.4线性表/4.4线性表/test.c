#include "SeqList.h"

//˳���ȱ��
//1.��̬��������������
//2.ͷ����������ʱ����ҪŲ������

void test1()
{
	sl seq;
	SeqListInit(&seq);

	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 7);
	SeqListPushBack(&seq, 6);

	SeqListPrint(&seq);
	printf("%d\n", seq.size);
	printf("%d\n", seq.capacity);

	SeqListDestroy(&seq);
}

void test2()
{
	sl seq;
	SeqListInit(&seq);

	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 5);
	SeqListPushBack(&seq, 6);

	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopFront(&seq);

	SeqListPrint(&seq);
	SeqListDestroy(&seq);
}

void test3()
{
	sl seq;
	SeqListInit(&seq);

	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 5);
	SeqListPushBack(&seq, 6);
	SeqListPrint(&seq);

	SeqListInsert(&seq, 2, 10);
	SeqListInsert(&seq, 1, 102);
	SeqListPrint(&seq);

	SeqListErase(&seq, 3);
	SeqListPrint(&seq);

	SeqListErase(&seq, 6);
	SeqListPrint(&seq);

	SeqListModify(&seq, 0, -100);
	SeqListPrint(&seq);

	SeqListModify(&seq, 3, -10);
	SeqListPrint(&seq);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}