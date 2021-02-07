#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//enum color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum color C = GREEN;
//    return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(20);
//	int i = 0;
//	if (p != NULL)//一定要对进行是否为空指针的判断
//	{
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 5; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	int* ptr = (int*)realloc(p, 40);
//	if (ptr != NULL)//一定要对进行是否为空指针的判断
//	{
//		p = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//
//	free(p);
//	p = NULL;
//	//这两个语句写上比较安全
//  //free后不会把p置为NULL
//	return 0;
//}
//realloc的注意事项
//1.如果p指向的空间后面有足够的内存空间足够追加
//则直接追加，完成后返回p
//2.如果p指向的空间后面没有足够的内存空间足够追加
//则realloc会重新找一块内存区域，开辟一块满足需要的内存空间
//并把原来内存空间中的内容拷贝过来，同时释放旧的内存空间
//(注意此时p指向的空间会变化)
//3.建议用一个新的变量来接受realloc函数的返回值

//动态内存管理注意事项
//1.开辟空间后一定要对指针进行是否为空指针的判断
//2.注意强制类型转换
//3.注意不要越界访问
//4.不要free非动态开辟内存的指针


//5.free释放动态开辟内存的一部分
//int main()
//{
//	int* p = malloc(40);
//	if (p != NULL)
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*p++ = i;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//6.不能对同一块动态开辟的内存多次释放
//7.一定要free
//int main()
//{
//	while (1)
//	{
//		malloc(20);
//		//内存被疯狂消耗(内存泄漏)
//	}
//	return 0;
//}

//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//	int* p = (int*)calloc(10, sizeof(int));
//	//calloc会自动把元素全部初始化为0
//	if (p != NULL)
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	int arr[];
//	//这个数组是柔性数组，未知大小(可改变)
//	//需要用malloc或者calloc初始化大小
//  //柔性数组前面必须至少包含一个结构体成员
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	//							 这里计算大小不算柔型数组
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps -> arr[i]);
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}


//typedef struct S
//{
//	int a;
//	int* arr;
//}S;
//int main()
//{
//	int i;
//	S* ps = (S*)malloc(sizeof(S));
//	ps->arr = malloc(5 * sizeof(int));
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	int* ptr = realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//}

