#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//int main()
//{
//	int *p = NULL;
//	int a[100];
//	printf("%d\n",sizeof(p));//的值是多少？
//	printf("%d\n", sizeof(*p));
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[100]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(&a[0]));
//    return 0;
//}


//int main()
//{
//	int a = 0;
//	//00000000 00000000 00000000 00000000	a
//	int b = ~a;
//	//11111111 11111111 11111111 11111111	b的补码
//	//b原码是-1
//	printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	char a = 3;
//	//00000101	a
//	char b = 127;
//	char c = a + b;
//	//01111111	b
//	//a,b是char型，运算时需整型提升变成int才能算
//	//有符号数直接在前面补原来的符号位
//	//无符号数直接补0
//	//00000000 00000000 00000000 00000011	整型提升后的a
//	//00000000 00000000 00000000 01111111	整型提升后的b
//	//a+b
//	//00000000 00000000 00000000 10000010	整型提升后的c
//	//10000010	截断后的c
//	//11111111 11111111 11111111 10000010	整型提升后的c的补码
//	//11111111 11111111 11111111 10000001	整型提升后的c的反码
//	//10000000 00000000 00000000 01111110	-126
//	printf("%d\n", c);
//}