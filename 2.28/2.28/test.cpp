#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
 
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
//	void print() const//void print(const Date* this);
//	{
//		//_year = 30;报错，指向的内容不能改变
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//	//void print()//void print(Date* this);
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;  
//	//}
//
//	//const Date* p1 -->>*p1指向的内容
//	//Date* const p2 -->>*p2指向的内容
//	//Date* const p3 -->>p3指针本身
//	//const在*之前，指向的内容是const
//	//const在*之后，指针指向的地址是const
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
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
//	void print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//下面两个取地址函数，自己不写，编译器也会自动生成
//	//编译器生成的就足够了
//	Date* operator&()
//	{
//		cout << "Date* operator&()" << endl;
//
//		return this;
//	}
//
//	const Date* operator&() const
//	{
//		cout << "const Date* operator&() const" << endl;
//
//		return this;
//	}
//
//	//可，可读可写-》只读，权限缩小
//	/*void f1()
//	{
//		f2();
//	}
//
//	void f2() const
//	{}*/
//
//	//不可，只读-》可读可写，权限变大
//	/*void f3()
//	{}
//
//	void f4() const
//	{
//		f3();
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 2, 28);
//	Date d2;
//	const Date d3;
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	cout << &d3 << endl;
//
//
//	return 0;
//}


//class Date
//{
//public:
//	//函数体内赋值
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//初始化列表
//	//固定格式，以：开始，中间用逗号分割
//	//必须用(),不能用=
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//最后还有{}
//
//	void print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 2, 28);
//	d1.print();
//	return 0 ;
//}


//class A
//{
//public :
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//
//class B
//{
//public:
//public:
//	//对象的成员变量的定义
//	//初始化的顺序和private中声明顺序相同
//	B(int a, int ref)
//		:_aobj(1)
//		, _ref(ref)
//		, _n(10)
//		//先初始化_n，再_aobj，最后_ref
//	{}
//private:
//	//以下三种成员必须在初始化列表初始化
//	const int _n;//const
//	A _aobj;//没有默认构造函数
//	//默认构造函数不用传参
//	int& _ref;//引用
//	//对象的成员变量的声明
//};
//
//int main()
//{
//	B b(1, 2);//对象的定义
//	return 0;
//}


//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//};
//
//
//int main()
//{
//	Date d1(1);//直接构造
//
//	//变成	explicit Date(int year)后，下面一行不合法	
//	//Date d2 = 2;//先构造tmp(2), 再Date(tmp)(即拷贝构造)
//	//实际过程如上，但最后优化为像d1一样的直接构造
//	
//	Date d3 = d1;//拷贝构造
//	return 0;
//}

