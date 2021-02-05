#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

//void* my_memcpy(void* dest, const void* src, size_t n)
//{
//	assert(dest&&src);
//	void* start = dest;
//	while (n--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//	return start;
//}

//void my_memmove(void* dest, const void* src, size_t n)
//{
//	void* ret = dest;
//	if (dest < src)
//	{
//		while (n--)
//		{
//			*(char*)dest = *(char*)src;
//			((char*)dest)++;
//			((char*)src)++;
//		}
//	}
//	else
//	{
//		while (n--)
//		{
//			*((char*)dest + n) = *((char*)src + n);
//		}
//	}
//}

//struct man
//{
//	char name[50];
//	int age;
//};

//int main()
//{
//	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arr2[5] = { 0 };
//	struct man M1[2] = { { "zhangsan", 50 }, { "lisi", 20 } };
//	struct man M2[5] = { 0 };
//	//memcpy(arr2, arr1, 20);
//	my_memcpy(M2, M1, sizeof(M1));
//	my_memmove(arr1, arr1 + 2, 20);
//	return 0;
//}


