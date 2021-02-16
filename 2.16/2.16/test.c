#include "Heap.h"


int main()
{
	int a[10] = { 27, 15, 19, 34, 65, 37, 25, 49, 28, 18 };
	Heap* hp = HeapCreate(a, 10);
	HeapPrint(hp);

	HeapPush(hp, 9);
	HeapPush(hp, 50);
	HeapPush(hp, 90);
	HeapPush(hp, 100);
	HeapPush(hp, 27);
	HeapPrint(hp);

    return 0;
}