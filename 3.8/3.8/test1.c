#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//位段：二进制位
//在一定程度上节省空间
//struct A
//{
//	int _a : 2; //_a只需要2个比特位
//	//int a;//a需要32个比特位
//	int _b : 5; //_b只需要5个比特位
//	int _c : 10;//_c只需要10个比特位
//	int _d : 20;//_d只需要20个比特位
//	//不能超过int的大小
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}


//联合体（共用体）
//成员占用同一块空间
//改变c也会改变i
//所以不能同时改变
//union un
//{
//	char c;
//	int i;
//	//double d;
//};
//int main()
//{
//	union un u;
//	printf("%d\n", sizeof(u));
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}


