#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//封装
//1.将数据和方法定义在一起
//2.把想给你看的给你看，不想给你看的封装起来(用访问限定符private,public实现)
//class Stack
//{
//public:
//	//1.成员函数
//	void Push(int x)
//	{
//		;//第一种定义方法
//	}
//	void Pop();
//	bool Empty();
//	//2.成员变量
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//
//};
////第二种定义方法
//void Stack::Pop()
//{
//	;
//}
//
////C++中struct也可当做类
//struct ListNode_CPP
//{
//	int val;
//	ListNode_CPP* prev;
//	struct ListNode_CPP* next;
//	//C++中两种写法都可
//};
//
////C++中class默认私有，struct默认公有
//
//class A1
//{};
//
//class A2
//{
//	void f();
//};
//int main()
//{
//	//只计算成员变量的大小
//	//不加函数
//	cout << sizeof(Stack) << endl;//12
//	//一个类实例化出若干个对象，每个对象都可存储不同的值
//	//但调用的成员函数相同
//	//如果每个对象都放成员函数
//	//就很浪费空间，所以放在这些对象以外公共的空间
//
//
//	//没有成员变量的类的大小是1
//	cout << sizeof(A1) << endl;//1
//	cout << sizeof(A2) << endl;//1
//	//大小是1，不是为了存数据
//	//而是为了占个位置，取地址时它有唯一的地址与其他变量区分
//
//	return 0;
//}


class date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << '-' << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	date d1;
	d1.Init(2021, 2, 24);
	d1.Print();

	date d2;
	d2.Init(2021, 2, 22);
	d2.Print();
	return 0;
}