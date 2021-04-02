#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum Sex
{
	Male,
	Female
};

//enum Weekday//星期
//{
//	Mon,//变量间用逗号分开
//	Tue,
//	Wed,
//	Thu,
//	Fri,
//	Sat,
//	Sun//注意最后一个变量后没有逗号
//};

enum Weekday//星期
{
	//给某个量赋初始值，则从该量开始递增1
	//该量之前的不受影响
	Mon,//0
	Tue,//1
	Wed = 10,//10
	Thu,//11
	Fri,//12
	Sat,//13
	Sun//14
};

//联合类型的声明
//union Un
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	//联合变量的定义
//	union Un un;
//	//计算联合体变量的大小
//	printf("%d\n", sizeof(un));
//	un.c = 1;
//
//	return 0;
//}

//
//union Un
//{
//	int a;
//	int b;
//	int c;
//};
//
//int main()
//{
//	union Un un;
//	un.a = 1;
//	printf("%d\n", un.b);//1
//	printf("%d\n", un.c);//1
//
//	un.b = 2;
//	printf("%d\n", un.a);//2
//	printf("%d\n", un.c);//2
//
//	printf("%d\n", &(un.a));
//	printf("%d\n", &(un.b));
//	printf("%d\n", &(un.c));
//
//	return 0;
//}


union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un1)); //
	printf("%d\n", sizeof(union Un2));//
	return 0;
}