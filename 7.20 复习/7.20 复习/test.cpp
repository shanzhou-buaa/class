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

class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int)* capacity);
		_size = 0;
		_capacity = capacity;
	}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_size = 0;
		_capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};

class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	~Date()
	{}

	bool Equal(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
		}

		return false;
	}

	bool operator>(const Date& d)
	{
		return !(*this == d) && !(*this < d);
	}

	void operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void print() const
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void f1(const Date d)
{
	cout << "传值" << endl;
}

void f2(const Date& d)
{
	cout << "传引用" << endl;
}


int main()
{
	Date d1(2021, 7, 9);
	Date d2;
	d2 = d1;

	//f1(d1);
	//f2(d1);

	//Stack st1;
	//Stack st2(st1);

	d1.Equal(d2);
 	return 0;
}