#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//int func(int n)
//{
//	int sum = 0;
//	int num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
//	while (n / 10 != 0)
//	{ 
//		int tmp = n % 10;
//		sum += num[tmp];
//		n /= 10;
//	}
//	sum += num[n];
//	return sum;
//}

//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		printf("%d\n", func(n));
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int i, j, sum = 0;
//	int m;
//	scanf("%d", &m);
//	for (i = 0; i <= 111; i++)
//	{
//		for (j = 0; j <= 111; j++)
//		{
//			if (func(i) + func(j) + func(i + j) == m - 4)
//			{
//				printf("%d + %d = %d\n", i, j, i + j);
//				sum++;
//			}
//		}
//	}
//	printf("%d\n", sum);
//    return 0;
//}


int ADD(int x, int y)
{
	return x + y;
}

int SUB(int x, int y)
{
	return x - y;
}

int MUL(int x, int y)
{
	return x * y;
}

int DIV(int x, int y)
{
	return x / y;
}
//int main()
//{
//	int(*p)(int, int) = &ADD;
//	int(*pArr[2])(int, int) = { 0, ADD };
//	int(*(*ppArr)[2])(int, int) = &pArr;//指向函数指针数组的指针
//	return 0;
//}


//void test(int(*p)(int, int))
//{
//	printf("%d", p(2, 3));
//}
//int main()
//{
//	test(ADD);
//	return 0;
//}


void calc(int(*p)(int, int))
{
	int x, y;
	printf("请输入两个数");
	scanf("%d%d", &x, &y);
	printf("%d\n", (p(x, y)));
}

//int main()
//{
//	int input;
//	//int(*pfArr[])(int, int) = { 0, ADD, SUB, MUL, DIV };
//	do
//	{
//		printf("0.退出\n1.加\n2.减\n3.乘\n4.除\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//		{
//				  printf("退出\n");
//				  break;
//		}
//		case 1:
//		{
//				  calc(ADD);
//				  break;
//		}
//		case 2:
//		{
//				  calc(SUB);
//				  break;
//		}
//		case 3:
//		{
//				  calc(MUL);
//				  break;
//		}
//		case 4:
//		{
//				  calc(DIV);
//				  break;
//		}
//		default:
//		{
//			printf("错\n");
//			break;
//		}
//		}
//	} while (input);
//}


//void* 类型的指针可以接收任何类型的地址
//但不能进行解引用操作和++，--操作


int cmp_int(const char* e1, const char** e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test1()
{
	int arr[] = { 0, 50, 6, 99, 12, 0, 506, 329 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
}
struct STU
{
	char name[50];
	int age;
};
int cmp_stu_age(const char* e1, const char** e2)
{
	return ((struct STU*)e1)->age - ((struct STU*)e2)->age;
}
int cmp_stu_name(const char* e1, const char** e2)
{
	return strcmp(((struct STU*)e1)->name, ((struct STU*)e2)->name);
}
void test2()
{
	struct STU arr[] = { { "zhangsan", 20 }, { "lisi", 17 }, { "wangwu", 29 }, { "zhaoliu", 42 } };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_stu_age);
	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_name);
}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}

//void qsort(void*base,size_t sz,size_t width,int(*com)(const void*e1,const void*e2));
//void _swap(char* e1, char* e2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *e1;
//		*e1 = *e2;
//		*e2 = tmp;
//		e1++;
//		e2++;
//	}
//}
//void bubble_qsort(void* base, size_t sz, size_t width, int(*cmp)(const void* e1, const void* e2))
//{
//	size_t i, j;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	struct STU arr[] = { { "zhangsan", 20 }, { "lisi", 17 }, { "wangwu", 29 }, { "zhaoliu", 42 } };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_qsort(arr, sz, sizeof(arr[0]), cmp_stu_age);
//}


int main()
{
	int a[3][4] = { 0 };
	printf("%p\n", a + 1);
	printf("%p\n", &a[1][0]);
	return 0;
}