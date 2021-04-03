#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//int main()
//{
//	int* p = (int*)malloc(sizeof(int)* 10);
//
//	if (p == NULL)//检查是否开辟成功
//	{
//		printf("开辟失败\n");
//		return 0;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	free(p);//释放空间
//
//	return 0;
//}


//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		printf("开辟失败\n");
//		return 0;
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	int* newptr = (int*)realloc(p, sizeof(int)* 50);

	printf("%p\n", p);
	printf("%p\n", newptr);
	
	return 0;
}
