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
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

class A
{
public:
	A(int x)
	{
		_x = x;
	}
private:
	int _x;
};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _n(10)
//		, _ref(_year)
//		, _a(1)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _n;
//	int& _ref;
//	A _a;
//};

//int main()
//{
//	const int n;//相当于不在初始化列表初始化
//	n = 10;//然后在构造函数体内赋值
//
//	int& r;
//	r = n;
//
//	A a;
//	a(10);
//	return 0;
//}

//class A
//{
//private:
//	int a = 20;
//	int* p = (int*)malloc(sizeof(int)* 4);
//	double pi = 3.14;
//	static int _n;
//};
//
//int A::_n = 0;

class A
{
public:
	class B
	{
	public:
		void f1(const A& a)
		{
			cout << a._a << endl;
			cout << _b << endl;
		}
	private:
		int _b;
	};

	void f2(const B& b)
	{
		cout << b._b << endl;
		cout << _a << endl;
	}

private:
	int _a;
};

int main()
{

	return 0;
}