#include <iostream>
#include <string>
using namespace std;
//
//class Time
//{
//	//任意位置都可以
//	//Date要访问Time，Date是Time的友元
//	//单向的，Time不能访问Date
//	friend class Date;
//
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//	{
//		_hour = hour;
//		_minute = minute;
//		_second = second;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class A
//{
//public:
//	A(int x)
//	{
//		_x = x;
//	}
//private:
//	int _x;
//};
//
////类中包含以下成员，必须在初始化列表初始化
////1.引用 2.const 3.自定义类型（且该类无默认构造函数）
//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//
//public:
//	//建议尽量使用初始化列表初始化
//	//初始化列表初始化
//	//可以混着用
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _n(1)
//		, ref(year)
//		, _a(1)
//	{
//		_day = day;
//		_t._hour = 1;
//		//_n = 10;//err
//		//_ref = year;//err
//		//_a(1 );
//	}
//
//	bool operator==(const Date& d) const
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//
//	//必须在定义的时候初始化 
//	const int _n;
//	int& ref;//成员变量的声明，不是定义
//	A _a;
//};
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//
//	return in;
//}
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//
//	return out;
//}
//
//int main()
//{
//	Date d1(1970, 1, 1);
//	Date d2(2021, 5, 30);
//	cin >> d2 >> d1;
//	cout << d2 << d1;
//	return 0;
//}
//
//
//成员变量在类中的声明次序就是在初始化列表中的初始化顺序
//与其在初始化列表中的先后次序无关
//class A
//{
//public:
//	//_a2先定义
//	A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//	void Print()
//	{
//		printf("%d %d\n", _a1, _a2);
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();
//
//	return 0;
//}
//
//class A
//{
//public:
//	//explicit A(int a)
//	A(int a)
//	{
//		_a = a;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//加上explicit就不能写了
//	A a1 = 3;//对于单参数的类，支持隐式类型转换
//	return 0;
//}
//
//int main()
//{
//	A a1(1);//标准的构造函数调用
//	A a2 = 2;//隐式类型转换，编译器优化后也是直接构造
//	A(3);//构造匿名对象，生命周期只在这一行
//}

//静态成员函数没有this指针，不能访问非静态成员
//静态成员
class A
{
public:
	A(int a = 10)
	{
		_n++;
		_a = a;
	}
	A(const A& a)
	{
		_n++;
		_a = a._a;
	}
	static int GetN()
	{
		return _n;
	}
private:
	//n存储在静态区，属于整个类
	static int _n;//声明，不在构造函数初始化
	int _a;
};

//如计算程序中定义了多少个类型为A的变量
int A::_n = 0;//静态成员变量的定义初始化

int main()
{
	//cout << sizeof(A) << endl;
	A a1;
	A a2;
	A a3 = 2;
	//public才能这么访问
	//cout << A::_n << endl;
	//cout << a1._n << endl;
	cout << A::GetN() << endl;
	return 0;
}