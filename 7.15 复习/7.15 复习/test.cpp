#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//namespace yh
//{
//	int scanf = 10;
//	int strlen = 20;
//}
//int main()
//{
//	scanf("%d", &yh::scanf);
//	printf("%d\n", yh::scanf);
//	return 0;
//}
//
////1. 普通的命名空间
//namespace N1 // N1为命名空间的名称
//{
//	// 命名空间中的内容，既可以定义变量，也可以定义函数
//	int a;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
////2. 命名空间可以嵌套
//namespace N2
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
////3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%d %p\n", a, p);
//	cout << a << " " << p << endl;
//	return 0;
//}

void test1(int a = 10)
{
	cout << a << endl;
}

void test2(int a = 10, int b = 20, int c = 30) 
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;
}

//void test3(int a, int b = 10, int c = 20) 
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	cout << endl;
//}
//
//int main()
//{
//	//test3();//a的值不确定，不合法
//
//	//函数中a的值必须给出
//	test3(1);
//	test3(1, 2);
//	test3(1, 2, 3);
//	return 0;
//}


int Add(int left, int right) 
{
	return left + right;
}
double Add(double left, double right) 
{
	return left + right;
}
long Add(long left, long right) 
{
	return left + right;
}

void f(int a, int b = 10)
{}

void f(int a)
{}

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.1, 20.2) << endl;
	cout << Add(10L, 20L) << endl;
	//f(1);
	f(1, 2);
	return 0;
}