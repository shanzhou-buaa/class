#include <iostream>
using namespace std;

//引用在定义的时候必须初始化
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int x = 20;
//	//不是让b变成x的引用，而是把x赋值给b
//	b = x;
//	return 0;
//}

//int main()
//{
//	//权限相同
//	const int a = 10;//只读的常量
//	const int& b = a;//只读的常量引用
//
//	//权限缩小
//	int c = 10;//可读可写
//	const int& d = c;//只读
//
//	//权限放大
//	//const int e = 10;
//	//int& f = e;
//	return 0;
//}

//做参数
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//作返回值
//int& Add(int x, int y)
//{
//	static int c = x + y;
//	return c;
//}

//int main()
//{
//	int& ret = Add(1, 2);
//	cout << Add(5, 7) << endl;
//	printf("%d\n", ret);
//	return 0;
//}

//C语言为了避免小函数建立栈帧，提供宏函数支持，在预处理阶段就展开
//宏的缺点
//1.不支持调试 2.语法复杂，容易出错 3.没有类型的检查

#define ADD(x, y) ((x) + (y))

//c++推荐频繁调用的小函数定义成inline，这个函数会在调用的地方展开，没有栈帧的开销
//内联有缺陷
//指令越多可执行程序占用的内存越大
//内联不建议声明和定义分离
inline int Add(int x, int y)
{
	return x + y;
}

//int main()
//{
//	int a = 10;
//	auto b = a;//auto自动推导b的类型
//
//	return 0;
//}

//范围for c++11的新语法，更简单，是数组就可以
//自动遍历，依次去除数组中的元素赋值给x直到遍历结束

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	for (auto x : a)
//		printf("%d ", x);
//
//	for (auto& x : a)
//		x *= 2;
//	for (auto x : a)
//		printf("%d ", x);
//	printf("\n");
//	return 0;
//}
//
//int main()
//{
//	int* a = nullptr;
//	return 0;
//}

//类：定义一个新的类型
//两部分
//1.成员变量 2.成员函数
//class不加访问限定符，默认全是私有的
//struct不加访问限定符，默认全是私有的

//class Stack
//{
//public:
//	void Init(int InitCapacity = 4);
//	void Push(int x)
//	{
//		a[size++] = x;
//	}
//	void Print()
//	{
//		for (int i = 0; i < size; i++)
//			printf("%d ", a[i]);
//		printf("\n");
//	}
//private://这里只是声明
//	int* a;
//	int size;
//	int capacity;
//};
//
//void Stack::Init(int InitCapacity)
//{
//	a = (int*)malloc(sizeof(int)* InitCapacity);
//	size = 0;
//	capacity = InitCapacity;
//}
//
//int main()
//{
//	Stack st;//成员变量定义的地方
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Print();
//	printf("%d\n", sizeof(Stack));
//	return 0;
//}

//空类(没有成员变量)的大小是1
//给1个字节不是为了存储数据，而是为了占位置，表示这个对象存在
class c1
{
	void f()
	{}
};

class c2
{};

int main()
{	
	printf("%d\n", sizeof(c1));
	printf("%d\n", sizeof(c2));
    return 0;
}
