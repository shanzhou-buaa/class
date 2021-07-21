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

//class Date
//{
//public:
//	void Init(int year = 1970, int month = 1, int day = 1) 
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;//Äê
//	int _month;//ÔÂ
//	int _day;//ÈÕ
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1.Init(2021, 7, 8);
//	d2.Init();
//	d1.Print();
//	d2.Print();
//	return 0;
//}


//class A
//{
//public:
//	void Print1()
//	{
//		cout << _a << endl;
//	}
//
//	void Print2()
//	{
//		cout << "Print2()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a;
//	a.Print1();
//	a.Print2();
//	return 0;
//}

class A
{
public:
	A(int a = 0)
	{
		_aa = a;
	}

	void printA()
	{
		cout << "printA()" << endl;
		cout << _aa << endl;
	}
private:
	int _aa;
};

class Date
{
public:
	Date(int year)
	{}
	void print()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	/*Date d1;
	d1.print();*/
	return 0;
}