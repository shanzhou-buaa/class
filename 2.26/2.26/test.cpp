#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//析构函数
//1.函数名是类名前加上~
//2.无参数，无返回值
//3.一个类有且仅有一个析构函数，且系统会自动生成默认的析构函数
//4.对象生命周期结束时，C++编译系统自动调用析构函数


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////自定义类型不能用运算符比较大小
////要比较就要用运算符重载函数实现
////运算符有几个操作数，operator函数就有几个参数
//bool operator == (const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//
//int main()
//{
//	Date d1(2021, 2, 26);
//	Date d2 = d1;
//	Date d3(d1);
//	//拷贝构造，必须用引用，不然会无穷递归
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	//d1 == d2 和 operator==(d1, d2)一样，但前者简洁且可读性强
//	int x = (d1 == d2) ? 1 : 0;//编译器自动转换成下一行的样子
//	int y = (operator==(d1, d2)) ? 1 : 0;
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//下面有private就得这样写
//	//d前面隐含this指针
//	bool operator==(const Date& d)//bool operator==(Date* this, const Date& d)
//	{
//		//前面隐含this->_month,this->_day
//		return this->_year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	bool operator>(const Date&d)
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else if (_year == d._year && _month == d._month&&_day > d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2021, 2, 26);
//	Date d2 = d1;
//	Date d3(2021,2,28);
//	//拷贝构造，必须用引用，不然会无穷递归
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	//d1 == d2 和 operator==(d1, d2)一样，但前者简洁且可读性强
//	//int x = (d1 == d2) ? 1 : 0;//编译器自动转换成下一行的样子
//	//int y = (d1.operator==(d2)) ? 1 : 0;
//	//cout << "x = " << x << endl;
//	//cout << "y = " << y << endl; 
//	
//
//	int z = (d1 > d3) ? 1 : 0;
//	cout << "z = " << z << endl;
//
//	return 0;
//}


class stack
{
public:
	stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)* n);
		_size = 0;
		_capacity = n;
	}

	~stack()
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


int main()
{
	stack s1;
	stack s2(s1);
	//崩溃，s1、s2指向同一块空间
	//同一块空间连续free两次

	stack s3(30);
	//st1 = st3;
	return 0;
}