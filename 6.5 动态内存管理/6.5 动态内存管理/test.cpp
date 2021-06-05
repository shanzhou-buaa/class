#include <iostream>
using namespace std;

////C++11
//class B
//{
//public:
//	B(int x = 1)
//		:_x(x)
//	{
//		cout << "B()" << endl;
//	}
//public:
//	int _x;
//};
//
//class A
//{
//public:
//
//private:
//	//内置类型也可以在自动生成的默认构造函数里被初始化
//	int _a = 0;//缺省值
//	int* _p = nullptr;
//	int* arr = (int*)malloc(sizeof(int)* 4);
//	B _b = 20;
//};
//
//int main()
//{
//	A aa;
//	return 0;
//}

//typedef struct StackC
//{
//	int* a;
//	int size;
//	int capacity;
//}sc;
//
////栈向下生长，堆向上生长
//void f2()
//{
//	int b = 0;
//	cout << "b:"<<&b << endl;
//}
//
//void f1()
//{
//	int a = 0;
//	cout << "a:"<<&a << endl;
//	f2();
//}
//int main()
//{
//	//f1();
//	//一般情况下后申请的比先申请的大，但也不一定
//	int* c = (int*)malloc(4);
//	int* d = (int*)malloc(4);
//	cout << "c:" << &c << endl;
//	cout << "d:" << &d << endl;
//
//	return 0;
//}

//const定义的变量不在常量区，叫常变量
//CCCAA AAADAB
//40 5 4 4 4 4


//malloc堆上开空间
//calloc堆上开空间+初始化成0
//realloc针对已有的空间扩容（原地/异地）
//new/delete和malloc/free针对**内置类型**没有差别
//new/delete new[]/delete[]
//int main()
//{
//	int* c1 = (int*)malloc(sizeof(int)* 10);
//	int* c2 = (int*)malloc(sizeof(int));
//	int* cpp1 = new int[10]
//	int* cpp2 = new int;
//
//	free(c1);
//	free(c2);
//	delete[] cpp1;
//	delete cpp2;
//
// 	return 0;
//}

typedef class ListNode
{
public:
	ListNode(int val = 0)
		:_val(val)
		, prev(nullptr)
		, next(nullptr)
	{}
private:
	int _val;
	ListNode* prev;
	ListNode* next;
}ln;

int main()
{
	ln* p1 = new ln;//new针对自定义类型，开空间+初始化
	ln* p2 = new ln(10);
	ln* arr = new ln[10]{1, 2, 3};//C++11
	delete p1;//delete针对自定义类型，析构+释放空间
	delete p2;
	delete[] arr;

	int* a = new int[4]{1, 2, 3, 4};
	return 0;
}
//申请4G的动态内存，用x64