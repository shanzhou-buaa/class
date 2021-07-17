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

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << endl;
//
//	c = 2;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	//int& ra;
//	
//	int& b = a;
//	int& c = a;
//
//	int d = 2;
//	c = d;
//	
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常量
//	const int& ra = a;
//	// int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;
//
//	int c = 10;
//	double d = 3.14;
//	d = c;
//
//	return 0;
//}
//
//void Swap(int& x, int& y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << a << " " << b << endl;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

//inline int Add(int a, int b) 
//{
//	int c = a + b;
//
//	return c;
//}
//int main()
//{
//	int ret = Add(1, 2);
//	return 0;
//}

//传引用返回
//int& Add(int a, int b) 
//{
//	static int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(3, 4) = " << ret << endl;
//	return 0;
//}

//double test()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = test();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	auto a = 1, b = 2;
//	//auto c = 10, d = 6.5;
//
//	return 0;
//}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl << endl;
	for (auto ee : arr)
	{
		ee *= 2;
		cout << ee << " ";
	}
	cout << endl;
	return 0;
}