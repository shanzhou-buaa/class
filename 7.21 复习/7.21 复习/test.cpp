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
//	const int n;//�൱�ڲ��ڳ�ʼ���б��ʼ��
//	n = 10;//Ȼ���ڹ��캯�����ڸ�ֵ
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