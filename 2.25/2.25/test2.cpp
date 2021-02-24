#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//C++默认的成员函数
//1.构造函数
//(1)在对象构造时自动调用，完成初始化
//(2)无返回值，注意不是void，是啥也不写
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
//	//函数重载，声明对象时不初始化
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
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
//	//调用构造函数时写法特别
//	//在对象后面写参数，而不是在函数名后面写
//	Date d1(2021,2,23);
//	d1.Print();
//	d1.Init(2021,2,24);
//	d1.Print();
//
//
//	Date d2;//d2后面千万不能加()
//	d2.Print();
//	return 0;
//}

//3.如果类中没有显式定义函数
//则编译器自动生成一个无参的默认构造函数

//class Date
//{
//public:
//	//一旦有显式构造函数，就不再生成
//	//没有显式定义函数，这里编译器自动生成无参的默认构造函数
//	//对内置类型（int，char...）的成员变量不做处理
//	//对自定义的成员变量，调用它们的构造函数初始化
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
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
//	//调用编译器生成的构造函数
//	Date d1;
//	d1.Print();
//	return 0;
//}



//默认构造函数
//1.自己实现的无参构造函数
//2.自己实现的全缺省函数
//3.编译器自动生成的
//class Date
//{
//public:
//	//用全缺省很方便
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	Date d2(2021);
//	d2.Print();
//
//	Date d3(2021,2);
//	d3.Print();
//	
//	Date d4(2021,2,24);
//	d4.Print();
//
//	return 0;
//}

//析构函数
//在对象的生命周期到了以后，自动调用
//完成清理工作（清理对象里的资源），但不是销毁变量
//比如free调未free的malloc
//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
//	}
//
//	~Date()//在类的名字前加个~
//	{
//		cout << "~Date()" << endl;
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
//	Date d1;
//	d1.Print();
//
//	Date d2(2021);
//	d2.Print();
//
//	Date d3(2021, 2);
//	d3.Print();
//
//	Date d4(2021, 2, 24);
//	d4.Print();
//
//	return 0;
//}


class stack
{
public:
	stack(int n = 0)
	{
		_a = (int*)malloc(sizeof(int)* n);
	}
	~stack()
	{
		if (_a != nullptr)
		{
			free(_a);
			_a = nullptr;
			_size = 0;
			_capacity = 0;
			cout << "~stack()" << endl;
		}
	}
private:
	int* _a;
	int _size;
	int _capacity;
};


int main()
{
	stack s1;
	stack s2;
	//先创建s1，在创建s2
	//先析构s2，在析构s1
	//先进后出
	
	return 0;
}