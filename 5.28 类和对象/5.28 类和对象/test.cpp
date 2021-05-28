#include <iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造函数
//	//拷贝构造是构造函数的一个重载形式
//	//拷贝构造函数的参数只有一个且必须使用引用传参，用传值传参会引发无穷递归调用
//	//也是默认成员函数，这个函数会完成内置类型的浅拷贝/值拷贝
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//Date这样的类浅拷贝即可，默认生成的拷贝构造就够用
//	//但是像Stack这样的类，需要的是深拷贝，需要自己写拷贝构造
//	//1.自动调用析构函数时，这块空间被free两次
//	//2.其中一个对象插入删除数据，都会导致另一个对象也插入删除数据
//
//	//和函数重载没关系
//	//函数重载是支持定义同名函数
//	//赋值运算符重载是为了让自定义类型可以像内置类型一样使用运算符
//	//.* :: sizeof ?: . 这五个运算符不能重载
//	//d1 < d2 -->>d1.operator<(&d1, d2);
//	//bool operator<(const Date& d2); -->>bool operator<(Date* this, const Date& d2);
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&&_day == d2._day;
//	}
//
//	//赋值运算符重载也是一个默认成员函数
//	//编译器生成的赋值运算符重载和拷贝构造的特性一致
//	//1.针对内置类型，浅拷贝
//	//2.针对自定义类型，调用其赋值运算符重载拷贝
//	Date& operator=(const Date& d)
//	{
//		//不是自己给自己赋值
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//	~Date()
//	{
//		//资源的清理，这里的析构函数无意义
//	}
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
//	}
//private:
//	//成员变量，命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//};
//
////函数传的参数时自定义类型，推荐引用传参
////若传值传参，会调用拷贝构造
//
//int main()
//{
//	Date d1(2021, 5, 26);
//	Date d2(1970, 1, 1);
//
//	Date d3(d1);//拷贝构造，让d3和d1一样
//	Date d4 = d1;//这里是拷贝，不是赋值
//	Date d5;
//
//	d3.Print();
//	d4.Print();
//
//	//也是拷贝行为
//	//拷贝构造：创建一个对象时，用同类对象来初始化
//	//赋值：两个对象都已经存在且被初始化过想，现在用把d4的值赋给d5
//	d5 = d1 = d2;
//
//	d5.Print();
//	d1.Print();
//	d2.Print();
//
//	Date d6(d1);//拷贝构造
//	d1 = d2;//赋值重载
//	Date d6 = d1;//拷贝构造
//	return 0;
//}
//
////构造、析构相似，编译器对内置类型不处理，自定义类型会调用它的构造和析构
////拷贝构造和赋值重载类似，内置类型浅拷贝，自定义类型会调用它的拷贝构造和赋值重载