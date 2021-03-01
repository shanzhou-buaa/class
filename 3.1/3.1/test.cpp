#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//静态函数无法访问任何非静态成员变量或成员函数
//因为静态函数中不含有this指针


//class Date
//{
//public:
//	/*Date(int year)
//		:_year(year)
//	{}*/
//
//	void print()
//	{
//		cout << _year << "-" << _month << '-' << _day << endl;
//	}
//private:
//	//C++11支持在声明时给缺省值
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};

//int main()
//{ 
//	/*Date d1(2021);
//	d1.print();*/
//
//	Date d2;
//	d2.print();
//
//	return 0;
//}



//友元函数可访问类的私有和保护成员，但不是类的成员函数
//友元函数不能用const修饰
//友元函数可以在类的任何地方声明，不受访问限定符限制
//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*void print()
//	{
//		cout << _year << "-" << _month << '-' << _day << endl;
//	}*/
//	
//	/*void operator<<(ostream& out)
//	{
//		out << _year << '/' << _month << "/" << _day << endl;
//	}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////void operator<<(ostream&out, const Date& d)
////{
////	out << d._year << "/" << d._month << "/" << d._day << endl;
////}
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "/" << d._month << "/" << d._day << endl;
//	return out;
//}
//
////cout 是 ostream类型
////cin 是 istream类型
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	
//	return in;
//}
//
//int main()
//{
//	int i = 0;
//	Date d1(2021, 3, 1);
//	Date d2(2021, 3, 2);
//	//d.operator<<(cout);
//	//d << cout;//按照operator应该这样写，但可读性很差
//
//	//cout << d;//用友元函数在类外面访问private内的成员变量
//	//cout << d1 << d2 << i << endl;
//	
//	Date d3;
//	Date d4;
//	cin >> d3 >> d4;
//	cout << d3;
//	cout << d4;
//
//	return 0;
//}


//class A
//{
//private:
//	//...
//
//public:
//	//...
//	class B
//	{
//	public:
//		//...
//	private:
//		//...
//	};
//};
//B天生就是A的友元
//访问B时要A::B