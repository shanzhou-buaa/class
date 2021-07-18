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


//类 ——》定义出一个新的类型
//1.成员变量
//2.成员函数
//C++中的struct兼容C的所有用法，同时C++中把struct升级为类

//struct student
//{
//	void Init(const char* name = "张三", const char* id = "0000", const int age = 18)
//	{
//		strcpy(_name, name);
//		strcpy(_id, id);
//		_age = age;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _id << endl;
//		cout << _age << endl;
//		cout << endl;
//	}
//
//	char _name[10];
//	char _id[10];
//	int _age;
//};
//
//int main()
//{
//	struct student s1;
//	s1.Init("李四", "1234", 20);
//	s1.Print();
//
//	student s2;
//	s2.Init();
//	s2.Print();
//
//	return 0;
//}

//class student
//{
//public:
//	void Init(const char* name = "张三", const char* id = "0000", const int age = 18);
//	void Print();
//
//private:
//	char _name[10];
//	char _id[10];
//	int _age;
//};
//
//void student::Init(const char* name, const char* id, const int age)
//{
//	strcpy(_name, name);
//	strcpy(_id, id);
//	_age = age;
//}
//
//void student::Print()
//{
//	cout << _name << endl;
//	cout << _id << endl;
//	cout << _age << endl;
//	cout << endl;
//}
//
//int main()
//{
//	class student s1;
//	s1.Init("李四", "1234", 20);
//	s1.Print();
//
//	student s2;
//	s2.Init();
//	s2.Print();
//
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//
//
//	return 0;
//}

// 类中既有成员变量，又有成员函数
class c1 {
public:
	void f()
	{}
private:
	int _a;
};

// 类中仅有成员函数
class c2 {
public:
	void f() 
	{}
};
// 类中什么都没有---空类
class A3
{

};