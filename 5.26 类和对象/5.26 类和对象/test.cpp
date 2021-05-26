#include <iostream>
using namespace std;

//class Date
//{
//public: 
//	//编译器会增加一个隐含的参数-》void Init(Date* this, int year = 1970, int month = 1, int day = 1)
//	//隐含的，不能写出来，但是可以直接使用
//	void Init(int year = 1970, int month = 1, int day = 1)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//		printf("this:%p\n", this);
//	}
//private:
//	//成员变量，命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//调用的init是同一个函数
//	Date d1;
//	d1.Init(2021, 5, 24);//d1.Init(&d1, 2021, 5, 24);
//	printf("d1:%p\n", &d1);
//
//	Date d2;
//	d2.Init(2021, 5, 25);
//	printf("d2:%p\n", &d2);
//
//	return 0;
//}

//class Date
//{
//public:
//	//类里面什么函数都不写的时候，编译器会自动生成6个函数，默认成员函数
//	//1.构造函数：完成对象的初始化，对象实例化时自动调用
//	//自己构造的Init可能会忘记调用，C++为了解决这个问题，引入构造函数
//	Date(int year = 1970, int month = 1, int day = 1)//无返回值
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date()//重载，不传参时调用这个
//	//{
//	//	_year = 1970;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//private:
//	//成员变量，命名风格区分一下
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
//	//不写构造函数,编译器会自动生成一个构造函数
//	//原生类型不初始化，自定义类型会调用他们的默认构造函数来初始化
//	void Print()
//	{
//		printf("%d-%d-%d", _year, _month, _day);
//	}
//private:
//	//成员变量，命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}

//默认构造函数，有且仅有一个
//1.不写，编译器默认生成
//2.自己写的无参的
//3.自己写的全缺省的
//就是不用传参就可以调用的构造函数
//class Date
//{
//public:
//
//private:
//	//成员变量，命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	
//	return 0;
//}


//析构函数不是完成对象的销毁，对象的销毁是由编译器完成的
//对象在销毁是会自动调用析构函数完成类的资源清理工作
//函数名：在类名前加~
//无参数，无返回值
//一个类有且仅有一个析构函数，若未显式定义在，则系统自动生成
//对象生命周期结束时，C++编译系统自动调用析构函数
//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()
//	{
//		//资源的清理，这里的析构函数无意义
//		printf("~Date\n");
//	}
//private:
//	//成员变量，命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity =  4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		//清理资源，自动调用
//		free(_a);
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//		printf("~Stack\n");
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	//s1先析构，main函数调用栈帧，栈帧中对象的构造和析构也要后进先出
//	Date d1;
//	Stack s1;
//	return 0;
//}